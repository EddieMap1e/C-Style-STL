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

#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

typedef struct my_vector* vector;

#ifndef TEMPLATE_FUNCTION_NAME
#define TEMPLATE_FUNCTION_NAME

typedef char* byte;
typedef int(*compare_func)(const void* a_addr, const void* b_addr);
typedef void(*destroy_func)(void* obj_addr);
typedef void(*copy_func)(void* dest_addr, const void* src_addr);

#endif

//��ȡ����vector����
vector new_vector(size_t elem_size,destroy_func,copy_func,compare_func);
//vector��������
void vector_destroy(void* obj_addr);
//ģ��ȽϺ���
int vector_cmp(const void* a_addr, const void* b_addr);
//ģ�帴�ƺ���
void vector_copy(void* dest_addr, const void* src_addr);

struct my_vector{
	//ָ������Ԫ�ص�ָ�� ��������׵�ַ
	void* data;
	//ÿ��Ԫ��ռ�ڴ�Ĵ�С
	size_t elem_size;
	//�Ѿ������ڴ�Ĵ�С
	size_t max_size;
	//ʵ�ʴ���Ԫ�صĸ���
	unsigned int size;
	//Ԫ�ص���������
	destroy_func elem_free;
	//Ԫ�صĸ��ƺ���
	copy_func elem_copy;
	//Ԫ�صıȽϺ���
	compare_func elem_cmp;
	//��ȡָ��posλ��Ԫ�ص�ָ��
	void*(*at)(vector self, unsigned int pos);
	//��������
	void(*destroy)(vector self);
	//��ֵ����
	void(*copy)(vector self,vector v);
	//�ں���׷��һ��Ԫ��
	void(*push_back)(vector self, void* elem_addr);
	//ɾ��ָ��λ�õ�Ԫ��
	void(*erase)(vector self, unsigned int pos);
	//��������Ԫ��
	void(*pop_back)(vector self);
};

#endif