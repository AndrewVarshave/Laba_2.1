#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "menu.h"
#include "string.h"

#define MAX_STRINGS 100

String* strings[MAX_STRINGS];
int string_count = 0;

void print_menu() {
    printf("\n======= MENU ========\n");
    printf("0) Run tests\n");
    printf("1) Add a new string\n");
    printf("2) Show string(s)\n");
    printf("3) Concatenation\n");
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
        printf("String was added with number %d\n", string_count);
    } else {
        printf("String wasn't added\n");
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
            printf("\" with number %d\n", string_count);
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

void run_tests() {
    printf("=== STARTING STRING ADT TESTS ===\n\n");
    int pass_count = 0, total_tests = 0;
    #define RUN_TEST(NAME, COND) \
        do { \
            total_tests++; \
            if (COND) { \
                printf("Test %d: %-50s [PASS]\n", total_tests, NAME); \
                pass_count++; \
            } else { \
                printf("Test %d: %-50s [FAIL]\n", total_tests, NAME); \
            } \
        } while (0)

    String* s = string_create("Hello World");
    
    String* sub1 = string_substring(s, 0, 5);
    RUN_TEST("Valid substring (start=0)", 
        sub1 != NULL && strcmp(sub1->data, "Hello") == 0);
    
    String* sub2 = string_substring(s, 6, 11);
    RUN_TEST("Valid substring (end=length)", 
        sub2 != NULL && strcmp(sub2->data, "World") == 0);
    
    String* sub3 = string_substring(s, 0, 0);
    RUN_TEST("Empty substring (start=end)", sub3 == NULL);
    
    String* sub4 = string_substring(s, 0, s->length);
    RUN_TEST("Full string substring", 
        sub4 != NULL && strcmp(sub4->data, "Hello World") == 0);
    
    String* sub5 = string_substring(s, 5, 6);
    RUN_TEST("Single character substring", 
        sub5 != NULL && strcmp(sub5->data, " ") == 0);
    
    String* sub6 = string_substring(s, 10, 5);
    RUN_TEST("Start > end", sub6 == NULL);
    
    String* sub7 = string_substring(s, 0, 100);
    RUN_TEST("End > length", sub7 == NULL);
    
    String* sub8 = string_substring(s, 20, 25);
    RUN_TEST("Start > length", sub8 == NULL);
    
    String* sub9 = string_substring(s, -1, 5);
    RUN_TEST("Negative start", sub9 == NULL);
    
    String* sub10 = string_substring(s, 0, -5);
    RUN_TEST("Negative end", sub10 == NULL);
    
    String* sub11 = string_substring(NULL, 0, 5);
    RUN_TEST("NULL input", sub11 == NULL);
    
    String* empty = string_create("");
    String* sub12 = string_substring(empty, 0, 0);
    RUN_TEST("Empty string substring", sub12 == NULL);
    
    String* sub13 = string_substring(empty, 0, 1);
    RUN_TEST("Empty string with invalid indices", sub13 == NULL);
    
    String* sub14 = string_substring(s, 0, SIZE_MAX);
    RUN_TEST("Extremely large end value", sub14 == NULL);
    
    String* sub15 = string_substring(s, SIZE_MAX - 10, SIZE_MAX);
    RUN_TEST("Extremely large start value", sub15 == NULL);
    
    String* zero = string_create("A");
    String* sub16 = string_substring(zero, 0, 0);
    RUN_TEST("Zero-length substring on single char", sub16 == NULL);
    
    String* sub17 = string_substring(zero, 1, 1);
    RUN_TEST("Start=end=length on single char", sub17 == NULL);
    
    string_free(s);
    string_free(empty);
    string_free(zero);
    if (sub1) string_free(sub1);
    if (sub2) string_free(sub2);
    if (sub4) string_free(sub4);
    if (sub5) string_free(sub5);
    
    printf("\nTEST SUMMARY:\n");
    printf("Passed: %d/%d\n", pass_count, total_tests);
    printf("=== TESTS COMPLETED ===\n");
}

void cleanup() {
    for (int i = 0; i < string_count; i++) {
        string_free(strings[i]);
    }
    printf("Aborting\n");
}

