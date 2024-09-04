#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

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

}TProduto;

typedef struct celula{
    TProduto item;
    struct celula* prox;

}TCelula;

typedef struct{
    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;

}TLista;

//Cabeçalho das funções:

void FLVazia(TLista *Lista);

int Vazia(TLista Lista);

void Inserir(TProduto x, TLista *Lista);

TCelula* Pesquisar(TLista Lista, TProduto Item);

void Excluir(TLista *Lista, TProduto *Item);

void Imprimir(TLista Lista);

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

void ExcluirImpar(TLista *Lista);

void Liberar(TLista *Lista);

TLista *Lista2();

void Iguais(TLista *Lista, TLista *Lista2);

void ConcatenaListas(TLista *Lista, TLista *Lista2);

TLista *Lista3();

void DivideLista(TLista *Lista, TLista *Lista2, TLista *Lista3);

void ImprimirDados(TLista *Lista);

void Remover(TLista *Lista);



#endif // LISTA_H_INCLUDED
