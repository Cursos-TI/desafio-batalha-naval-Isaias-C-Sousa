#include <stdio.h>

int main() { int tabuleiro[10][10]; // Matriz 10x10 representando o tabuleiro int i, j;

// Limpa o tabuleiro preenchendo com 0 (água)
for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
        tabuleiro[i][j] = 0;
    }
}

// Posicionamento fixo de navios (cada parte do navio = 3)
// Navio 1 - horizontal (linha 2, colunas 1 a 3)
tabuleiro[2][1] = 3;
tabuleiro[2][2] = 3;
tabuleiro[2][3] = 3;

// Navio 2 - vertical (coluna 5, linhas 6 a 8)
tabuleiro[6][5] = 3;
tabuleiro[7][5] = 3;
tabuleiro[8][5] = 3;

// Navio 3 - diagonal principal (linha = coluna, de 0 a 2)
tabuleiro[0][0] = 3;
tabuleiro[1][1] = 3;
tabuleiro[2][2] = 3;

// Navio 4 - diagonal secundária (linha crescente, coluna decrescente)
tabuleiro[0][9] = 3;
tabuleiro[1][8] = 3;
tabuleiro[2][7] = 3;

// Aplicando habilidades especiais do nível mestre (áreas marcadas com 5)

// 1. Cone (5x5 iniciando em [3][3], formato triangular para baixo)
int origemConeX = 3, origemConeY = 3;
for (i = 0; i < 3; i++) {
    for (j = -i; j <= i; j++) {
        int x = origemConeX + i;
        int y = origemConeY + j;
        if (x >= 0 && x < 10 && y >= 0 && y < 10) {
            tabuleiro[x][y] = 5;
        }
    }
}

// 2. Cruz (linha e coluna com centro em [6][6])
int origemCruz = 6;
for (i = 0; i < 10; i++) {
    tabuleiro[origemCruz][i] = 5; // linha horizontal
    tabuleiro[i][origemCruz] = 5; // coluna vertical
}

// 3. Octaedro (losango centralizado em [5][5], raio 2)
int centroX = 5, centroY = 5, raio = 2;
for (i = -raio; i <= raio; i++) {
    for (j = -raio; j <= raio; j++) {
        if (abs(i) + abs(j) <= raio) {
            int x = centroX + i;
            int y = centroY + j;
            if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                tabuleiro[x][y] = 5;
            }
        }
    }
}

// Exibição do tabuleiro final
printf("Tabuleiro Batalha Naval com Habilidades (0 = água, 3 = navio, 5 = habilidade):\n\n");
for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
        printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
}

return 0;

}