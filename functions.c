#include "functions.h"
    
void concat() {

    String* string1; 
    String* string2;
    String* result;
    printf("Choose type of first object for concatenation then input it\n");
    string1 = type_setting(string1);
    string1 = string1->info->create(string1);
    printf("Choose type of second object for concatenation then input it\n");
    string2 = type_setting(string2);
    string2 = string2->info->create(string2);
    printf("Choose type of result object for concatenation\n");
    result = type_setting(result);
    result = result->info->concat(result, string1, string2);
    result->info->print(result);
    string1->info->free(string1);
    string2->info->free(string2);
    result->info->free(result);
    
}
void get_substring(void) {

    String* string;
    size_t first, last;
    printf("Choose type of object then input it\n");
    string = type_setting(string);
    string = string->info->create(string);
    printf("> Input first and last symbol: ");
    scanf("%zu %zu", &first, &last);
    string = string->info->substring(string, first-1, last);
    string->info->print(string);
    string->info->free(string);

}
void find_sensitive(void) {

    String* string1;
    String* string2;
    printf("Choose type of main string then input it\n");
    string1 = type_setting(string1);
    string1 = string1->info->create(string1);
    printf("Choose type of sub string then input it\n");
    string2 = type_setting(string2);
    string2 = string2->info->create(string2);
    string1->info->find_sensitive(string1, string2);
    string1->info->free(string1);
    string2->info->free(string2);

}
void find_unsensitive(void) {

    String* string1;
    String* string2;
    printf("Choose type of main string then input it\n");
    string1 = type_setting(string1);
    string1 = string1->info->create(string1);
    printf("Choose type of sub string then input it\n");
    string2 = type_setting(string2);
    string2 = string2->info->create(string2);
    string1->info->find_unsensitive(string1, string2);
    string1->info->free(string1);
    string2->info->free(string2);

}
void* type_setting(String* string) {
    
    int type;
    while (1) {

        printf("> Select type: ");
        scanf("%d", &type);
        switch (type) {

            case 1:
                    string = malloc(sizeof(String));
                    if (!string) {

                        printf("pizdec");
                        break;
            
                    }
                    string->length = 0;
                    string->capacity = 1;
                    string->data = (char*)malloc(sizeof(string->capacity));
                    if (!string->data){

                        printf("peremoga");
                        break;

                    }
                    string->data="\0";
                    string = String_get_type(string);
                    return string;
            default: 
                    printf("Wrong type\n");
                    break;

            }

        }
}