#ifndef STRING_TYPE_H
#define STRING_TYPE_H

#include "field_info.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>  

typedef struct String {
    FieldInfo *info;
    char* data;
    size_t length;  
    size_t capacity; 
} String;

void* String_create(void* s);
void String_free(void* s);
void* String_concat(void* result, void* s1, void* s2);
void* String_substring(void* s, size_t start, size_t end);
void String_find_sensitive(void* s1, void* s2);
void String_find_unsensitive(void* s1, void* s2);
void* String_print(void* s);
void *String_get_type(void* x);

#endif