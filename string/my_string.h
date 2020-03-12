#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdbool.h>

typedef struct my_string string;

char* substr(char*, int, int);
void string_init(string*,const char*);		//string���캯��
void str_destroy(string*);					//string��������
void str_push_back(string*, char);			//�ַ���ĩβ���һ���ַ�
char str_pop_back(string*);					//ɾ���ַ���ĩβ���ַ�
void str_copy(string*, string*);			//string�Ŀ���
void str_c_copy(string*, const char*);		//�����ַ����Ŀ���
unsigned int str_size(string*);				//�ַ����ĳ���
void str_show(string*);						//��ӡ�ַ���
bool str_equal(string*, string*);			//�ж��Ƿ����
bool str_c_equal(string*, const char*);		//�ж��Ƿ����
bool str_greater(string*, string*);			//�ж��Ƿ����
bool str_c_greater(string*,const char*);	//�ж��Ƿ����
bool str_less(string*, string*);			//�ж��Ƿ�С��
bool str_c_less(string*, const char*);		//�ж��Ƿ�С��
void str_append(string*, string*);			//�ַ���ĩβ׷��
char* str_c_substr(string*, int, int);		//��ȡ�Ӵ�
string str_substr(string*, int, int);		//��ȡ�Ӵ�

struct my_string {
	char* str;
	void(*init)(string*,const char*);
	void(*destroy)(string*);
	void(*push_back)(string*, char);
	char(*pop_back)(string*);
	void(*copy)(string*, string*);
	void(*c_copy)(string*, const char*);
	unsigned int(*size)(string*);
	void(*show)(string*);
	bool(*equal)(string*, string*);
	bool(*c_equal)(string*, const char*);
	bool(*greater_than)(string*,string*);
	bool(*c_greater_than)(string*, const char*);
	bool(*fewer_than)(string*, string*);
	bool(*c_fewer_than)(string*, const char*);
	void(*append)(string*, string*);
	char*(*c_substr)(string*, int, int);
	string(*substr)(string*, int, int);
};

#endif