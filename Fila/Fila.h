#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct item{
 int codigo;
 char nome[80];
 char descricao[200];
 float preco;
 int quantidade;
 float peso;
} TProduto;

typedef struct celula{
 TProduto item;
 struct celula *prox;
} TCelula;

typedef struct fila{
 TCelula *frente;
 TCelula *tras;
 int tamanho;
} TFila;

void FFVazia(TFila *Fila);

int FVazia(TFila Fila);

void ExcluirF(TFila *Fila, TProduto *Item);

void LiberarF(TFila *Fila);

void Enfileirar(TProduto x, TFila *Fila);

void Desenfileirar(TFila *Fila, TProduto *Item);

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

void Imprimir(TFila fila);

int PesquisarFila(TFila *Fila, TProduto *x);

int FilasIguais(TFila *Fila, TFila *Fila2);

void Remover(TFila *Fila, int n);

void Intersecao(TFila *Fila, TFila *Fila2, TFila *Fila3);

void Diferenca(TFila *Fila, TFila *Fila2, TFila *Fila3);


#endif // FILA_H_INCLUDED
