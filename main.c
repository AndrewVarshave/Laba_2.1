#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "menu.h"
#include "test.h"

int main(int argc, char *argv[]) {

    if (argc > 1 && strcmp(argv[1], "-tests") == 0) {
        
        run_all_tests();
        return 0;

    }
    int action;
    print_menu();

    while (1) {

        printf("\n> Select action: ");
        scanf("%d", &action);
        switch (action) { 

            case 1: 
                    concat();
                    break;
            case 2: 
                    get_substring();
                    break;
            case 3: 
                    find_sensitive();
                    break;
            case 4: 
                    find_unsensitive();
                    break;
            case 5: printf("\nAborting\n");
                    return 0; 
                    break;
             default: printf("Wrong action\n");
        }
    }
}