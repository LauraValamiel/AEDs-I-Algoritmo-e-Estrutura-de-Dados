#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


//Estruturas:
typedef struct{
    char nome[100];
    int codigo;
    char descricao[100];
    float preco;
    int quantidade;
    float peso;
    char substring;

}TProduto;

typedef struct celula{
    TProduto item;
    struct celula* prox;
}TCelula;


void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);


#endif // UTIL_H_INCLUDED
