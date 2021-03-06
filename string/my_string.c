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

#include "my_string.h"

char* substr(char* s, int offset, int length)
{
	if (offset < 0 || length <= 0)return "\0";	//错误输入返回空字符串
	int len = strlen(s);
	int len_ret;	//截取的长度
	if (len - offset >= length)len_ret = length;	//足够截取
	else len_ret = len - offset;	//不够截取 直到末尾
	char* tmp = (char*)malloc(sizeof(char)*(len_ret + 1));
	assert(tmp != NULL);
	strncpy(tmp, s + offset, len_ret);
	tmp[len_ret] = '\0';	//strncpy这个函数需要手动补终止符
	return tmp;
}

void KMP_next_pre(char* p, int* next)	//KMP预处理函数
{
	int plen = strlen(p);
	for (int i = 1, j = 0; i < plen; i++)	//i是当前遍历到的后缀 j是前缀
	{
		while (j&&p[i] != p[j])j = next[j - 1];	//跳转
		if (p[i] == p[j])j++;	//前后缀一样 前缀开始向后
		next[i] = j;
	}
}

int KMP_match(char* s, char* p, int begin)
{
	int slen = strlen(s), plen = strlen(p);
	int* next = (int*)malloc(sizeof(int)*plen);
	assert(next != NULL);
	memset(next, 0, sizeof next);
	KMP_next_pre(p, next);	//预处理出跳转数组
	for (int i = begin, j = 0; i < slen; i++)
	{
		while (j&&s[i] != p[j])j = next[j - 1];	//匹配失败 跳转
		if (s[i] == p[j])j++;	//匹配成功
		if (j == plen)	//pattern串匹配完毕
		{
			free(next);		//C语言记得free掉
			return i - plen + 1;
		}
	}
	free(next);
	return -1;	//匹配不成功
}

void str_destroy(string self)
{
	assert(self != NULL);
	assert(self->str != NULL);
	free(self->str);
	self->length = 0;
	self->destroy = NULL;
	self->copy = NULL;
	self->c_copy = NULL;
	self->show = NULL;
	self->push_back = NULL;
	self->pop_back = NULL;
	self->equal = NULL;
	self->c_equal = NULL;
	self->greater_than = NULL;
	self->c_greater_than = NULL;
	self->fewer_than = NULL;
	self->c_fewer_than = NULL;
	self->append = NULL;
	self->c_append = NULL;
	self->c_substr = NULL;
	self->substr = NULL;
	self->find = NULL;
	self->c_find = NULL;
	self->clear = NULL;
	self->reverse = NULL;
	self->erase = NULL;
	self->c_insert = NULL;
	self->insert = NULL;
}

void string_destroy(void* obj_addr)
{
	string obj = *((string*)obj_addr);
	str_destroy(obj);
}

void str_c_copy(string self, const char* s)
{
	//不允许未初始化使用成员函数
	assert(self->str != NULL);
	free(self->str);	//先要释放原来的空间
	self->length = strlen(s);
	self->str = (char*)malloc(sizeof(char)*(self->length + 1));
	assert(self->str != NULL);
	strcpy(self->str, s);
}

void str_copy(string self, string s)
{
	str_c_copy(self, s->str);
}

void string_copy(void* dest_addr, const void* src_addr)
{
	string dest = *((string*)dest_addr), src = *((string*)src_addr);
	dest = new_string_s(src);
}

int string_cmp(const void* a_addr, const void* b_addr)
{
	return strcmp((*(string*)a_addr)->str, (*(string*)b_addr)->str);
}

void str_show(string self)
{
	printf("%s", self->str);
}

void str_push_back(string self, char c)
{
	int len = self->length + 2;
	self->str = (char*)realloc(self->str, sizeof(char)*len);	//重新分配空间
	assert(self->str != NULL);
	self->str[len - 2] = c;
	self->str[len - 1] = '\0';
	self->length++;
}

char str_pop_back(string self)
{
	//此函数无需注意空间的丢失 realloc会解决
	int len = self->length;
	assert(len > 0);
	char c = self->str[len - 1];
	self->str[len - 1] = '\0';
	self->length--;
	return c;
}

bool str_c_equal(string self, const char* s)
{
	if (!strcmp(self->str, s))return true;
	return false;
}

bool str_equal(string self, string s)
{
	return str_c_equal(self, s->str);
}

bool str_c_greater(string self, const char* s)
{
	if (strcmp(self->str, s) > 0)return true;
	return false;
}

bool str_greater(string self, string s)
{
	return str_c_greater(self, s->str);
}

bool str_c_less(string self, const char* s)
{
	if (strcmp(self->str, s) < 0)return true;
	return false;
}

bool str_less(string self, string s)
{
	return str_c_less(self, s->str);
}

void str_c_append(string self, char* s)
{
	int len1 = self->length, len2 = strlen(s);
	self->length = len1 + len2;
	self->str = (char*)realloc(self->str, sizeof(char)*(self->length + 1));	//重新分配空间
	assert(self->str != NULL);
	strcpy(self->str + len1, s);
}

void str_append(string self, string s)
{
	str_c_append(self, s->str);
}

char* str_c_substr(string self, int offset, int length)
{
	return substr(self->str, offset, length);
}

string str_substr(string self, int offset, int length)
{
	char* s = substr(self->str, offset, length);
	string tmp = new_string(s);
	return tmp;
}

int str_find(string self, string p, int begin)
{
	return KMP_match(self->str, p->str, begin);
}

int str_c_find(string self, char* p, int begin)
{
	return KMP_match(self->str, p, begin);
}

void str_clear(string self)
{
	if (self->length==0)return;
	self->str[0] = '\0';
	self->length = 0;
}

void str_reverse(string self)
{
	int len = self->length;
	if (len <= 1)return;
	for (int i = 0, j = len - 1; i < len / 2; i++, j--) {
		char t = self->str[i];
		self->str[i] = self->str[j];
		self->str[j] = t;
	}
}

void str_erase(string self, int begin, int end)
{
	assert(begin < end);
	int len = self->length;
	if (end > len)end = len;	//删到最后
	self->length -= (end - begin);
	for (int i = begin, j = end; j <= len; i++, j++)self->str[i] = self->str[j];
}

void str_c_insert(string self, int pos, char* s)
{
	if (pos >= (int)self->length) {
		str_c_append(self, s);
		return;
	}
	int len = strlen(s);
	if (!len)return;
	self->length += len;
	self->str = (char*)realloc(self->str, sizeof(char)*(self->length + 1));
	assert(self->str != NULL);
	for (int i = self->length - len - 1, j = self->length - 1; j >= pos + len; i--, j--)	//从后往前复制
		self->str[j] = self->str[i];
	for (int i = pos, j = 0; i < pos + len; i++, j++)
		self->str[i] = s[j];
	self->str[self->length] = '\0';
}

void str_insert(string self, int pos, string s)
{
	str_c_insert(self, pos, s->str);
}

void string_init(string self,const char* s)
{
	if (s) {
		self->length = strlen(s);
		self->str = (char*)malloc(sizeof(char)*(self->length+1));
		assert(self->str != NULL);
		strcpy(self->str, s);
	}
	else {		//非法传入空指针
		self->length = 0;
		self->str = (char*)malloc(sizeof(char));
		assert(self->str != NULL);
		self->str[0] = '\0';
	}
	self->destroy = str_destroy;
	self->copy = str_copy;
	self->c_copy = str_c_copy;
	self->show = str_show;
	self->push_back = str_push_back;
	self->pop_back = str_pop_back;
	self->equal = str_equal;
	self->c_equal = str_c_equal;
	self->greater_than = str_greater;
	self->c_greater_than = str_c_greater;
	self->fewer_than = str_less;
	self->c_fewer_than = str_c_less;
	self->append = str_append;
	self->c_append = str_c_append;
	self->c_substr = str_c_substr;
	self->substr = str_substr;
	self->find = str_find;
	self->c_find = str_c_find;
	self->clear = str_clear;
	self->reverse = str_reverse;
	self->erase = str_erase;
	self->c_insert = str_c_insert;
	self->insert = str_insert;
}

string new_string(const char* s)
{
	string ret = (string)malloc(sizeof(struct my_string));
	assert(ret != NULL);
	string_init(ret, s);
	return ret;
}

string new_string_s(string s)
{
	assert(s != NULL);
	return new_string(s->str);
}