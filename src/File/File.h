#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int read_file(const char* filename, char* s, int slen);
