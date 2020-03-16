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

//模板交换
void swap(void* a_addr, void* b_addr, size_t elem_size);
//返回给定范围中最大的元素
void* max_element(void* arr, int begin, int end, size_t elem_size, compare_func);
//返回给定范围中最小的元素
void* min_element(void* arr, int begin, int end, size_t elem_size, compare_func);
//int模板比较函数
int int_cmp(const void* a_addr, const void* b_addr);
//longlong模板比较函数
int long_long_cmp(const void* a_addr,const void* b_addr);
//char模板比较函数
int char_cmp(const void* a_addr,const void* b_addr);
//float模板比较函数
int float_cmp(const void* a_addr,const void* b_addr);
//double模板比较函数
int double_cmp(const void* a_addr,const void* b_addr);
//char*模板比较函数
int c_str_cmp(const void* a_addr,const void* b_addr);
//模板冒泡排序
void bubble_sort(void* arr, int length, size_t elem_size, compare_func);
//模板快速排序函数
void quick_sort(void* arr, int begin, int end, size_t elem_size, compare_func);

#endif