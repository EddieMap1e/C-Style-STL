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

#include "my_vector.h"

void* v_at(vector self, unsigned int pos)
{
	//���б߽���
	assert(pos < self->size);
	return (byte)self->data + pos * self->elem_size;
}

void v_destroy(vector self)
{
	assert(self != NULL);
	//��ÿ��Ԫ�ؽ�������
	if (self->elem_free != NULL) {
		for (unsigned int i = 0; i < self->size; i++) {
			void* elem_addr = v_at(self, i);
			self->elem_free(elem_addr);
		}
	}
	free(self->data);	//û����������ֱ��free��data����
	self->at = NULL;
	self->destroy = NULL;
	self->size = 0;
	self->max_size = 0;
	self->elem_size = 0;
	self->elem_cmp = NULL;
	self->elem_copy = NULL;
	self->elem_free = NULL;
	self->push_back = NULL;
	self->erase = NULL;
	self->pop_back = NULL;
	self->copy = NULL;
}

void vector_destroy(void* obj_addr)
{
	vector obj = *(vector*)obj_addr;
	v_destroy(obj);
}

//��֤�����ǿ�Ƕ�׵� �����Ƿ�������
int vector_cmp(const void* a_addr, const void* b_addr)
{
	vector a = *((vector*)a_addr), b = *((vector*)b_addr);
	int len1 = a->size, len2 = b->size;
	int len = min(len1, len2);
	// ÿ��Ԫ�ؽ��бȽ� ��0��ַ��ʼ
	for (int i = 0; i < len; i++) {
		void* elem1 = v_at(a, i);
		void* elem2 = v_at(b, i);
		int res = a->elem_cmp(elem1, elem2);
		if (res > 0)return 1;
		else if (res < 0)return -1;
	}
	// ��ͬ���Ȳ��ֶ���ͬ ��Ƚϳ���
	if (len1 > len2)return 1;
	else if (len1 < len2)return -1;
	return 0;
}

void v_copy(vector self, vector v)
{
	if (&self == &v)return;
	//�Ȱ�ԭ����dataȫ���ͷŵ�
	if (self->elem_free != NULL) {
		for (unsigned int i = 0; i < self->size; i++) {
			void* elem_addr = v_at(self, i);
			self->elem_free(elem_addr);
		}
	}
	free(self->data);
	self->data = malloc(v->elem_size*v->max_size);	//���ƿռ��С
	self->max_size = v->max_size;
	memcpy(self->data, v->data, v->elem_size*v->size);	//����Ԫ��
	self->size = v->size;
	if (v->elem_copy != NULL) {
		for (unsigned int i = 0; i < v->size; i++) {
			void* elem1_addr = v_at(self, i);
			void* elem2_addr = v_at(v, i);
			v->elem_copy(elem1_addr, elem2_addr);
		}
	}
	self->elem_size = v->elem_size;
}

void vector_copy(void* dest_addr, const void* src_addr)
{
	vector src = *((vector*)src_addr);
	vector dest = new_vector(src->elem_size, src->elem_free, src->elem_copy, src->elem_cmp);
	v_copy(dest, src);
	*((vector*)dest_addr) = dest;
}

void v_grow(vector self)
{
	self->max_size <<= 1;	//�ڴ淭��
	self->data = realloc(self->data, self->max_size*self->elem_size);
	assert(self->data != NULL);
}

void v_push_back(vector self,void* elem_addr)
{
	if (self->size == self->max_size)v_grow(self);	//��������
	void* dest_addr = (byte)self->data + self->elem_size*self->size;
	memcpy(dest_addr, elem_addr, self->elem_size);
	if (self->elem_copy != NULL)self->elem_copy(dest_addr, elem_addr);	//��Ҫ���
	self->size++;
}

void v_erase(vector self, unsigned int pos)
{
	assert(pos < self->size);
	void* elem = self->at(self, pos);
	if (self->elem_free != NULL)self->elem_free(elem);
	int size = (self->size - 1 - pos)*self->elem_size;
	//�˴��������һ��λ�õ�Ԫ�ػᱣ�� 
	//����ǰһ��������ǳ����
	//���Բ���������
	//ȫ�����ƶ�Ҳ��ǳ��������
	memmove(elem, (byte)self->at(self, pos)+self->elem_size, size);
	self->size--;
}

void v_pop_back(vector self)
{
	assert(self->size > 0);
	v_erase(self, self->size - 1);
}

void v_init(vector self, size_t elem_size,
	destroy_func destroy, copy_func copy,
	compare_func compare)
{
	assert(self != NULL);
	self->elem_size = elem_size;
	self->size = 0;
	self->max_size = 4;		//��ʼ����Ϊ4
	self->data = malloc(elem_size * 4);		//�����ʼ�ռ�
	self->elem_cmp = compare;
	self->elem_copy = copy;
	self->elem_free = destroy;
	self->destroy = v_destroy;
	self->at = v_at;
	self->push_back = v_push_back;
	self->erase = v_erase;
	self->pop_back = v_pop_back;
	self->copy = v_copy;
}

vector new_vector(size_t elem_size, destroy_func destroy,
	copy_func copy, compare_func compare)
{
	vector ret = (vector)malloc(sizeof(struct my_vector));
	assert(ret != NULL);
	v_init(ret, elem_size, destroy, copy, compare);
	return ret;
}