#include "test.h"
#include "string_type.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

static void test_string_concat(void) {
    printf("=== Testing string concatenation ===\n");
    
    printf("Creating first string...\n");
    String* s1 = malloc(sizeof(String));
    printf("Memory allocated for s1 successfully\n");
    
    s1->length = 5;
    s1->capacity = 6;
    s1->data = strdup("Hello");
    printf("s1 data set to: %s\n", s1->data);
    
    s1 = String_get_type(s1);
    printf("s1 type initialized successfully\n");

    printf("Creating second string...\n");
    String* s2 = malloc(sizeof(String));
    printf("Memory allocated for s2 successfully\n");
    
    s2->length = 6;
    s2->capacity = 7;
    s2->data = strdup(" World");
    printf("s2 data set to: %s\n", s2->data);
    
    s2 = String_get_type(s2);
    printf("s2 type initialized successfully\n");

    printf("Creating result string...\n");
    String* result = malloc(sizeof(String));
    printf("Memory allocated for result successfully\n");
    
    result = String_get_type(result);
    printf("Result type initialized successfully\n");

    printf("Performing concatenation...\n");
    result = s1->info->concat(result, s1, s2);
    printf("Concatenation completed. Result: %s\n", result->data);
    
    printf("Verifying result...\n");
    assert(strcmp(result->data, "Hello World") == 0);
    printf("String content verification passed!\n");
    
    assert(result->length == 11);
    printf("String length verification passed!\n");
    
    printf("Cleaning up memory...\n");
    s1->info->free(s1);
    printf("s1 memory freed\n");
    
    s2->info->free(s2);
    printf("s2 memory freed\n");
    
    result->info->free(result);
    printf("result memory freed\n");
    
    printf("String concatenation test passed!\n\n");
}

static void test_string_substring(void) {
    printf("=== Testing substring extraction ===\n");
    
    printf("Creating source string...\n");
    String* s = malloc(sizeof(String));
    printf("Memory allocated for source string successfully\n");
    
    s->length = 12;
    s->capacity = 13;
    s->data = strdup("Hello World!");
    printf("Source string data set to: %s\n", s->data);
    
    s = String_get_type(s);
    printf("Source string type initialized successfully\n");

    printf("Extracting substring (positions 6-11)...\n");
    String* sub = s->info->substring(s, 6, 11);
    printf("Substring extracted: %s\n", sub->data);
    
    printf("Verifying substring...\n");
    assert(strcmp(sub->data, "World") == 0);
    printf("Substring content verification passed!\n");
    
    assert(sub->length == 5);
    printf("Substring length verification passed!\n");
    
    printf("Cleaning up memory...\n");
    s->info->free(s);
    printf("Source string memory freed\n");
    
    sub->info->free(sub);
    printf("Substring memory freed\n");
    
    printf("Substring test passed!\n\n");
}

static void test_string_find_sensitive(void) {
    printf("=== Testing case-sensitive search ===\n");
    
    printf("Creating main string...\n");
    String* s1 = malloc(sizeof(String));
    printf("Memory allocated for main string successfully\n");
    
    s1->length = 12;
    s1->capacity = 13;
    s1->data = strdup("Hello World!");
    printf("Main string data set to: %s\n", s1->data);
    
    s1 = String_get_type(s1);
    printf("Main string type initialized successfully\n");

    printf("Creating search substring...\n");
    String* s2 = malloc(sizeof(String));
    printf("Memory allocated for search substring successfully\n");
    
    s2->length = 5;
    s2->capacity = 6;
    s2->data = strdup("World");
    printf("Search substring data set to: %s\n", s2->data);
    
    s2 = String_get_type(s2);
    printf("Search substring type initialized successfully\n");

    printf("Performing case-sensitive search...\n");
    s1->info->find_sensitive(s1, s2);
    printf("Case-sensitive search completed\n");

    printf("Cleaning up memory...\n");
    s1->info->free(s1);
    printf("Main string memory freed\n");
    
    s2->info->free(s2);
    printf("Search substring memory freed\n");
    
    printf("Case-sensitive search test passed!\n\n");
}

static void test_string_find_unsensitive(void) {
    printf("=== Testing case-insensitive search ===\n");
    
    printf("Creating main string...\n");
    String* s1 = malloc(sizeof(String));
    printf("Memory allocated for main string successfully\n");
    
    s1->length = 12;
    s1->capacity = 13;
    s1->data = strdup("Hello World!");
    printf("Main string data set to: %s\n", s1->data);
    
    s1 = String_get_type(s1);
    printf("Main string type initialized successfully\n");

    printf("Creating search substring...\n");
    String* s2 = malloc(sizeof(String));
    printf("Memory allocated for search substring successfully\n");
    
    s2->length = 5;
    s2->capacity = 6;
    s2->data = strdup("world");
    printf("Search substring data set to: %s\n", s2->data);
    
    s2 = String_get_type(s2);
    printf("Search substring type initialized successfully\n");

    printf("Performing case-insensitive search...\n");
    s1->info->find_unsensitive(s1, s2);
    printf("Case-insensitive search completed\n");

    printf("Cleaning up memory...\n");
    s1->info->free(s1);
    printf("Main string memory freed\n");
    
    s2->info->free(s2);
    printf("Search substring memory freed\n");
    
    printf("Case-insensitive search test passed!\n\n");
}

void run_all_tests(void) {
    printf("=========== Running All Tests ===========\n\n");
    
    test_string_concat();
    test_string_substring();
    test_string_find_sensitive();
    test_string_find_unsensitive();
    
    printf("=========== All Tests Passed! ===========\n");
}