#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "string.h"

#define MAX_STRINGS 100

String* strings[MAX_STRINGS];
int string_count = 0;

void print_menu() {
    printf("\n======= MENU ========\n");
    printf("1) Add a new string\n");
    printf("2) Show string(s)\n");
    printf("3. Concatenation\n");
    printf("4) Get substring\n");
    printf("5) Find substring\n");
    printf("6) Abort programm\n");
    printf("=======================\n");
}

void create_string() {
    if (string_count >= MAX_STRINGS) {
        printf("Strings limit\n");
        return;
    }
    
    char input[1024];
    printf("Input string: ");
    getchar();
    if (!fgets(input, sizeof(input), stdin)) {
        return;
    }
    
    input[strcspn(input, "\n")] = '\0';
    
    String* s = string_create(input);
    if (s) {
        strings[string_count++] = s;
        printf("Strind was added with number %d\n", string_count);
    } else {
        printf("Strind wasn't added\n");
    }
}

void list_strings() {
    printf("\n=== String's list ===\n");
    for (int i = 0; i < string_count; i++) {
        printf("String %d: \"", i+1);
        string_print(strings[i]);
        printf("\"\n");
    }
}

void concat_strings() {
    if (string_count == 0) {
        printf("No strings\n");
        return;
    }
    int num1, num2;
    printf("Choose strings:");
    scanf("%d %d", &num1, &num2);
    if (num1 < 0 || num1 > string_count || num2 < 0 || num2 > string_count) {
        printf("Wrong strings\n");
        return;
    }
    
    String* result = string_concat(strings[num1-1], strings[num2-1]);
    if (result) {
        if (string_count < MAX_STRINGS) {
            strings[string_count++] = result;
            printf("string is added with number %d\n", string_count);
        } else {
            printf("String limit\n");
            string_print(result);
            printf("\n");
            string_free(result);
        }
    } else {
        printf("Error\n");
    }
}

void get_substring() {
    if (string_count == 0) {
        printf("No strings\n");
        return;
    }
    int num;
    size_t first, last;
    printf("Choose string: ");
    scanf("%d", &num);
    printf("first and last symbol: ");
    scanf("%zu %zu", &first, &last);
    
    if (num < 0 || num > string_count) {
        printf("Wrong string\n");
        return;
    }
    
    String* sub = string_substring(strings[num-1], first-1, last);
    if (sub) {
        if (string_count < MAX_STRINGS) {
            strings[string_count++] = sub;
            printf("Substring: \"");
            string_print(sub);
            printf("\" with numder %d\n", string_count);
        } else {
            printf("String limit\n");
            string_print(sub);
            printf("\n");
            string_free(sub);
        }
    } else {
        printf("Error\n");
    }
}

void find_substring() {
    if (string_count < 2) {
        printf("Need %d more string(s)\n", 2-string_count);
        return;
    }
    int main_string, sub_string;
    printf("Choose main string and sub string: ");
    scanf("%d %d", &main_string, &sub_string);
    
    if (main_string < 0 || main_string > string_count || sub_string < 0 || sub_string > string_count) {
        printf("\n");
        return;
    }
    
    int case_sensitive;
    printf("Case sensitivity (1 - yes, 0 - no): ");
    scanf("%d", &case_sensitive);
    
    int pos = string_find(strings[main_string-1], strings[sub_string-1], case_sensitive);
    if (pos >= 0) {
        printf("Substring is found on %d position\n", pos);
    } else {
        printf("Substring isn't found\n");
    }
}

void cleanup() {
    for (int i = 0; i < string_count; i++) {
        string_free(strings[i]);
    }
    printf("Aborting\n");
}
