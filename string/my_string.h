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

//��ȡ�ַ����Ӵ�
char* substr(char* s, int offset, int length);
//KMPƥ��
int KMP_match(char* s, char* p, int begin);
//��char*����string����
string new_string(const char* s);
//��string������string����
string new_string_s(string s);

/*	˽�к��� ������ֱ�ӷ��� ������ϰ��ȡ������
void string_init(string,const char*);		//string���캯��
void KMP_next_pre(char*, int*);				//KMPԤ������
void str_destroy(void*);					//string��������
void str_push_back(string, char);			//�ַ���ĩβ���һ���ַ�
char str_pop_back(string);					//ɾ���ַ���ĩβ���ַ�
void str_copy(void*,const void*);			//string�Ŀ���
void str_c_copy(string, const char*);		//�����ַ����Ŀ���
unsigned int str_size();					//string������ڴ��С
void str_show(string);						//��ӡ�ַ���
bool str_equal(string, string);				//�ж��Ƿ����
bool str_c_equal(string, const char*);		//�ж��Ƿ����
bool str_greater(string, string);			//�ж��Ƿ����
bool str_c_greater(string,const char*);		//�ж��Ƿ����
bool str_less(string, string);				//�ж��Ƿ�С��
bool str_c_less(string, const char*);		//�ж��Ƿ�С��
void str_append(string, string);			//�ַ���ĩβ׷��
void str_c_append(string, char*);			//�ַ���ĩβ׷��
char* str_c_substr(string, int, int);		//��ȡ�Ӵ�
string str_substr(string, int, int);		//��ȡ�Ӵ�
int str_find(string,string,int);			//����ƥ����Ӵ�
int str_c_find(string,char*,int);			//����ƥ����Ӵ�
void str_clear(string);						//����ַ���
void str_reverse(string);					//��ת�ַ���
void str_erase(string,int,int);				//ɾ���Ӵ�
void str_c_insert(string,int,char*)			//��ָ��λ�ò����ַ���
void str_insert(string,int,string)			//��ָ��λ�ò����ַ���
int str_cmp(const void*,const void*)		//�Ƚϴ�С
*/

struct my_string {
	//������
	char* str;
	//�ַ�������
	unsigned int length;
	//��������
	void(*destroy)(void* obj);
	//��ĩβ���һ���ַ�
	void(*push_back)(string self, char c);
	//ɾ�������ַ�
	char(*pop_back)(string self);
	//���ƺ���
	void(*copy)(void* dest, const void* src);
	//���ƺ��� C�ַ���
	void(*c_copy)(string self, const char* s);
	//��ȡ����ṹ���С
	unsigned int(*size)();
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
	//ģ��ȽϺ���
	int(*compare)(const void* a,const void* b);
};

#endif