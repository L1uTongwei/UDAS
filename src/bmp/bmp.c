#include "../bmp/bmp.h" 
#include "../asm_optimize.h"

/*
	2023-01-21 图像处理
	bmp_init 初始化图片-使用前请初始化
	bmp_free 释放空间-使用后请释放
	read 从数组中读取图片
	write 输出图片至数组
	cfread 读取图片指定行信息
	draw 绘制指定图片

	注意：  局部变量使用后必须释放
			允许多线程同时读取一个图片，严谨多线程同时修改一个图片，建议修改局部变量
*/
const long image_bmp_maxhw = 4096;//如需修改此处，请计算文件大小是否会超过bmp格式最大限制
const long image_bmp_maxsize = 26214400;
const long image_bmp_8bit = 51;//8bit绘图每位亮度 
const long image_bmp_highcut = 1;//高切不透明
const long image_bmp_highcutdh = 2;//高切透明
const long image_bmp_lowcut = -1;//低切不透明
const long image_bmp_lowcutdh = -2;//低切透明

/*
	2023-01-21 初始化图片
	int h图像高
	int w图像宽
	int mode每像素大小
	
	2023-01-22 修复空间开辟的bug
	2023-02-23 内存中强制24bit
*/
short image_bmp_init(struct image_bmp* data,long h, long w, long mode) {
	if(data==NULL) return 0;
	if (h<0 || w<0 || h>image_bmp_maxhw || w>image_bmp_maxhw) return 0;
	if (mode != 4 && mode != 8 && mode != 24) return 0;
	
	data->widthsize = w * mode / 32;//必须为4字节的倍数
	if (w*mode % 32 != 0) data->widthsize++;
	data->data = NULL;
	data->data = (unsigned long*)malloc(sizeof(unsigned long)*w*h);
	if (data->data == NULL) return 0;
	memset(data->data, 0, sizeof(unsigned long)*w*h);
	
	data->height = h;
	data->width = w;
	data->bit = mode;
	return 1;
}
/*
	2023-01-21 释放空间
*/
void image_bmp_free(struct image_bmp* data) {
	if(data==NULL) return;
	if (data->data != NULL) free(data->data);
	data->data = NULL;
	return;
}
/*
	2023-01-21 数组中读取图片
	char* dat 待解析数据
	long datlen 待解析数据长度
	返回值：
		1： 解析成功
		-1： 输入错误
		-2： 文件过大
		-3： 图片头错误
		-4： 初始化错误
	
	2023-02-23 内存中强制24bit
*/
long image_bmp_read(struct image_bmp* data, unsigned char* dat, long datlen) {
	if (data==NULL) return 0;
	if (dat == NULL) return -1;
	if (datlen < 54) return -1;

	//解析文件头 
	image_bmp_free(data);
	unsigned long filesize = 0;
	int i = 0; 
	for (i = 5; i >= 2; i--) {
		filesize *= 256;
		filesize += (*(dat + i));
	}
	if (filesize > image_bmp_maxsize) return -2;
	if (datlen < filesize) return -2;

	unsigned long head = 0;
	for (i = 13; i >= 10; i--) {
		head *= 256;
		head += (*(dat + i));
	}
	if (head > image_bmp_maxsize || head > filesize) return -3;

	//解析数据头 
	unsigned long Bhead = 0;
	for (i = 17; i >= 14; i--) {
		Bhead *= 256;
		Bhead += (*(dat + i));
	}
	if (Bhead != 40) return -3;

	unsigned long h = 0, w = 0, mode = 0;
	for (i = 21; i >= 18; i--) {
		w *= 256;
		w += (*(dat + i));
	}
	for (i = 25; i >= 22; i--) {
		h *= 256;
		h += (*(dat + i));
	}
	for (i = 29; i >= 28; i--) {
		mode *= 256;
		mode += (*(dat + i));
	}
	data->widthsize = w * mode / 32;//必须为4字节的倍数 
	if (w*mode % 32 != 0) data->widthsize++;
	if (data->widthsize * 4 * h != filesize - head) return -4;
	if (image_bmp_init(data, h, w, mode) == 0) return -4;

	//解析色彩数据
	unsigned long* color_data = NULL;
	if (mode == 4 || mode == 8) {
		long color_num = 1 << mode;
		color_data = (unsigned long*)malloc(sizeof(unsigned long)*color_num);
		if (color_data == NULL) return -4;
		memset(color_data, 0, sizeof(unsigned long)*color_num);
		for (i = 0; i < color_num; i++) {
			int j = 0;
			for (j = 0; j < 3; j++) {
				*(color_data + i) = (*(color_data + i)) << 8;
				*(color_data + i) += *(dat + 54 + i * 4 + j);
			}
		}
	}

	//解析数据
	for (i = 0; i < data->height; i++) {
		unsigned long wsiz = (data->height - i - 1) * data->widthsize;
		unsigned long wbit = wsiz * 4 + head;
		int j = 0;
		for (j = 0; j < data->width; j++) {
			*(data->data + i * data->width + j) = 0;
			if (data->bit == 4) {
				unsigned char read_temp_data = (*(dat + wbit + j / 2));
				//舍弃低位信息 
				if ((j & 1) == 0) {
					read_temp_data = read_temp_data >> 4;
				}
				//舍弃高位信息 
				else {
					read_temp_data = read_temp_data << 4;
					read_temp_data = read_temp_data >> 4;
				}
				*(data->data + i * data->width + j) = *(color_data + read_temp_data);
			}
			else if (data->bit == 8) {
				unsigned char read_temp_data = (*(dat + wbit + j));
				*(data->data + i * data->width + j) = *(color_data + read_temp_data);
			}
			else if (data->bit == 24) {
				int k = 0;
				for (k = 0; k < 3; k++) {
					*(data->data + i * data->width + j) = (*(data->data + i * data->width + j)) << 8;
					*(data->data + i * data->width + j) += (*(dat + wbit + j * 3 + k));
				}
			}
		}
	}
	if (color_data != NULL) free(color_data);
	color_data = NULL;
	return 1;
}
/*
	2023-01-21 输出图片至数组
	char* dat 保存用数组
	long datlen 保存用数组最大长度
	返回值：
		正整数： 输出成功，文件大小
		-1： 输入错误
		-2： 空间过小
	注意：如果输出非24位图片，该函数会抛弃颜色信息，并采用默认值

	更新：
		2023-01-22 修复了24bit的颜色数问题，现在不会报超空间了
		2023-01-23 修复了输出时会使图像信息变空的bug
		2023-02-23 兼容在内存中强制为24位的更新，增加8bit输出
*/
long image_bmp_write(struct image_bmp* data, unsigned char* dat, long datlen) {
	if (dat == NULL || datlen < 54) return -1;

	memset(dat, 0, datlen);
	//计算文件头 
	unsigned long filesize = 54;
	unsigned long colornum = 1 << data->bit;
	if (data->bit == 24) colornum = 0;
	unsigned long head = 54 + colornum * 4;
	filesize += data->widthsize * 4 * data->height;
	filesize += colornum * 4;
	if (filesize > datlen) return -2;
	//输出文件头
	*(dat + 0) = 0x42; *(dat + 1) = 0x4d;
	unsigned long tfilesize = filesize, thead = head;
	int i = 0,j = 0;
	for (i = 2; i <= 5; i++) {
		*(dat + i) = tfilesize % 256;
		tfilesize /= 256;
	}
	for (i = 10; i <= 13; i++) {
		*(dat + i) = thead % 256;
		thead /= 256;
	}

	//输出数据头 
	*(dat + 14) = 40;
	unsigned long tw = data->width, th = data->height, tbit = data->bit, imagesize = filesize - head;
	for (i = 18; i <= 21; i++) {
		*(dat + i) = tw % 256;
		tw /= 256;
	}
	for (i = 22; i <= 25; i++) {
		*(dat + i) = th % 256;
		th /= 256;
	}
	*(dat + 26) = 1;
	for (i = 28; i <= 29; i++) {
		*(dat + i) = tbit % 256;
		tbit /= 256;
	}
	for (i = 34; i <= 37; i++) {
		*(dat + i) = imagesize % 256;
		imagesize /= 256;
	}

	//输出色彩信息
	if (data->bit != 24) {
		if (data->bit == 4) {
			for (i = 0; i < 16; i++) {
				for (j = 0; j < 3; j++) {
					//*(dat+54 + i*4+2+j)
					if (i < 8) *(dat + 56 + (i << 2) - j) = ((i >> j) & 1) << 7;
					if (i > 8) *(dat + 56 + (i << 2) - j) = ((i >> j) & 1) * 255;
				}
			}
			*(dat + 88) = 192;//dat + 56 + 8 * 4
			*(dat + 87) = 192;//dat + 55 + 8 * 4
			*(dat + 86) = 192;//dat + 54 + 8 * 4
		}
		else if (data->bit == 8) {
			int b = 0,g = 0,r = 0;
			for (b = 0; b < 6; b++) {
				for (g = 0; g < 6; g++) {
					for (r = 0; r < 6; r++) {
						int write_temp_rgb = (b * 36 + g * 6 + r) << 2;
						*(dat + 56 + write_temp_rgb) = r * image_bmp_8bit;
						*(dat + 55 + write_temp_rgb) = g * image_bmp_8bit;
						*(dat + 54 + write_temp_rgb) = b * image_bmp_8bit;
					}
				}
			}
		}
	}

	//输出图片
	for (i = 0; i < data->height; i++) {
		unsigned long wsiz = (data->height - i - 1) * data->widthsize;
		unsigned long wbit = wsiz * 4 + head;
		for (j = 0; j < data->width; j++) {
			unsigned long write_temp_data = (*(data->data + i * data->width + j));
			unsigned char write_temp_data_c[3];
			int k = 0;
			for (k = 0; k < 3; k++) {
				write_temp_data_c[2 - k] = write_temp_data % 256;
				write_temp_data /= 256;
			}

			if (data->bit == 4) {
				long write_temp_data_l = 0, write_temp_data_mid = 0;
				write_temp_data_mid = (write_temp_data_c[0] + write_temp_data_c[1] + write_temp_data_c[2]) / 3;
				if (write_temp_data_c[0] < 224 && write_temp_data_c[0] > 160
					&& write_temp_data_c[1] < 224 && write_temp_data_c[1] > 160
					&& write_temp_data_c[2] < 224 && write_temp_data_c[2] > 160) write_temp_data_l = 8;
				else if (write_temp_data_mid >= 128) {
					write_temp_data_l = 8 + ((write_temp_data_c[0] >> 7) << 2) + ((write_temp_data_c[1] >> 7) << 1) + (write_temp_data_c[2] >> 7);
				}
				else {
					for (k = 0; k < 3; k++) {
						if (write_temp_data_c[k] >= 64) write_temp_data_c[k] = 1;
						else write_temp_data_c[k] = 0;
					}
					write_temp_data_l = (write_temp_data_c[0] << 2) + (write_temp_data_c[1] << 1) + (write_temp_data_c[2]);
				}

				(*(dat + wbit + j / 2)) = (*(dat + wbit + j / 2)) << 4;
				(*(dat + wbit + j / 2)) += write_temp_data_l;
			}
			else if (data->bit == 8) {
				long write_temp_data_l = 0;
				for (k = 0; k < 3; k++) {
					write_temp_data_l = (write_temp_data_l << 2) + (write_temp_data_l << 1);//write_temp_data_l *= 6;
					write_temp_data_l += write_temp_data_c[k] / image_bmp_8bit;
				}
				(*(dat + wbit + j)) = write_temp_data_l;
			}
			else if (data->bit == 24) {
				for (k = 0; k < 3; k++) {
					(*(dat + wbit + j * 3 + k)) = write_temp_data_c[k];
				}
			}
		}
	}
	return filesize;
}
/*
	2023-01-21 读取图片指定行信息
	long h 读取的行（从0开始）
	long* dat 输出数组
	long datlen 输出数组最大长度

	更新：
		2023-02-23 兼容在内存中强制为24位的更新
*/
void image_bmp_cfread(struct image_bmp* data, long h, unsigned long* dat, long datlen) {
	if (h >= data->height || dat == NULL || datlen < data->width) return;
	int j = 0;
	for (j = 0; j < data->width; j++) {
		(*(dat + j)) = (*(data->data + h * data->width + j));
	}
	return;
}
/*
	2023-01-21 绘制指定图片
	long x 绘制行（从0开始）
	long y 绘制列（从0开始）
	image_bmp* bmp 绘制的图片
	返回值：
		1： 绘制成功
		-1： 输入错误
		-4： 初始化错误

	更新：
		2023-01-22 修复了绘图坐标和颜色错误的问题，修复了y为负数时绘图错误的问题
		2023-01-26 修复了4bit绘图时访问错误和绘图错误的问题
		2023-02-23 兼容在内存中强制为24位的更新
*/
long image_bmp_draw(struct image_bmp* data,long x, long y, struct image_bmp* bmp) {
	if (x >= data->height || y >= data->width || bmp == NULL) return -1;

	long bmp_h = bmp->height, bmp_w = bmp->width;
	unsigned long dat_size = sizeof(unsigned long) * bmp_w;
	unsigned long* dat = NULL;
	dat = (unsigned long*)malloc(dat_size);
	if (dat == NULL) return -4;

	int i = x; if (i < 0) i = 0;
	for (i = i; i < x + bmp_h && i < data->height; i++) {
		memset(dat, 0, dat_size);
		
		image_bmp_cfread(bmp, i - x, dat, bmp_w);
		
		int j = y; if (j < 0) j = 0;
		for (j = j; j < y + bmp_w && j < data->width; j++) {
			*(data->data + i * data->width + j) = *(dat + j - y);
		}
	}

	if (dat != NULL)free(dat);
	dat = NULL;
	return 1;
}
/*
	2023-02-24 部分透明绘制指定图片
	long x 绘制行（从0开始）
	long y 绘制列（从0开始）
	image_bmp* bmp 绘制的图片
	long cutmode = 0 高切/低切模式
	long cutnum = 255 高切/低切范围
	返回值：
		1： 绘制成功
		-1： 输入错误
		-4： 初始化错误
*/
long image_bmp_drawcut(struct image_bmp* data,long x, long y, struct image_bmp* bmp, long cutmode, long cutnum) {
	if (x >= data->height || y >= data->width || bmp == NULL) return -1;
	if (cutmode <= -3 || cutmode >= 3) return -1;
	if (cutnum < 0 || cutnum > 255) return -1;

	long bmp_h = bmp->height, bmp_w = bmp->width;
	unsigned long dat_size = sizeof(unsigned long) * bmp_w;
	unsigned long* dat = NULL;
	dat = (unsigned long*)malloc(dat_size);
	if (dat == NULL) return -4;

	int i = x; if (i < 0) i = 0;
	for (i = i; i < x + bmp_h && i < data->height; i++) {
		memset(dat, 0, dat_size);
		image_bmp_cfread(bmp, i - x, dat, bmp_w);

		int j = y; if (j < 0) j = 0;
		for (j = j; j < y + bmp_w && j < data->width; j++) {
			unsigned long draw_temp_data = *(dat + j - y);
			unsigned long draw_temp_data_c[3];
			short draw_temp_cutdh = 0;
			int k = 0;
			for (k = 0; k < 3; k++) {
				draw_temp_data_c[2 - k] = draw_temp_data % 256;
				//高低切 
				if (cutmode == image_bmp_highcut || cutmode == image_bmp_lowcut) {
					if (cutmode == image_bmp_highcut && draw_temp_data_c[2 - k] > cutnum) {
						draw_temp_data_c[2 - k] = cutnum;
					}
					else if (cutmode == image_bmp_lowcut && draw_temp_data_c[2 - k] < cutnum) {
						draw_temp_data_c[2 - k] = cutnum;
					}
				}
				//透明高低切
				else if (cutmode == image_bmp_highcutdh || cutmode == image_bmp_lowcutdh) {
					if (cutmode == image_bmp_highcutdh && draw_temp_data_c[2 - k] >= cutnum) {
						draw_temp_cutdh = 1;
						break;
					}
					else if (cutmode == image_bmp_lowcutdh && draw_temp_data_c[2 - k] <= cutnum) {
						draw_temp_cutdh = 1;
						break;
					}
				}
				draw_temp_data /= 256;
			}
			if (draw_temp_cutdh == 0) {
				*(data->data + i * data->width + j) = 0;
				int k = 0;
				for (k = 0; k < 3; k++) {
					*(data->data + i * data->width + j) = (*(data->data + i * data->width + j)) << 8;
					*(data->data + i * data->width + j) += draw_temp_data_c[k];
				}
			}
		}
	}

	if (dat != NULL)free(dat);
	dat = NULL;
	return 1;
}
