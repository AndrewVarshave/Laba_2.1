#include "string.h"
#include <stdio.h>
#include <ctype.h>  
#include <stdlib.h> 

String* string_create(const char* string) {
    String* s = (String*)malloc(sizeof(String));
    if (!s) { 
        printf("Coudn't make a new string; ");
        return NULL; 
    }
    
    s->length = strlen(string);
    s->capacity = s->length + 1;
    s->data = (char*)malloc(s->capacity);
    
    if (!s->data) {
        free(s);
        printf("Issues with memory; ");
        return NULL;
    }
    
    strcpy(s->data, string);
    return s;
}

void string_free(String* s) {
    if (s) {
        if (s->data) free(s->data);
        free(s);
    }
    else {
        printf("Haven't strings to free; ");
    }
}

String* string_concat(String* s1, String* s2) {
    String* result = (String*)malloc(sizeof(String));
    if (!result) {
        printf("Coudn't make a result string; ");
        return NULL;
    }
    
    result->length = s1->length + s2->length;
    result->capacity = result->length + 1;
    result->data = (char*)malloc(result->capacity);
    
    if (!result->data) {
        free(result);
        printf("Issues with memory; ");
        return NULL;
    }
    
    strcpy(result->data, s1->data);
    strcat(result->data, s2->data);
    
    return result;
}

String* string_substring(String* s, size_t start, size_t end) {
    if (!s || start >= s->length || end > s->length || start >= end) {
        printf("Wrong satrt symbol or end symbol; ");
        return NULL;
    }
    
    size_t len = end - start;
    String* sub = (String*)malloc(sizeof(String));
    if (!sub) {
        printf("Coudn't create a substring; ");
        return NULL; 
    }
    
    sub->length = len;
    sub->capacity = len + 1;
    sub->data = (char*)malloc(sub->capacity);
    
    if (!sub->data) {
        free(sub);
        printf("Issues with memory; ");
        return NULL;
    }
    
    strncpy(sub->data, s->data + start, len);
    sub->data[len] = '\0';
    
    return sub;
}

int string_find(String* first, String* second, int case_sensitive) {
    if (!first || !second || second->length == 0 || second->length > first->length) {
        printf("Wrong strings; ");
        return -1; }
    
    for (size_t i = 0; i <= first->length - second->length; i++) {
        int match = 1;
        for (size_t j = 0; j < second->length; j++) {
            char c1 = first->data[i + j];
            char c2 = second->data[j];
            
            if (case_sensitive==1) {
                if (c1 != c2) {
                    match = 0;
                    break;
                }
            } else if(case_sensitive==0) {
                if (tolower(c1) != tolower(c2)) {
                    match = 0;
                    break;
                }
            }
            else {printf("Wrong case sensitive; "); return -1;}
        }
        if (match) return i;
    }
    return -1;
}

void string_print(String* s) {
    if (s && s->data) {
        printf("%s", s->data);
    }
}