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
    // system("cls");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%i  ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int testa_vitoria(int linha, int coluna){
    if(tabuleiro[linha][0] == (tabuleiro[linha][1] == tabuleiro[linha][2])){
        printf("Linha\n");
        return 1;
    }
    else if(tabuleiro[0][coluna] == (tabuleiro[1][coluna] == tabuleiro[2][coluna])){
        printf("Coluna\n");
        return 1;
    }
    else{
        printf("Nao\n");
        return 0;
    }
}

void jogada(int linha, int coluna, int jogador){
    tabuleiro[linha][coluna] = jogador;
}

void pvp(){
    int i = 1;
    while(i < 10){
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

        jogada(linha - 1, coluna - 1, (i % 2) + 1);
        if(testa_vitoria(linha - 1, coluna - 1)){
            imprime_tabuleiro();
            printf("Jogador %i Venceu\n", (i % 2) + 1);
            break;
        }
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