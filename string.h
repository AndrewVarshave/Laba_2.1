#ifndef STRING_H
#define STRING_H

#include <stdio.h>   // Добавлено для printf
#include <stdlib.h>  // Добавлено для size_t
#include <string.h>  // Добавлено для strcspn

typedef struct String {
    char* data;     // Указатель на данные строки
    size_t length;  // Длина строки
    size_t capacity; // Емкость буфера
} String;

String* string_create(const char* initial);

void string_free(String* s);

String* string_concat(String* s1, String* s2);

String* string_substring(String* s, size_t start, size_t end);

int string_find(String* haystack, String* needle, int case_sensitive);

void string_print(String* s);

#endif