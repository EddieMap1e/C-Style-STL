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

#ifndef MY_ALGORITHM_H
#define MY_ALGORITHM_H

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef TEMPLATE_FUNCTION_NAME
#define TEMPLATE_FUNCTION_NAME

typedef char* byte;
typedef int(*compare_func)(const void* a_addr, const void* b_addr);
typedef void(*destroy_func)(void* obj_addr);
typedef void(*copy_func)(void* dest_addr, const void* src_addr);

#endif

//ģ�彻��
void swap(void* a_addr, void* b_addr, size_t elem_size);
//���ظ�����Χ������Ԫ��
void* max_element(void* arr, int begin, int end, size_t elem_size, compare_func);
//���ظ�����Χ����С��Ԫ��
void* min_element(void* arr, int begin, int end, size_t elem_size, compare_func);
//intģ��ȽϺ���
int int_cmp(const void* a_addr, const void* b_addr);
//longlongģ��ȽϺ���
int long_long_cmp(const void* a_addr,const void* b_addr);
//charģ��ȽϺ���
int char_cmp(const void* a_addr,const void* b_addr);
//floatģ��ȽϺ���
int float_cmp(const void* a_addr,const void* b_addr);
//doubleģ��ȽϺ���
int double_cmp(const void* a_addr,const void* b_addr);
//char*ģ��ȽϺ���
int c_str_cmp(const void* a_addr,const void* b_addr);
//ģ��ð������
void bubble_sort(void* arr, int length, size_t elem_size, compare_func);
//ģ�����������
void quick_sort(void* arr, int begin, int end, size_t elem_size, compare_func);

#endif