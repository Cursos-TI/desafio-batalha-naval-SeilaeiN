#include <stdio.h>
#include <stdlib.h>

// Função para aplicar uma matriz de habilidade no tabuleiro
void aplicar_habilidade(int tabuleiro[10][10], int habilidade[5][5], int linha_origem, int coluna_origem, int tamanho) {
    int centro = tamanho / 2;

    for (int linha_hab = 0; linha_hab < tamanho; linha_hab++) {
        for (int coluna_hab = 0; coluna_hab < tamanho; coluna_hab++) {
            if (habilidade[linha_hab][coluna_hab] == 1) {
                int linha_tab = linha_origem + (linha_hab - centro);
                int coluna_tab = coluna_origem + (coluna_hab - centro);

                if (linha_tab >= 0 && linha_tab < 10 && coluna_tab >= 0 && coluna_tab < 10 && tabuleiro[linha_tab][coluna_tab] == 0) {
                    tabuleiro[linha_tab][coluna_tab] = 5; // Marca a área afetada
                }
            }
        }
    }
}

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

    // Criação das matrizes de habilidade (5x5)
    int tamanho = 5;
    int centro = tamanho / 2;

    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Preenche matriz em forma de cone
    for (int linha_hab = 0; linha_hab < tamanho; linha_hab++) {
        for (int coluna_hab = 0; coluna_hab < tamanho; coluna_hab++) {
            if (coluna_hab >= centro - linha_hab && coluna_hab <= centro + linha_hab && linha_hab <= centro)
                cone[linha_hab][coluna_hab] = 1;
        }
    }

    // Preenche matriz em forma de cruz
    for (int linha_hab = 0; linha_hab < tamanho; linha_hab++) {
        cruz[linha_hab][centro] = 1;
        cruz[centro][linha_hab] = 1;
    }

    // Preenche matriz em forma de octaedro (losango)
    for (int linha_hab = 0; linha_hab < tamanho; linha_hab++) {
        for (int coluna_hab = 0; coluna_hab < tamanho; coluna_hab++) {
            if (abs(linha_hab - centro) + abs(coluna_hab - centro) <= centro)
                octaedro[linha_hab][coluna_hab] = 1;
        }
    }

    // Aplica habilidades em posições fixas do tabuleiro
    aplicar_habilidade(tabuleiro, cone, 7, 2, tamanho);      // Cone em (8, C)
    aplicar_habilidade(tabuleiro, cruz, 5, 5, tamanho);      // Cruz em (6, F)
    aplicar_habilidade(tabuleiro, octaedro, 1, 7, tamanho);  // Octaedro em (2, H)

    // Exibe cabeçalho
    printf("\n**** BATALHA NAVAL - HABILIDADES ESPECIAIS ****\n\n");

    printf("   ");
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    // Imprime o tabuleiro com símbolos visuais
    for (int linha = 0; linha < 10; linha++) {
        printf("%2d ", linha + 1);
        for (int coluna = 0; coluna < 10; coluna++) {
            if (tabuleiro[linha][coluna] == 0)
                printf("0 "); // Água
            else if (tabuleiro[linha][coluna] == 3)
                printf("3 "); // Navio
            else if (tabuleiro[linha][coluna] == 5)
                printf("5 "); // Área afetada por habilidade
            else
                printf("? "); // Outro valor (caso inesperado)
        }
        printf("\n");
    }

    return 0;
}

