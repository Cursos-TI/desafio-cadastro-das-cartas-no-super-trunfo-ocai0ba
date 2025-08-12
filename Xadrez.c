#include <stdio.h>

/*  
    Funções recursivas para Torre, Bispo e Rainha
    Cada função imprime a direção correspondente
    e chama a si mesma até que não restem casas para mover.
*/

// ------------------- TORRE -------------------
void moverTorre(int casas) {
    if (casas <= 0) return;       // condição de parada
    printf("Direita\n");          // ação
    moverTorre(casas - 1);        // chamada recursiva
}

// ------------------- BISPO -------------------
void moverBispo(int casas) {
    if (casas <= 0) return;       // condição de parada

    // loops aninhados: vertical (externo) e horizontal (interno)
    for (int v = 0; v < 1; v++) { // 1 movimento vertical por casa
        for (int h = 0; h < 1; h++) { // 1 movimento horizontal por casa
            printf("Cima Direita\n");
        }
    }

    moverBispo(casas - 1);        // chamada recursiva
}

// ------------------- RAINHA -------------------
void moverRainha(int casas) {
    if (casas <= 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// ------------------- CAVALO -------------------
void moverCavalo(int movimentos) {
    // Movimentos do Cavalo: 2 para cima, 1 para a direita
    // Loops aninhados com múltiplas variáveis e controle de fluxo

    for (int m = 1; m <= movimentos; m++) { // cada iteração = 1 movimento em "L"
        int verticais = 0, horizontais = 0;

        // Movimento vertical (2 casas para cima)
        for (int i = 0; i < 2; i++) {
            printf("Cima\n");
            verticais++;
            if (verticais >= 2) break; // garante no máximo 2 passos verticais
        }

        // Movimento horizontal (1 casa para a direita)
        int j = 0;
        while (j < 2) { // propositalmente maior que 1 para usar continue/break
            j++;
            if (j != 1) continue; // só executa no primeiro passo válido
            printf("Direita\n");
            horizontais++;
            if (horizontais >= 1) break; // garante no máximo 1 passo horizontal
        }
    }
}

// ------------------- MAIN -------------------
int main() {
    // Quantidade de casas para cada peça
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    // Movimentos completos do cavalo em "L"
    int movimentosCavalo = 3; // número de movimentos em L que serão simulados

    // Torre
    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);

    printf("\n");

    // Bispo
    printf("Movimento do Bispo:\n");
    moverBispo(casasBispo);

    printf("\n");

    // Rainha
    printf("Movimento da Rainha:\n");
    moverRainha(casasRainha);

    printf("\n");

    // Cavalo
    printf("Movimento do Cavalo:\n");
    moverCavalo(movimentosCavalo);

    return 0;
}
