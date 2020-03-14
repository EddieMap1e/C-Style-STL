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

typedef char* byte;

#ifndef TEMPLATE_FUNCTION_NAME
#define TEMPLATE_FUNCTION_NAME

typedef int(*compare_func)(const void* a, const void* b);
typedef void(*destroy_func)(void* obj);
typedef void(*copy_func)(void* dest, const void* src);

#endif

//ģ�彻��
void swap(void* a, void* b, size_t elem_size);
//���ظ�����Χ������Ԫ��
void* max_element(void* arr, int begin, int end, size_t elem_size, compare_func);
//���ظ�����Χ����С��Ԫ��
void* min_element(void* arr, int begin, int end, size_t elem_size, compare_func);
//intģ��ȽϺ���
int int_cmp(void* a, void* b);
//longlongģ��ȽϺ���
int long_long_cmp(void* a, void* b);
//charģ��ȽϺ���
int char_cmp(void* a, void* b);
//floatģ��ȽϺ���
int float_cmp(void* a, void* b);
//doubleģ��ȽϺ���
int double_cmp(void* a, void* b);
//char*ģ��ȽϺ���
int c_str_cmp(void* a, void* b);
//ģ��ð������
void bubble_sort(void* arr, int length, size_t elem_size, compare_func);
//ģ�����������
void quick_sort(void* arr, int begin, int end, size_t elem_size, compare_func);

#endif