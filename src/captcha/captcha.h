#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../bmp/bmp.h"
#include "../File/File.h"

/*
	2023-01-23 初始化captcha接口所需文件
	注意： 请为此预留256k+的内存空间（长期占用），与MaxFileSize的内存空间（初始化使用）
*/
short captcha_setup();
unsigned long captcha_key();
//retbuf请确保有 api_captcha_img_hnc*api_captcha_img_wnc/2+54 字节空间 
short captcha(char* retbuf,char* user_token);
