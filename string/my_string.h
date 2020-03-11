#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdbool.h>

typedef struct my_string string;

void string_init(string*,const char*);		//string初始化
void str_push_back(string*, char);			//字符串末尾添加一个字符
char str_pop_back(string*);					//删除字符串末尾的字符
void str_copy(string*, string*);			//string的拷贝
void str_c_copy(string*, const char*);		//常量字符串的拷贝
unsigned int str_size(string*);				//字符串的长度
void str_show(string*);						//打印字符串
bool str_equal(string*, string*);			//判断是否相等
bool str_c_equal(string*, const char*);		//判断是否相等
bool str_greater(string*, string*);			//判断是否大于
bool str_c_greater(string*,const char*);	//判断是否大于
bool str_less(string*, string*);			//判断是否小于
bool str_c_less(string*, const char*);		//判断是否小于

struct my_string {
	char* str;
	void(*init)(string*,const char*);
	void(*push_back)(string*, char);
	char(*pop_back)(string*);
	void(*copy)(string*, string*);
	void(*c_copy)(string*, const char*);
	unsigned int(*size)(string*);
	void(*show)(string*);
	bool(*equal)(string*, string*);
	bool(*c_equal)(string*, const char*);
	bool(*greater_than)(string*,string*);
	bool(*c_greater_than)(string*, const char*);
	bool(*fewer_than)(string*, string*);
	bool(*c_fewer_than)(string*, const char*);
};

#endif