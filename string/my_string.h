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

//��ȡ�ַ����Ӵ�
char* substr(char* s, int offset, int length);
//KMPƥ��
int KMP_match(char* s, char* p, int begin);
//��char*����string����
string new_string(const char* s);
//��string������string����
string new_string_s(string s);
//string��������
void string_destroy(void* obj_addr);
//string�Ŀ�������
void string_copy(void* dest_addr, const void* src_addr);
//string�ıȽϺ���
int string_cmp(const void* a_addr, const void* b_addr);

struct my_string {
	//������
	char* str;
	//�ַ�������
	unsigned int length;
	//��������
	void(*destroy)(string self);
	//��ĩβ���һ���ַ�
	void(*push_back)(string self, char c);
	//ɾ�������ַ�
	char(*pop_back)(string self);
	//���ƺ���
	void(*copy)(string self,string s);
	//���ƺ��� C�ַ���
	void(*c_copy)(string self, const char* s);
	//��ӡ�ַ���
	void(*show)(string self);
	//�ж����
	bool(*equal)(string self, string s);
	//�ж����
	bool(*c_equal)(string self, const char* s);
	//�жϴ���
	bool(*greater_than)(string self,string s);
	//�жϴ���
	bool(*c_greater_than)(string self, const char* s);
	//�ж�С��
	bool(*fewer_than)(string self, string s);
	//�ж�С��
	bool(*c_fewer_than)(string self, const char* s);
	//׷���ַ��� C�ַ���
	void(*c_append)(string self, char* s);
	//׷���ַ���
	void(*append)(string self, string s);
	//��ȡ�Ӵ� C�ַ���
	char*(*c_substr)(string self, int offset, int length);
	//��ȡ�Ӵ�
	string(*substr)(string self, int offset, int length);
	//�����Ӵ�
	int(*find)(string self, string s, int begin);
	//�����Ӵ� C�ַ���
	int(*c_find)(string self, char* s, int begin);
	//����ַ���
	void(*clear)(string self);
	//��ת�ַ���
	void(*reverse)(string self);
	//ɾ���Ӵ�
	void(*erase)(string self, int begin, int end);
	//�����Ӵ� C�ַ���
	void(*c_insert)(string self, int pos, char* s);
	//�����Ӵ�
	void(*insert)(string self, int pos, string s);
};

#endif