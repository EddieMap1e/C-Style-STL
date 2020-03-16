/*
 * Copyright (C) 2020 Eddie
 *
 * This library is free software
 * you can redistribute it and/or modify it
 * if you find BUG you can send E-mail to me
 *
 * github project https://github.com/EddieMap1e/C-Style-STL
 *
 * Author e-mail: 752654212@qq.com
 */

#ifndef MY_STRING_H
#define MY_STRING_H

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct my_string* string;

//获取字符串子串
char* substr(char* s, int offset, int length);
//KMP匹配
int KMP_match(char* s, char* p, int begin);
//用char*构造string对象
string new_string(const char* s);
//用string对象构造string对象
string new_string_s(string s);
//string析构函数
void string_destroy(void* obj_addr);
//string的拷贝函数
void string_copy(void* dest_addr, const void* src_addr);
//string的比较函数
int string_cmp(const void* a_addr, const void* b_addr);

struct my_string {
	//数据域
	char* str;
	//字符串长度
	unsigned int length;
	//析构函数
	void(*destroy)(string self);
	//向末尾添加一个字符
	void(*push_back)(string self, char c);
	//删除最后的字符
	char(*pop_back)(string self);
	//复制函数
	void(*copy)(string self,string s);
	//复制函数 C字符串
	void(*c_copy)(string self, const char* s);
	//打印字符串
	void(*show)(string self);
	//判断相等
	bool(*equal)(string self, string s);
	//判断相等
	bool(*c_equal)(string self, const char* s);
	//判断大于
	bool(*greater_than)(string self,string s);
	//判断大于
	bool(*c_greater_than)(string self, const char* s);
	//判断小于
	bool(*fewer_than)(string self, string s);
	//判断小于
	bool(*c_fewer_than)(string self, const char* s);
	//追加字符串 C字符串
	void(*c_append)(string self, char* s);
	//追加字符串
	void(*append)(string self, string s);
	//获取子串 C字符串
	char*(*c_substr)(string self, int offset, int length);
	//获取子串
	string(*substr)(string self, int offset, int length);
	//查找子串
	int(*find)(string self, string s, int begin);
	//查找子串 C字符串
	int(*c_find)(string self, char* s, int begin);
	//清空字符串
	void(*clear)(string self);
	//翻转字符串
	void(*reverse)(string self);
	//删除子串
	void(*erase)(string self, int begin, int end);
	//插入子串 C字符串
	void(*c_insert)(string self, int pos, char* s);
	//插入子串
	void(*insert)(string self, int pos, string s);
};

#endif