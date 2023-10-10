#pragma once
#include <stdio.h>
#include "asm_optimize.h"
/*
	2022-03-16 读取文件
	将文件读取并存入char*数组
	char* filename 文件名称
	char* s 保存文件的数组
	int slen 数组最大长度
	返回值：
		正整数：成功，返回文件长度
		-1：文件打开失败
		-2：保存文件数组长度不足
*/
int read_file(const char* filename, char* s, int slen) {
	//将图片读取出来
	FILE* fp = fopen(filename, "rb");     //打开文件req.path.c_str() + 1
	if (!fp) {//打开文件失败
		printf("Filed to open %s,\n", filename);
		return -1;
	}
	fseek(fp, 0, SEEK_END);  //一直寻找到文件尾部
	int pic_len = ftell(fp);  //得到图片的长度
	if (pic_len > slen) {//保存文件数组长度不足
		fclose(fp);
		return -2;
	}
	rewind(fp);  //rewind将文件指针指向开头
	memset(s, 0, slen);  //清空文件指针
	//读取文件内容
	fread(s, sizeof(char), pic_len, fp);
	fclose(fp);
	return pic_len;
}
