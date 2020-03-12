#define _CRT_SECURE_NO_WARNINGS
#include "my_string.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* substr(char* s, int offset, int length)
{
	if (offset < 0 || length <= 0)return "\0";	//错误输入返回空字符串
	int len = strlen(s);
	int len_ret;	//截取的长度
	if (len - offset >= length)len_ret = length;	//足够截取
	else len_ret = len - offset;	//不够截取 直到末尾
	char* tmp = (char*)malloc(sizeof(char)*(len_ret + 1));
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

void str_show(string* self)
{
	printf("%s", self->str);
}

void str_copy(string* self, string* s)
{
	free(self->str);	//先要释放原来的空间
	int len = strlen(s->str) + 1;
	self->str = (char*)malloc(sizeof(char)*len);
	strcpy(self->str, s->str);
}

void str_c_copy(string* self, const char* s)
{
	free(self->str);	//先要释放原来的空间
	int len = strlen(s) + 1;
	self->str = (char*)malloc(sizeof(char)*len);
	strcpy(self->str, s);
}

void str_push_back(string* self, char c)
{
	int len = strlen(self->str) + 2;
	self->str = (char*)realloc(self->str, sizeof(char)*len);	//重新分配空间
	self->str[len - 2] = c;
	self->str[len - 1] = '\0';
}

char str_pop_back(string* self)
{
	//此函数无需注意空间的丢失 realloc会解决
	int len = strlen(self->str);
	if (!len)return '\0';
	char c = self->str[len - 1];
	self->str[len - 1] = '\0';
	return c;
}

unsigned str_size(string* self)
{
	return strlen(self->str);
}

bool str_equal(string* self, string* s)
{
	if (!strcmp(self->str, s->str))return true;
	return false;
}

bool str_c_equal(string* self, const char* s)
{
	if (!strcmp(self->str, s))return true;
	return false;
}

bool str_greater(string* self, string* s)
{
	if (strcmp(self->str, s->str) > 0)return true;
	return false;
}

bool str_c_greater(string* self, const char* s)
{
	if (strcmp(self->str, s) > 0)return true;
	return false;
}

bool str_less(string* self, string* s)
{
	if (strcmp(self->str, s->str) < 0)return true;
	return false;
}

bool str_c_less(string* self, const char* s)
{
	if (strcmp(self->str, s) < 0)return true;
	return false;
}

void str_c_append(string* self, char* s)
{
	int len1 = strlen(self->str), len2 = strlen(s);
	self->str = (char*)realloc(self->str, sizeof(char)*(len1 + len2 + 1));	//重新分配空间
	strcpy(self->str + len1, s);
}

void str_append(string* self, string* s)
{
	str_c_append(self, s->str);
}

char* str_c_substr(string *self, int offset, int length)
{
	return substr(self->str, offset, length);
}

string str_substr(string *self, int offset, int length)
{
	string tmp;
	char* s = substr(self->str, offset, length);
	string_init(&tmp, s);
	return tmp;
}

int str_find(string* self, string* p, int begin)
{
	return KMP_match(self->str, p->str, begin);
}

int str_c_find(string* self, char* p, int begin)
{
	return KMP_match(self->str, p, begin);
}

void str_clear(string* self)
{
	if (!strlen(self->str))return;
	self->str[0] = '\0';
}

void str_destroy(string* self)
{
	free(self->str);

}

void string_init(string* self,const char* s)
{
	if (s) {
		int len = strlen(s) + 1;
		self->str = (char*)malloc(sizeof(char)*len);
		strcpy(self->str, s);
	}
	else {		//非法传入空指针
		self->str = (char*)malloc(sizeof(char));
		self->str[0] = '\0';
	}
	self->destroy = str_destroy;
	self->copy = str_copy;
	self->c_copy = str_c_copy;
	self->show = str_show;
	self->push_back = str_push_back;
	self->pop_back = str_pop_back;
	self->size = str_size;
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
}

void string_s_init(string* self, string* s)
{
	string_init(self, s->str);
}