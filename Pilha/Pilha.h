#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "util.h"

typedef struct{
    TCelula *fundo;
    TCelula *topo;
    int tamanho;
}TPilha;



//Cabeçalho das funções:

void FPVazia(TPilha *Pilha);

int PVazia(TPilha Pilha);

void Empilhar(TProduto x, TPilha *Pilha);

void Desempilhar(TPilha *Pilha, TProduto *Item);

void ImprimirP(TPilha *Pilha);

int PesquisarPilha(TPilha *Pilha, TProduto *x);

void OrdemReversa(TFila *Pilha, int k);

void ConverteNumero(int num,int base, TPilha *PilhaC);

void ImprimirOrdem(TPilha *Pilha);

void TorreHanoi(TPilha *Pilha, TPilha *PilhaDest, int n);

void Substring(TPilha *PilhaS);

void MultiplosParentesis(TPilha *PilhaM);

#endif // PILHA_H_INCLUDED
