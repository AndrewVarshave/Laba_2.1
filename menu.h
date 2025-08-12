#ifndef MENU_H
#define MENU_H
#include "string.h"

extern String* strings[];
extern int string_count;

void print_menu(void);
void create_string(void);
void list_strings(void);
void concat_strings(void);
void get_substring(void);
void find_substring(void);
void cleanup(void);

#endif