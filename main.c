#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int tabuleiro[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

void menu(){
    printf("=================================\n");
    printf("1. Jogador contra jogador\n");
    printf("2. Jogador contra computador\n");
    printf("3. Sair\n");
    printf("Escolha: ");
}

void imprime_tabuleiro(){
    system("cls");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%i  ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void jogada(int linha, int coluna, int jogador){
    tabuleiro[linha - 1][coluna - 1] = jogador;
}

void pvp(){
    int i = 1;
    while(1){
        imprime_tabuleiro();
        int linha = 0;
        int coluna = 0;
        printf("Jogada (linha e coluna): ");
        scanf("%i", &linha);    
        scanf("%i", &coluna);

        if(linha > 3 || linha < 1 || coluna > 3 || coluna < 1 || isalpha(linha) || isalpha(coluna) || tabuleiro[linha - 1][coluna - 1] != 0){
            while(getchar() != '\n');
            continue;
        }

        jogada(linha, coluna, (i % 2) + 1);
        i += 1;
    }
}


int main(){
    int opcao = 0;
    do{
        menu();
        scanf("%i", &opcao);
        while(getchar() != '\n');
        system("cls");
        if(opcao == 1){
            pvp();
        }
        else if(opcao == 2){

        }
        else if(opcao != 3){
            printf("Opcao invalida.\n");
        }

    } while(opcao != 3);

    return 0;
}