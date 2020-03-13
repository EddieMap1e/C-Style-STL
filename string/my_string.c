/*
 * Copyright (C) 2020 Eddie
 *
 * This library is free software
 * you can redistribute it and/or modify it
 *
 * Author e-mail: 752654212@qq.com
 *
 */

#define _CRT_SECURE_NO_WARNINGS
#include "my_string.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* substr(char* s, int offset, int length)
{
	if (offset < 0 || length <= 0)return "\0";	//�������뷵�ؿ��ַ���
	int len = strlen(s);
	int len_ret;	//��ȡ�ĳ���
	if (len - offset >= length)len_ret = length;	//�㹻��ȡ
	else len_ret = len - offset;	//������ȡ ֱ��ĩβ
	char* tmp = (char*)malloc(sizeof(char)*(len_ret + 1));
	strncpy(tmp, s + offset, len_ret);
	tmp[len_ret] = '\0';	//strncpy���������Ҫ�ֶ�����ֹ��
	return tmp;
}

void KMP_next_pre(char* p, int* next)	//KMPԤ������
{
	int plen = strlen(p);
	for (int i = 1, j = 0; i < plen; i++)	//i�ǵ�ǰ�������ĺ�׺ j��ǰ׺
	{
		while (j&&p[i] != p[j])j = next[j - 1];	//��ת
		if (p[i] == p[j])j++;	//ǰ��׺һ�� ǰ׺��ʼ���
		next[i] = j;
	}
}

int KMP_match(char* s, char* p, int begin)
{
	int slen = strlen(s), plen = strlen(p);
	int* next = (int*)malloc(sizeof(int)*plen);
	memset(next, 0, sizeof next);
	KMP_next_pre(p, next);	//Ԥ�������ת����
	for (int i = begin, j = 0; i < slen; i++)
	{
		while (j&&s[i] != p[j])j = next[j - 1];	//ƥ��ʧ�� ��ת
		if (s[i] == p[j])j++;	//ƥ��ɹ�
		if (j == plen)	//pattern��ƥ�����
		{
			free(next);		//C���Լǵ�free��
			return i - plen + 1;
		}
	}
	free(next);
	return -1;	//ƥ�䲻�ɹ�
}

void str_show(string self)
{
	printf("%s", self->str);
}

void str_c_copy(string self, const char* s)
{
	free(self->str);	//��Ҫ�ͷ�ԭ���Ŀռ�
	self->length = strlen(s);
	self->str = (char*)malloc(sizeof(char)*(self->length+1));
	strcpy(self->str, s);
}

void str_copy(string self, string s)
{
	str_c_copy(self, s->str);
}

void str_push_back(string self, char c)
{
	int len = self->length + 2;
	self->str = (char*)realloc(self->str, sizeof(char)*len);	//���·���ռ�
	self->str[len - 2] = c;
	self->str[len - 1] = '\0';
	self->length++;
}

char str_pop_back(string self)
{
	//�˺�������ע��ռ�Ķ�ʧ realloc����
	int len = self->length;
	if (!len)return '\0';
	char c = self->str[len - 1];
	self->str[len - 1] = '\0';
	self->length--;
	return c;
}

unsigned str_size(string self)
{
	return self->length;
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
	self->str = (char*)realloc(self->str, sizeof(char)*(self->length + 1));	//���·���ռ�
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
	if (begin >= end)return;	//�Ƿ�
	int len = self->length;
	if (end > len)end = len;	//ɾ�����
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
	for (int i = self->length - len - 1, j = self->length - 1; j >= pos + len; i--, j--)	//�Ӻ���ǰ����
		self->str[j] = self->str[i];
	for (int i = pos, j = 0; i < pos + len; i++, j++)
		self->str[i] = s[j];
	self->str[self->length] = '\0';
}

void str_insert(string self, int pos, string s)
{
	str_c_insert(self, pos, s->str);
}

void str_destroy(string self)
{
	free(self->str);
	self->length = 0;
	self->destroy = NULL;
	self->copy = NULL;
	self->c_copy = NULL;
	self->show = NULL;
	self->push_back = NULL;
	self->pop_back = NULL;
	self->size = NULL;
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

void string_init(string self,const char* s)
{
	if (s) {
		self->length = strlen(s);
		self->str = (char*)malloc(sizeof(char)*(self->length+1));
		strcpy(self->str, s);
	}
	else {		//�Ƿ������ָ��
		self->length = 0;
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
	self->reverse = str_reverse;
	self->erase = str_erase;
	self->c_insert = str_c_insert;
	self->insert = str_insert;
}

string new_string(const char* s)
{
	string ret = (string)malloc(sizeof(struct my_string));
	string_init(ret, s);
	return ret;
}

string new_string_s(string s)
{
	if (s == NULL)return NULL;
	return new_string(s->str);
}