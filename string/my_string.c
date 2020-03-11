#define _CRT_SECURE_NO_WARNINGS
#include "my_string.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

void string_init(string* self,const char* s)
{
	int len = strlen(s) + 1;
	self->str = (char*)malloc(sizeof(char)*len);
	strcpy(self->str, s);
	self->init = string_init;
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
}