#pragma once
#include "image_bmp.h"
#include "File.h"
#include <time.h>

const long MaxFileSize = 1048576;

char api_captcha_file[128] = ".\\27.bmp";//资源文件路径
long api_captcha_file_len = 28;

long api_captcha_num_h = 27;//每个数字的高（外框）
long api_captcha_num_w = 27;//每个数字的宽（外框）
long api_captcha_num_hnc = 25;//每个数字的高（内框）
long api_captcha_num_wnc = 25;//每个数字的宽（内框）
long api_captcha_img_h = 32;//每个划痕的高（外框）
long api_captcha_img_w = 102;//每个划痕的宽（外框）
long api_captcha_img_hnc = 30;//每个划痕的高（内框）
long api_captcha_img_wnc = 100;//每个划痕的宽（内框）

/*
	2023-01-23 初始化captcha接口所需文件
	注意： 请为此预留256k+的内存空间（长期占用），与MaxFileSize的内存空间（初始化使用）
*/
image_bmp captcha_const_data;
image_bmp captcha_const_num[10][20];
image_bmp captcha_const_img[20];
bool captcha_setup() {
	//初始化
	unsigned char* captcha_temp_data = NULL;
	captcha_temp_data = (unsigned char*)malloc(sizeof(unsigned char)*MaxFileSize);
	if (captcha_temp_data == NULL) return 0;
	memset(captcha_temp_data, '\0', sizeof(char)*MaxFileSize);
	long captcha_temp_data_len = read_file(api_captcha_file, (char*)captcha_temp_data, MaxFileSize);
	if (captcha_temp_data_len < 0) return 0;
	if (captcha_const_data.read(captcha_temp_data, captcha_temp_data_len) < 0) return 0;
	//解析原始文件
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 19; j++) {
			captcha_const_num[i][j].bmp_init(api_captcha_num_hnc, api_captcha_num_wnc, captcha_const_data.cfread_bit());
			captcha_const_num[i][j].draw(-i * api_captcha_num_h - 1, -j * api_captcha_num_w - 1, &captcha_const_data);
		}
	}
	//解析为素材
	long captcha_const_numhight = 10 * api_captcha_num_h;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			captcha_const_img[i * 4 + j].bmp_init(api_captcha_img_hnc, api_captcha_img_wnc, captcha_const_data.cfread_bit());
			captcha_const_img[i * 4 + j].draw(-i * api_captcha_img_h - 1 - captcha_const_numhight, -j * api_captcha_img_w - 1, &captcha_const_data);
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
//        "imull [sed], 16807\n\t"
//        "andl [sed], 2147483647\n\t"
//        : [sed]"p"(seed)
//    );
    return seed;
}
//retbuf请确保有 api_captcha_img_hnc*api_captcha_img_wnc/2+54 字节空间 
bool captcha(char* retbuf,char* user_token) {
    if (retbuf == NULL || user_token == NULL) return 0;
    unsigned long acg_ti=captcha_key();
    
    captcha_inside(user_token,acg_ti);
    
    image_bmp captcha_generate_bmp;
	captcha_generate_bmp.bmp_init(api_captcha_img_hnc, api_captcha_img_wnc, 4);
	//绘制底部
	captcha_generate_bmp.draw(0, 0, &captcha_const_img[acg_ti % 16]);
	//绘制验证码
	for (int i = 0; i < 4; i++) {
		long acg_t1 = acg_ti % 10, acg_t2 = acg_ti % 19;
		char acg_tc = acg_t1 + '0';
		captcha_generate_bmp.drawcut(2, i * api_captcha_num_wnc, &captcha_const_num[acg_t1][acg_t2], image_bmp_highcutdh);
		acg_ti /= 13;
	}
	//输出验证码
	captcha_generate_bmp.write((unsigned char*)retbuf, MaxFileSize);
	captcha_generate_bmp.bmp_free();
	
	return 1;
}
