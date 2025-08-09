#include <stdio.h>
void menu(void){
    printf("menu\n");
}
void add_vector(void){
    printf("1\n");
}
void view_vectors(void){
    printf("2\n");
}
void delete_vector(void){
    printf("3\n");
}
void sum_vectors(void){
    printf("4\n");
}
void scalarnoe(void){
    printf("5\n");
}
void clean(void){
    printf("6\n");
}
 int main(){
    int action;
    int run = 1;
    menu();
    while (run == 1) {
        printf("\n> Select action: ");
        scanf("%d", &action);
        switch (action) {
            case 1: add_vector(); break;
            case 2: view_vectors(); break;
            case 3: delete_vector(); break;
            case 4: sum_vectors(); break;
            case 5: scalarnoe(); break;
            case 6: clean(); run=0; break;
            default : printf("\nWrong action"); break;
        }
    }
    return 0;
 }