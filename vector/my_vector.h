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

//获取构造vector对象
vector new_vector(size_t elem_size,destroy_func,copy_func,compare_func);
//vector析构函数
void vector_destroy(void* obj_addr);
//模板比较函数
int vector_cmp(const void* a_addr, const void* b_addr);
//模板复制函数
void vector_copy(void* dest_addr, const void* src_addr);

struct my_vector{
	//指向数据元素的指针 即数组的首地址
	void* data;
	//每个元素占内存的大小
	size_t elem_size;
	//已经分配内存的大小
	size_t max_size;
	//实际储存元素的个数
	unsigned int size;
	//元素的析构函数
	destroy_func elem_free;
	//元素的复制函数
	copy_func elem_copy;
	//元素的比较函数
	compare_func elem_cmp;
	//获取指向pos位的元素的指针
	void*(*at)(vector self, unsigned int pos);
	//析构函数
	void(*destroy)(vector self);
	//赋值函数
	void(*copy)(vector self,vector v);
	//在后面追加一个元素
	void(*push_back)(vector self, void* elem_addr);
	//删除指定位置的元素
	void(*erase)(vector self, unsigned int pos);
	//弹出最后的元素
	void(*pop_back)(vector self);
};

#endif