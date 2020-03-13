#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_string.h"
int main()
{
	string s = new_string("hello");
	printf("new_string(\"hello\")\n");
	printf("show(): ");
	s->show(s);
	printf("\nlength: %d\n", s->length);
	s->push_back(s, 's');
	printf("push_back(): %s %d\n", s->str, s->length);
	s->pop_back(s);
	printf("pop_back(): %s %d\n", s->str, s->length);
	s->reverse(s);
	printf("reverse(): %s %d\n", s->str, s->length);
	s->c_copy(s, "hello world");
	printf("c_copy(\"hello world\"): %s %d\n", s->str, s->length);
	printf("c_equal(\"hello world\"): %d\n", s->c_equal(s,"hello world"));
	printf("c_equal(\"hello\"): %d\n", s->c_equal(s, "hello"));
	s->erase(s, 5, 999);
	printf("erase(5,999): %s %d\n", s->str, s->length);
	s->erase(s, 1, 3);
	printf("erase(1,3): %s %d\n", s->str, s->length);
	s->c_insert(s, 1, "el");
	printf("insert(1,\"el\"): %s %d\n", s->str, s->length);
	s->c_append(s, " my_string");
	printf("append(\"my_string\"): %s %d\n", s->str, s->length);
	printf("substr(6,9): %s\n", s->c_substr(s, 6, 9));
	printf("c_find(\"llo\",0): %d\n", s->c_find(s, "llo", 0));
	printf("c_find(\"llo\",6): %d\n", s->c_find(s, "llo", 6));
	s->clear(s);
	printf("clear: %s %d\n", s->str, s->length);
	s->destroy(s);
	printf("destroy: %s %d\n", s->str, s->length);
	string s2 = new_string("hello");
	printf("new_string2(\"hello\")\n");
	s = new_string_s(s2);
	printf("new_string_s(s2): %s %d\n", s->str, s->length);
	return 0;
}