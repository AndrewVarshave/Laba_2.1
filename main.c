#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

void menu() {
    printf("\n=== УПРАВЛЕНИЕ СТРОКАМИ ===\n");
    printf("1. Создать строку\n");
    printf("2. Показать все строки\n");
    printf("3. Конкатенация двух строк\n");
    printf("4. Получить подстроку\n");
    printf("5. Найти подстроку\n");
    printf("6. Выйти\n");
    printf("===========================\n");
}

void create_string() {
    if (string_count >= MAX_STRINGS) {
        printf("Достигнут лимит строк\n");
        return;
    }
    
    char input[1024];
    printf("Введите строку: ");
    getchar();
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Ошибка чтения\n");
        return;
    }
    
    // Удаление символа новой строки
    input[strcspn(input, "\n")] = '\0';
    
    String* s = string_create(input);
    if (s) {
        strings[string_count++] = s;
        printf("Строка создана (ID: %d)\n", string_count - 1);
    } else {
        printf("Ошибка создания строки\n");
    }
}

void list_strings() {
    printf("\n=== СПИСОК СТРОК ===\n");
    for (int i = 0; i < string_count; i++) {
        printf("Строка %d: \"", i);
        string_print(strings[i]);
        printf("\"\n");
    }
}

void concat_strings() {
    if (string_count < 2) {
        printf("Нужно минимум 2 строки\n");
        return;
    }
    
    list_strings();
    int id1, id2;
    printf("Выберите первую строку: ");
    scanf("%d", &id1);
    printf("Выберите вторую строку: ");
    scanf("%d", &id2);
    
    if (id1 < 0 || id1 >= string_count || id2 < 0 || id2 >= string_count) {
        printf("Неверный ID строки\n");
        return;
    }
    
    String* result = string_concat(strings[id1], strings[id2]);
    if (result) {
        if (string_count < MAX_STRINGS) {
            strings[string_count++] = result;
            printf("Результат сохранен (ID: %d)\n", string_count - 1);
        } else {
            printf("Достигнут лимит строк, результат не сохранен\n");
            string_print(result);
            printf("\n");
            string_free(result);
        }
    } else {
        printf("Ошибка конкатенации\n");
    }
}

void get_substring() {
    if (string_count == 0) {
        printf("Нет строк\n");
        return;
    }
    
    list_strings();
    int id;
    size_t start, end;
    printf("Выберите строку: ");
    scanf("%d", &id);
    printf("Начальный индекс: ");
    scanf("%zu", &start);
    printf("Конечный индекс: ");
    scanf("%zu", &end);
    
    if (id < 0 || id >= string_count) {
        printf("Неверный ID строки\n");
        return;
    }
    
    String* sub = string_substring(strings[id], start, end);
    if (sub) {
        if (string_count < MAX_STRINGS) {
            strings[string_count++] = sub;
            printf("Подстрока: \"");
            string_print(sub);
            printf("\" (ID: %d)\n", string_count - 1);
        } else {
            printf("Достигнут лимит строк, результат не сохранен\n");
            string_print(sub);
            printf("\n");
            string_free(sub);
        }
    } else {
        printf("Ошибка получения подстроки\n");
    }
}

void find_substring() {
    if (string_count < 2) {
        printf("Нужно минимум 2 строки\n");
        return;
    }
    
    list_strings();
    int haystack_id, needle_id;
    printf("Выберите строку для поиска: ");
    scanf("%d", &haystack_id);
    printf("Выберите подстроку для поиска: ");
    scanf("%d", &needle_id);
    
    if (haystack_id < 0 || haystack_id >= string_count || 
        needle_id < 0 || needle_id >= string_count) {
        printf("Неверный ID строки\n");
        return;
    }
    
    int case_sensitive;
    printf("Чувствительность к регистру (1 - да, 0 - нет): ");
    scanf("%d", &case_sensitive);
    
    int pos = string_find(strings[haystack_id], strings[needle_id], case_sensitive);
    if (pos >= 0) {
        printf("Подстрока найдена на позиции: %d\n", pos);
    } else {
        printf("Подстрока не найдена\n");
    }
}

void cleanup() {
    for (int i = 0; i < string_count; i++) {
        string_free(strings[i]);
    }
    printf("Память очищена. Программа завершена.\n");
}

int main() {
    int choice;
    menu();
    while (1) {
        printf("> Выберите действие: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Ошибка ввода\n");
            continue;
        }
        
        switch (choice) {
            case 1: create_string(); break;
            case 2: list_strings(); break;
            case 3: concat_strings(); break;
            case 4: get_substring(); break;
            case 5: find_substring(); break;
            case 6: cleanup(); return 0;
            default: printf("Неверный выбор\n");
        }
    }
}