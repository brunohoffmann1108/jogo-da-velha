#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int tabuleiro[3][3];
int jogador[3];

void menu(){
    printf("1. Jogar novamente\n");
    printf("2. Sair\n");
    printf("Escolha: ");
}

void zera_tabuleiro(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = 0;
        }
    }
}

void imprime_tabuleiro(){
    system("cls");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tabuleiro[i][j] == 1){
                printf("  X  ");
            }
            else if(tabuleiro[i][j] == -2){
                printf("  O  ");
            }
            else{
                printf("     ");
            }
            if(j < 2){
                printf("|");
            }
        }
        printf("\n");
    }
    printf("\n      %i x %i\n\n", jogador[1], jogador[0]);
}

int testa_vitoria(int linha, int coluna){
    if(tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
        return 1;
    }
    else if(tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
        return 1;
    }
    else if((linha == coluna && linha == 1) && ((tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) || (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]))){
        return 1;
    }
    else if((linha == coluna && linha != 1) && (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])){
        return 1;
    }   
    else if((linha != coluna && linha != 1 && coluna != 1) && (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])){
        return 1;
    }
    return 0;
}

void recebe_jogada(int *linha, int *coluna){
    *linha = 0;
    *coluna = 0;
    printf("Jogada (linha e coluna): ");
    scanf("%i", linha);    
    scanf("%i", coluna);

}

int valida_jogada(int linha, int coluna){
    // Jogada com número inválido.
    if(linha > 3 || linha < 1 || coluna > 3 || coluna < 1 || isalpha(linha) || isalpha(coluna)){
        return 1;
    }
    // Jogada em posição já ocupada.
    else if(tabuleiro[linha - 1][coluna - 1] != 0){
        return 1;
    }
    return 0;
}

int define_jogador(int iterador){
    if(iterador % 2 == 0){
        return -2;
    }
    else{
        return 1;
    }
}

void jogada(int linha, int coluna, int jogador){
    tabuleiro[linha][coluna] = jogador;
}

void jogo(){
    int linha;
    int coluna;
    int i = 1;
    while(i < 10){
        imprime_tabuleiro();
        recebe_jogada(&linha, &coluna);
        if(valida_jogada(linha, coluna)){
            while(getchar() != '\n');
            continue;
        }
        jogador[2] = define_jogador(i);
        jogada(linha - 1, coluna - 1, jogador[2]);
        if(testa_vitoria(linha - 1, coluna - 1)){
            jogador[i % 2] += 1;
            imprime_tabuleiro();
            printf("Jogador %i Venceu\n", abs(jogador[2]));
            break;
        }
        i += 1;
    }
}

int main(){
    int opcao;
    do{
        opcao = 0;
        zera_tabuleiro();
        jogo();
        while(opcao != 1 && opcao != 2){
            menu();
            scanf("%i", &opcao);
            while(getchar() != '\n'); // Limpa buffer caso seja um caractere.
            system("cls");
        }
    } while(opcao != 2);
    return 0;
}