#include "string_type.h"

void *String_create(void* s) {

    char input[256];
    printf("> Input string: ");
    getchar();
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Coudn't read string, try again");
        return NULL;
    }
    
    input[strcspn(input, "\n")] = '\0';
    ((String*)s)->length = strlen(input);
    ((String*)s)->capacity = ((String*)s)->length + 1;
    ((String*)s)->data = (char*)malloc(((String*)s)->capacity);
    if (!((String*)s)->data) {

        free(s);
        printf("Issues with memory; ");
        return NULL;

    }
    strcpy(((String*)s)->data, input);
    return String_get_type(s);

}
void String_free(void* s) {
    
    if (((String*)s)) {

        if (((String*)s)->data) { 

            free(((String*)s)->data);
    
        }
        free(((String*)s));

    }
    else {

        printf("Haven't strings to free; ");

    }

}
void* String_concat(void* result, void* s1, void* s2){

    /*printf("%s%s\n", ((String*)s1)->data, ((String*)s2)->data);*/ 
    ((String*)result)->length = ((String*)s1)->length + ((String*)s2)->length;
    ((String*)result)->capacity = ((String*)result)->length + 1;
    ((String*)result)->data = (char*)malloc(((String*)result)->capacity);    
    if (!((String*)result)->data) {

        free(((String*)result)->data);
        free(((String*)result));
        printf("Issues with memory; ");
        return NULL;

    }    
    strcpy(((String*)result)->data, ((String*)s1)->data);
    strcat(((String*)result)->data, ((String*)s2)->data);
    return result; 
    
}
void* String_substring(void* s, size_t start, size_t end) {
    
    if (!((start < end) && (end <= ((String*)s)->length))) {
        printf("Wrong satrt symbol or end symbol; ");
        return NULL;
    }
    
    size_t len = end - start;
    String* sub = (String*)malloc(sizeof(String));
    if (!sub) {
        printf("Coudn't create a substring; ");
        return NULL; 
    }
    sub->info = ((String*)s)->info;
    sub->length = len;
    sub->capacity = len + 1;
    sub->data = (char*)malloc(sub->capacity);
    
    if (!sub->data) {
        free(sub);
        printf("Issues with memory; ");
        return NULL;
    }
    
    strncpy(sub->data, ((String*)s)->data + start, len);
    sub->data[len] = '\0';
    return sub;

}
void String_find_unsensitive(void* s1, void* s2) {

    if (((String*)s2)->length == 0 || ((String*)s2)->length > ((String*)s1)->length || 
        ((String*)s1) == 0 || !((String*)s1) || !((String*)s2)) {

        printf("Wrong Length");
        return; 
        
    }
    int flag=0;
    for (size_t i = 0; i <= ((String*)s1)->length - ((String*)s2)->length + 1; i++) {

        int match = 1;
        for (size_t j = 0; j < ((String*)s2)->length && match; j++) {
            
            char c1 = ((String*)s1)->data[i + j];
            char c2 = ((String*)s2)->data[j];
            if (tolower(c1) != tolower(c2)) {

                match = 0;

            }
        
        }
        if (match)  {

            printf("substring \"%s\" is found on poses %zu - %zu\n", ((String*)s2)->data, i + 1, i +((String*)s2)->length);
            flag=1;

        }
    }
    if (flag == 0) {

        printf("substring \"%s\" isn't found\n", ((String*)s2)->data);

    }

}
void String_find_sensitive(void* s1, void* s2) {

    if (((String*)s2)->length == 0 || ((String*)s2)->length > ((String*)s1)->length || 
        ((String*)s1) == 0 || !((String*)s1) || !((String*)s2)) {

        printf("Wrong Length");
        return; 
        
    }
    int flag=0;
    for (size_t i = 0; i <= ((String*)s1)->length - ((String*)s2)->length + 1; i++) {

        int match = 1;
        for (size_t j = 0; j < ((String*)s2)->length && match; j++) {

            char c1 = ((String*)s1)->data[i + j];
            char c2 = ((String*)s2)->data[j];
            if (c1 != c2) {

                match = 0;

            }
        
        }
        if (match)  {

            printf("substring \"%s\" is found on poses %zu - %zu\n", ((String*)s2)->data, i + 1, i +((String*)s2)->length);
            flag=1;

        }
    }
    if (flag == 0) {

        printf("substring \"%s\" isn't found\n", ((String*)s2)->data);

    }

}
void* String_print(void* s){

    if (((String*)s) && ((String*)s)->data) {
        printf("A new string: \"%s\"\n", ((String*)s)->data);
    }
}
void *String_get_type(void* x) {

    ((String*)x)->info = setting(&String_create,
                               &String_free,
                               &String_concat,
                               &String_substring,
                               &String_find_sensitive,
                               &String_find_unsensitive,
                               &String_print);
    return x;

}