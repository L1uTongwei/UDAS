#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct image_bmp{
	long height, width;//图像高宽
	long bit;//每像素大小
	unsigned long* data;//图片数据
	long widthsize;
}; 

/*
	2023-01-21 初始化图片
	int h图像高
	int w图像宽
	int mode每像素大小
	
	2023-01-22 修复空间开辟的bug
	2023-02-23 内存中强制24bit
*/
short image_bmp_init(struct image_bmp* data,long h, long w, long mode);
/*
	2023-01-21 释放空间
*/
void image_bmp_free(struct image_bmp* data);
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
long image_bmp_read(struct image_bmp* data, unsigned char* dat, long datlen);
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
long image_bmp_write(struct image_bmp* data, unsigned char* dat, long datlen);
/*
	2023-01-21 读取图片指定行信息
	long h 读取的行（从0开始）
	long* dat 输出数组
	long datlen 输出数组最大长度

	更新：
		2023-02-23 兼容在内存中强制为24位的更新
*/
void image_bmp_cfread(struct image_bmp* data, long h, unsigned long* dat, long datlen);
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
long image_bmp_draw(struct image_bmp* data,long x, long y, struct image_bmp* bmp);
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
long image_bmp_drawcut(struct image_bmp* data,long x, long y, struct image_bmp* bmp, long cutmode, long cutnum);
