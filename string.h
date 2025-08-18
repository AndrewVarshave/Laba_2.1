#ifndef STRING_H
#define STRING_H

#include <stdio.h>   
#include <stdlib.h>  
#include <string.h>  

typedef struct String {
    char* data;    
    size_t length;  
    size_t capacity; 
} String;

String* string_create(const char* initial);
void string_free(String* s);
String* string_concat(String* s1, String* s2);
String* string_substring(String* s, size_t start, size_t end);
int string_find(String* first, String* second, int case_sensitive);
void string_print(String* s);

#endif