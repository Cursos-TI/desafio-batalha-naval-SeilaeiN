#include <stdio.h>

int main() {
    // Tabuleiro 10x10, inicializado com água (0)
    int tabuleiro[10][10] = {0};

    // Navios com tamanho 3 (valor 3 representa parte do navio)
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};
    int navio_diag1[3] = {3, 3, 3}; 
    int navio_diag2[3] = {3, 3, 3}; 

    // Coordenadas iniciais dos navios
    int linha_h = 2, coluna_h = 4; // Horizontal: linha 3, coluna E
    int linha_v = 5, coluna_v = 1; // Vertical: linha 6, coluna B
    int linha_d1 = 0, coluna_d1 = 0; // Diagonal: começa no canto superior esquerdo
    int linha_d2 = 2, coluna_d2 = 7; // Diagonal: começa mais à direita e embaixo

    // Posiciona navio horizontal
    for (int posicao = 0; posicao < 3; posicao++) {
        if (tabuleiro[linha_h][coluna_h + posicao] == 0)
            tabuleiro[linha_h][coluna_h + posicao] = navio_horizontal[posicao];
    }

    // Posiciona navio vertical
    for (int posicao = 0; posicao < 3; posicao++) {
        if (tabuleiro[linha_v + posicao][coluna_v] == 0)
            tabuleiro[linha_v + posicao][coluna_v] = navio_vertical[posicao];
    }

    // Posiciona navio diagonal (linha e coluna aumentam)
    for (int posicao = 0; posicao < 3; posicao++) {
        int l = linha_d1 + posicao;
        int c = coluna_d1 + posicao;
        if (tabuleiro[l][c] == 0)
            tabuleiro[l][c] = navio_diag1[posicao];
    }

    // Posiciona navio diagonal (linha aumenta, coluna diminui)
    for (int posicao = 0; posicao < 3; posicao++) {
        int l = linha_d2 + posicao;
        int c = coluna_d2 - posicao;
        if (tabuleiro[l][c] == 0)
            tabuleiro[l][c] = navio_diag2[posicao];
    }

    // Exibe cabeçalho
    printf("\n**** BATALHA NAVAL ****\n\n");

    printf("   ");
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    // Imprime o tabuleiro com números das linhas
    for (int linha = 0; linha < 10; linha++) {
        printf("%2d ", linha + 1);
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
