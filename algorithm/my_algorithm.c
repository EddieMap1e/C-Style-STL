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

#include "my_algorithm.h"

void swap(void* a, void* b, size_t elem_size)
{
	void* t = malloc(elem_size);
	memcpy(t, a, elem_size);
	memcpy(a, b, elem_size);
	memcpy(b, t, elem_size);
	free(t);
}

int int_cmp(void* a, void* b)
{
	return *(int*)a - *(int*)b;
}

int long_long_cmp(void* a, void* b)
{
	long long t = *(long long*)a - *(long long*)b;
	if (t > 0ll)return 1;
	else if (t < 0ll)return -1;
	return 0;
}

int char_cmp(void* a, void* b)
{
	return *(char*)a - *(char*)b;
}

int float_cmp(void* a, void* b)
{
	float t= *(float*)a - *(float*)b;
	if (t >= 1e-8)return 1;
	else if (t <= -1e-8)return -1;
	return 0;
}

int double_cmp(void* a, void* b)
{
	double t = *(double*)a - *(double*)b;
	if (t >= 1e-8)return 1;
	else if (t <= -1e-8)return -1;
	return 0;
}

int c_str_cmp(void* a, void* b)
{
	return strcmp((char*)a, (char*)b);
}

void bubble_sort(void* arr, int length, size_t elem_size,compare_func cmp)
{
	bool flag = true;	//��ǰ����
	void *a, *b;
	for (int i = 0; i < length - 1; i++)
	{
		flag = false;
		for (int j = 0; j < length - i - 1; j++)
		{
			a = (byte)arr + j * elem_size;		//ͨ��ƫ��ֵ��ȡԴ����
			b = (byte)arr + (j + 1)*elem_size;
			if (cmp(a, b) > 0) {
				swap(a, b, elem_size);
				flag = true;
			}
		}
		if (!flag)return;
	}
}

void quick_sort(void* arr, int begin, int end , size_t elem_size, compare_func cmp)
{
	if (begin >= end)return;
	int i = begin - 1, j = end + 1;	//���������ڱ�
	void* base = (byte)arr + ((begin + end) >> 1)*elem_size;	//��׼Ԫ��
	while (i < j)
	{
		while (cmp((byte)arr + (++i)*elem_size, base) < 0);		//���ڱ����ƶ��ҵ���һ���Ȼ�׼Ԫ��Ҫ���
		while (cmp((byte)arr + (--j)*elem_size, base) > 0);		//Ȼ�����ڱ��ƶ���С��
		if (i < j)swap((byte)arr + i * elem_size, (byte)arr + j * elem_size,elem_size);		//����
	}
	quick_sort(arr, begin, j, elem_size, cmp);		//������ߵ�  j
	quick_sort(arr, j + 1, end, elem_size, cmp);	//�����ұߵ�  j+1
}

void* max_element(void* arr, int begin, int end, size_t elem_size, compare_func cmp)
{
	void* ret = (byte)arr + begin * elem_size;
	for (int i = begin+1; i <= end; i++)
		if (cmp(ret, (byte)arr + i * elem_size) < 0)ret = (byte)arr + i * elem_size;
	return ret;		//���ص���Ԫ�ص�����
}

void* min_element(void* arr, int begin, int end, size_t elem_size, compare_func cmp)
{
	void* ret = (byte)arr + begin * elem_size;
	for (int i = begin + 1; i <= end; i++)
		if (cmp(ret, (byte)arr + i * elem_size) > 0)ret = (byte)arr + i * elem_size;
	return ret;		//���ص���Ԫ�ص�����
}