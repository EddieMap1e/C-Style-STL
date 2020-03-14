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

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct my_string* string;

//获取字符串子串
char* substr(char* s, int offset, int length);
//KMP匹配
int KMP_match(char* s, char* p, int begin);
//用char*构造string对象
string new_string(const char* s);
//用string对象构造string对象
string new_string_s(string s);

/*	私有函数 不允许直接访问 按个人习惯取消隐藏
void string_init(string,const char*);		//string构造函数
void KMP_next_pre(char*, int*);				//KMP预处理函数
void str_destroy(void*);					//string析构函数
void str_push_back(string, char);			//字符串末尾添加一个字符
char str_pop_back(string);					//删除字符串末尾的字符
void str_copy(void*,const void*);			//string的拷贝
void str_c_copy(string, const char*);		//常量字符串的拷贝
unsigned int str_size();					//string对象的内存大小
void str_show(string);						//打印字符串
bool str_equal(string, string);				//判断是否相等
bool str_c_equal(string, const char*);		//判断是否相等
bool str_greater(string, string);			//判断是否大于
bool str_c_greater(string,const char*);		//判断是否大于
bool str_less(string, string);				//判断是否小于
bool str_c_less(string, const char*);		//判断是否小于
void str_append(string, string);			//字符串末尾追加
void str_c_append(string, char*);			//字符串末尾追加
char* str_c_substr(string, int, int);		//获取子串
string str_substr(string, int, int);		//获取子串
int str_find(string,string,int);			//查找匹配的子串
int str_c_find(string,char*,int);			//查找匹配的子串
void str_clear(string);						//清空字符串
void str_reverse(string);					//翻转字符串
void str_erase(string,int,int);				//删除子串
void str_c_insert(string,int,char*)			//在指定位置插入字符串
void str_insert(string,int,string)			//在指定位置插入字符串
int str_cmp(const void*,const void*)		//比较大小
*/

struct my_string {
	//数据域
	char* str;
	//字符串长度
	unsigned int length;
	//析构函数
	void(*destroy)(void* obj);
	//向末尾添加一个字符
	void(*push_back)(string self, char c);
	//删除最后的字符
	char(*pop_back)(string self);
	//复制函数
	void(*copy)(void* dest, const void* src);
	//复制函数 C字符串
	void(*c_copy)(string self, const char* s);
	//获取对象结构体大小
	unsigned int(*size)();
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
	//模板比较函数
	int(*compare)(const void* a,const void* b);
};

#endif