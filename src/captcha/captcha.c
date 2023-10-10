#include "captcha.h"
#include "../asm_optimize.h"
#include <time.h>

const long MaxFileSize = 1048576;

const char api_captcha_file[128] = "testFont.bmp";//资源文件路径
const long api_captcha_file_len = 28;

const long api_captcha_num_h = 27;//每个数字的高（外框）
const long api_captcha_num_w = 27;//每个数字的宽（外框）
const long api_captcha_num_hnc = 25;//每个数字的高（内框）
const long api_captcha_num_wnc = 25;//每个数字的宽（内框）
const long api_captcha_img_h = 32;//每个划痕的高（外框）
const long api_captcha_img_w = 102;//每个划痕的宽（外框）
const long api_captcha_img_hnc = 30;//每个划痕的高（内框）
const long api_captcha_img_wnc = 100;//每个划痕的宽（内框）

/*
	2023-01-23 初始化captcha接口所需文件
	注意： 请为此预留256k+的内存空间（长期占用），与MaxFileSize的内存空间（初始化使用）
*/
struct image_bmp captcha_const_data;
struct image_bmp captcha_const_num[10][20];
struct image_bmp captcha_const_img[20];
short captcha_setup() {
	//初始化
	unsigned char* captcha_temp_data = NULL;
	captcha_temp_data = (unsigned char*)malloc(sizeof(unsigned char)*MaxFileSize);
	if (captcha_temp_data == NULL) return 0;
	memset(captcha_temp_data, '\0', sizeof(char)*MaxFileSize);
	long captcha_temp_data_len = read_file(api_captcha_file, (char*)captcha_temp_data, MaxFileSize);
	if (captcha_temp_data_len < 0) return 0;
	if (image_bmp_read(&captcha_const_data, captcha_temp_data, captcha_temp_data_len) < 0) return 0;
	//解析原始文件
	int i = 0,j = 0;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 19; j++) {
			image_bmp_init(&captcha_const_num[i][j], api_captcha_num_hnc, api_captcha_num_wnc, captcha_const_data.bit);
			//captcha_const_num[i][j].bmp_init(api_captcha_num_hnc, api_captcha_num_wnc, captcha_const_data.cfread_bit());
			image_bmp_draw(&captcha_const_num[i][j], -i * api_captcha_num_h - 1, -j * api_captcha_num_w - 1, &captcha_const_data);
			//captcha_const_num[i][j].draw(-i * api_captcha_num_h - 1, -j * api_captcha_num_w - 1, &captcha_const_data);
		}
	}
	//解析为素材
	long captcha_const_numhight = 10 * api_captcha_num_h;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			image_bmp_init(&captcha_const_img[i * 4 + j], api_captcha_img_hnc, api_captcha_img_wnc, captcha_const_data.bit);
			//captcha_const_img[i * 4 + j].bmp_init(api_captcha_img_hnc, api_captcha_img_wnc, captcha_const_data.cfread_bit());
			image_bmp_draw(&captcha_const_img[i * 4 + j], -i * api_captcha_img_h - 1 - captcha_const_numhight, -j * api_captcha_img_w - 1, &captcha_const_data);
			//captcha_const_img[i * 4 + j].draw(-i * api_captcha_img_h - 1 - captcha_const_numhight, -j * api_captcha_img_w - 1, &captcha_const_data);
		}
	}

	if (captcha_temp_data != NULL)free(captcha_temp_data);
	captcha_temp_data = NULL;
	return 1;
}

//待补充————————————————————————————————————————————保存验证码 
void captcha_inside(char* user_token,unsigned long data){
	
	return;
}
//待补充————————————————————————————————————————————读取验证码 
unsigned long captcha_find(char* user_token){
	
	return 0;
}
unsigned long captcha_key(){
    unsigned long seed = clock();
//    __asm__(
//        "imull %0, 16807\n\t"
//        "andl %0, 2147483647\n\t"
//        : [sed]"r"(seed)
//    );
    return seed;
}
//retbuf请确保有 api_captcha_img_hnc*api_captcha_img_wnc/2+54 字节空间 
short captcha(char* retbuf,char* user_token) {
    if (retbuf == NULL || user_token == NULL) return 0;
    unsigned long acg_ti=captcha_key();
    
    captcha_inside(user_token,acg_ti);
    
    struct image_bmp captcha_generate_bmp;
    image_bmp_init(&captcha_generate_bmp, api_captcha_img_hnc, api_captcha_img_wnc, 4);
//	captcha_generate_bmp.bmp_init(api_captcha_img_hnc, api_captcha_img_wnc, 4);
	//绘制底部
	image_bmp_draw(&captcha_generate_bmp, 0, 0, &captcha_const_img[acg_ti % 16]);
//	captcha_generate_bmp.draw(0, 0, &captcha_const_img[acg_ti % 16]);
	//绘制验证码
	int i = 0;
	for (i = 0; i < 4; i++) {
		long acg_t1 = acg_ti % 10, acg_t2 = acg_ti % 19;
		char acg_tc = acg_t1 + '0';
		//image_bmp_highcutdh = 2(in image_bmp.c)
		//image_bmp_drawcut(&captcha_generate_bmp, 2, i * api_captcha_num_wnc, &captcha_const_num[acg_t1][acg_t2], image_bmp_highcutdh, 255);
		image_bmp_drawcut(&captcha_generate_bmp, 2, i * api_captcha_num_wnc, &captcha_const_num[acg_t1][acg_t2], 2, 255);
		acg_ti /= 13;
	}
	//输出验证码
	image_bmp_write(&captcha_generate_bmp, (unsigned char*)retbuf, MaxFileSize);
	image_bmp_free(&captcha_generate_bmp);
	
	return 1;
}
