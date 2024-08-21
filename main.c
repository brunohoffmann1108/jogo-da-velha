#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int tabuleiro[3][3];
int jogador[3];
int alternador_de_jogador = 1;

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

int testa_linha(int linha){
    int soma = 0;
    for(int i = 0; i < 3; i++){
        soma += tabuleiro[linha][i];
    }
    if(soma == 3 || soma == -6){
        return 1;
    }
    return 0;
}

int testa_coluna(int coluna){
int soma = 0;
for(int i = 0; i < 3; i++){
    soma += tabuleiro[i][coluna];
}
if(soma == 3 || soma == -6){
    return 1;
}
return 0;
}

int testa_diagonal_principal(){
    int soma = 0;
    for(int i = 0; i < 3; i++){
        soma += tabuleiro[i][i];
    }
    if(soma == 3 || soma == -6){
        return 1;
    }
    return 0;
}

int testa_diagonal_secundaria(){
    int i = 0;
    int j = 2;
    int soma = 0;
    while(i < 3){
        soma += tabuleiro[i][j];
        i += 1;
        j -= 1;
    }
    if(soma == 3 || soma == -6){
        return 1;
    }
    return 0;
}

int testa_vitoria(int linha, int coluna){
    if(testa_linha(linha)){
        return 1;
    }
    if(testa_coluna(coluna)){
        return 1;
    }
    if(linha != 1 && linha == coluna){
        return testa_diagonal_principal();
    }
    if(linha != 1 && coluna != 1 && linha != coluna){
        return testa_diagonal_secundaria();
    }
    if(linha == 1 && coluna == 1){
        if(testa_diagonal_principal() || testa_diagonal_secundaria()){
            return 1;
        }
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
        if(i == 1){
            printf("jogador %i comeca\n", abs(define_jogador(alternador_de_jogador)));
        }
        recebe_jogada(&linha, &coluna);
        if(valida_jogada(linha, coluna)){
            while(getchar() != '\n');
            continue;
        }
        jogador[2] = define_jogador(alternador_de_jogador);
        jogada(linha - 1, coluna - 1, jogador[2]);
        if(testa_vitoria(linha - 1, coluna - 1)){
            jogador[alternador_de_jogador % 2] += 1; // Jogador[0] = jogador 2 | Jogador[1] = jogador 1
            break;
        }
        i += 1;
        alternador_de_jogador += 1;
    }
    alternador_de_jogador -= 1;
}

int main(){
    int opcao;

    do{
        opcao = 0;
        zera_tabuleiro();
        jogo();
        do{    
            imprime_tabuleiro();
            menu();
            scanf("%i", &opcao);
            while(getchar() != '\n');
            system("cls");
        }while(opcao != 1 && opcao != 2);
    }while(opcao != 2);
    return 0;
}