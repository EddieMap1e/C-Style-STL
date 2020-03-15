#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_algorithm.h"
int main()
{
	printf("swap: ");
	int a = 1, b = 2;
	printf("int: before: %d %d\n",a,b);
	swap(&a, &b, sizeof(int));
	printf("int: after : %d %d\n", a, b);
	printf("swap: ");
	char c = 'A', d = 'B';
	printf("char: before: %c %c\n", c, d);
	swap(&c, &d, sizeof(char));
	printf("char: after : %c %c\n", c, d);
	printf("swap: ");
	double e = 3.1415926, f = 2.33333;
	printf("double: before: %lf %lf\n", e, f);
	swap(&e, &f, sizeof(double));
	printf("double: after : %lf %lf\n", e, f);
	int arr[5] = { 5,2,1,4,9 };
	printf("arr: 5 2 1 4 9\n");
	printf("max_element: %d\n", *(int*)max_element(arr, 0, 4, sizeof(int), int_cmp));
	printf("min_element: %d\n", *(int*)min_element(arr, 0, 4, sizeof(int), int_cmp));
	printf("quick_sort: ");
	quick_sort(arr, 0, 4, sizeof(int), int_cmp);
	for (int i = 0; i < 5; i++)printf("%d ", arr[i]);
	double arr2[5] = { 6.666,1.223,5.123,3.145,9.876 };
	printf("\narr2: 6.666 1.223 5.123 3.145 9.876\n");
	printf("max_element: %lf\n", *(double*)max_element(arr2, 0, 4, sizeof(double), double_cmp));
	printf("min_element: %lf\n", *(double*)min_element(arr2, 0, 4, sizeof(double), double_cmp));
	printf("quick_sort: ");
	quick_sort(arr2, 0, 4, sizeof(double), double_cmp);
	for (int i = 0; i < 5; i++)printf("%.3lf ", arr2[i]);
	printf("\n");
	return 0;
}