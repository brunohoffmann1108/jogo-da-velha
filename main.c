#include <stdio.h>

void menu(){
    printf("=================================\n");
    printf("1. Jogador contra jogador\n");
    printf("2. Jogador contra computador\n");
    printf("3. Sair\n");
    printf("Escolha: ");
}

int main(){
    
    int opcao = 0;
    do{
        menu();
        scanf("%i", &opcao);

    } while(opcao != 3);

    return 0;
}