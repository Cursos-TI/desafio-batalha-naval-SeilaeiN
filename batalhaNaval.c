#include <stdio.h>

int main() {
    // Tabuleiro 10x10, inicializado água com (0)
    int tabuleiro[10][10] = {0};

    // Navios com tamanho 3
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // Coordenadas dos navios / - _v = vertical e _h = horizontal
    
    int linha_h = 2, coluna_h = 4; // início do navio horizontal (linha 3, coluna E)
    int linha_v = 5, coluna_v = 1; // início do navio vertical (linha 6, coluna B)

    // Posiciona navio horizontal no tabuleiro - _v = vertical e _h = horizontal
    for (int posicao = 0; posicao  < 3; posicao++) {
        tabuleiro[linha_h][coluna_h + posicao] = navio_horizontal[posicao];
    }

    // Posiciona navio vertical no tabuleiro - _v = vertical e _h = horizontal
    for (int posicao = 0; posicao < 3; posicao++) {
        tabuleiro[linha_v + posicao][coluna_v] = navio_vertical[posicao];
    }
    printf  ("\n");
    printf ("**** BATALHA NAVAL ****\n");
    printf  ("\n");
    
    // Imprime o nome das colunas
    
    printf("   "); // alinhamento números das linhas
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    // Imprime o tabuleiro com números das linhas
    
    for (int linha = 0; linha < 10; linha++) {
        printf("%2d ", linha + 1); // Números das linhas (1 a 10) alinhados
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}


