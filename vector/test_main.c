#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_vector.h"
int cmp1(const void* a_addr, const void* b_addr)
{
	return *(int*)a_addr - *(int*)b_addr;
}
int cmp2(const void* a_addr, const void* b_addr)
{
	double t = *(double*)a_addr - *(double*)b_addr;
	if (t >= 1e-8)return 1;
	else if (t <= -1e-8)return -1;
	return 0;
}
int main()
{
	vector v = new_vector(sizeof(int), NULL, NULL, cmp1);
	printf("new vector\nsize: %d\nmax_size: %d\n", v->size, v->max_size);
	int arr[] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)v->push_back(v, &arr[i]);
	printf("after push back 5 int elements: {1,2,3,4,5}\nsize: %d\nmax_size: %d\n", v->size, v->max_size);
	int *v_data = (int*)v->data;
	printf("now printf the elements of vector: ");
	for (unsigned int i = 0; i < v->size; i++)printf("%d ", v_data[i]);
	printf("\nuse at() to get element: ");
	for (unsigned int i = 0; i < v->size; i++)printf("%d ", *(int*)v->at(v, i));
	vector v2 = new_vector(sizeof(int), NULL, NULL, cmp1);
	v2->copy(v2, v);
	printf("\nnew v2 copy from v\nsize: %d\nmax_size: %d\n", v2->size, v2->max_size);
	for (unsigned int i = 0; i < v->size; i++)printf("%d ", *(int*)v2->at(v2, i));
	v->erase(v, 1);
	printf("\nerase(1): ");
	for (unsigned int i = 0; i < v->size; i++)printf("%d ",*(int*)v->at(v, i));
	printf("\npop_back(): ");
	v->pop_back(v);
	for (unsigned int i = 0; i < v->size; i++)printf("%d ", *(int*)v->at(v, i));
	printf("\ntry double[][]:\n");
	vector vv = new_vector(sizeof(vector), vector_destroy, vector_copy, vector_cmp);
	for (int i = 0; i < 5; i++)
	{
		vector tmp_v = new_vector(sizeof(double), 0, 0, cmp2);
		double tmp_arr[5] = { i*3.14,i*2,i*6.66,i*4.21,i*1.23 };
		for (int j = 0; j < 5; j++)tmp_v->push_back(tmp_v, &tmp_arr[j]);
		vv->push_back(vv, &tmp_v);
		tmp_v->destroy(tmp_v);
	}
	for (unsigned int i = 0; i < vv->size; i++) {
		vector t = *(vector*)vv->at(vv, i);
		for (unsigned int j = 0; j < t->size; j++) {
			double elem = *(double*)t->at(t, j);
			printf("%lf ", elem);
		}
		printf("\n");
	}
	return 0;
}