#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    int altura;
    struct No* esquerda;
    struct No* direita;
} No;

No* inserirNo(No* raiz, int valor);
int atualizaAltura(No* raiz);
void imprimirEmOrdem(No* raiz);
void imprimirPreOrdem(No* raiz);
void imprimirPosOrdem(No* raiz);
void imprimirArvore(No* raiz);

int main() {
    No* raiz = NULL;
    raiz = inserirNo(raiz, 15);
    raiz = inserirNo(raiz, 11);
    raiz = inserirNo(raiz, 19);
    raiz = inserirNo(raiz, 8);
    raiz = inserirNo(raiz, 9);
    raiz = inserirNo(raiz, 7);
    raiz = inserirNo(raiz, 13);
    raiz = inserirNo(raiz, 12);
    raiz = inserirNo(raiz, 14);
    raiz = inserirNo(raiz, 17);
    raiz = inserirNo(raiz, 16);
    raiz = inserirNo(raiz, 18);
    raiz = inserirNo(raiz, 40);
    raiz = inserirNo(raiz, 35);
    raiz = inserirNo(raiz, 42);

    printf("Altura da Árvore: %d\n", raiz->altura);
    printf("Em Ordem:\n");
    imprimirEmOrdem(raiz);
    printf("Pre Ordem:\n");
    imprimirPreOrdem(raiz);
    printf("Pos Ordem:\n");
    imprimirPosOrdem(raiz);
    imprimirArvore(raiz);
    
    return 0;
}

No* inserirNo(No* raiz, int valor) {
    if (raiz == NULL) {
        raiz = (No*)malloc(sizeof(No));
        raiz->valor = valor;
        raiz->altura = 0;
        raiz->esquerda = NULL;
        raiz->direita = NULL;
    } else if (valor < raiz->valor) {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserirNo(raiz->direita, valor);
    }
    atualizaAltura(raiz);
    return raiz;
}

int atualizaAltura(No* raiz) {
    if (raiz == NULL) return -1;

    int alturaEsquerda = (raiz->esquerda != NULL) ? raiz->esquerda->altura : -1;
    int alturaDireita = (raiz->direita != NULL) ? raiz->direita->altura : -1;

    raiz->altura = (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
    return raiz->altura;
}

void imprimirEmOrdem(No* raiz) {
    if (raiz == NULL) return;
    imprimirEmOrdem(raiz->esquerda);
    printf("%d\n", raiz->valor);
    imprimirEmOrdem(raiz->direita);
}

void imprimirPreOrdem(No* raiz) {
    if (raiz == NULL) return;
    printf("%d\n", raiz->valor);
    imprimirPreOrdem(raiz->esquerda);
    imprimirPreOrdem(raiz->direita);
}

void imprimirPosOrdem(No* raiz) {
    if (raiz == NULL) return;
    imprimirPosOrdem(raiz->esquerda);
    imprimirPosOrdem(raiz->direita);
    printf("%d\n", raiz->valor);
}

void imprimirArvore(No* raiz) {
    if (raiz == NULL) return;

    printf("       %03d\n", raiz->valor);
    if (raiz->esquerda != NULL && raiz->direita != NULL) {
        printf("      /   \\ \n");
        printf("    %03d    %03d\n", raiz->esquerda->valor, raiz->direita->valor);
    } else if (raiz->esquerda != NULL) {
        printf("      /   \n");
        printf("    %03d\n", raiz->esquerda->valor);
    } else if (raiz->direita != NULL) {
        printf("          \\ \n");
        printf("           %03d\n", raiz->direita->valor);
    }
}
