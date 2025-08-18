#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main() {
    int action;
    print_menu();
    while (1) {
        printf("> Select action: ");
        scanf("%d", &action);
        switch (action) {
            case 0: run_tests(); break;
            case 1: create_string(); break;
            case 2: list_strings(); break;
            case 3: concat_strings(); break;
            case 4: get_substring(); break;
            case 5: find_substring(); break;
            case 6: cleanup(); return 0;
            default: printf("Wrong action\n");
        }
    }
}