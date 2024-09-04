#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"


void FFVazia(TFila *Fila){
 Fila->frente = (TCelula*) malloc(sizeof(TCelula));
 Fila->tras = Fila->frente;
 Fila->frente->prox = NULL;
 Fila->tamanho = 0;
}

int FVazia(TFila Fila){
 return (Fila.frente == Fila.tras);
}

void ExcluirF(TFila *Fila, TProduto *Item){
    int i;
    int n = Fila -> tamanho;
    TProduto x;

    for(i = 0; i < n; i++){
        Desenfileirar(Fila, Item);
        if(x.codigo != Item->codigo){
            Enfileirar(x, &Fila);
        }
    }

}

void LiberarF(TFila *Fila){
    TProduto x;
    while(!FVazia(*Fila)){
        x = Fila -> frente -> prox -> item;
        ExcluirF(Fila, &x);
    }
    free(Fila -> frente);
}

void Enfileirar(TProduto x, TFila *Fila){
 Fila->tras->prox = (TCelula*) malloc(sizeof(TCelula));
 Fila->tras = Fila->tras->prox;
 Fila->tras->item = x;
 Fila->tras->prox = NULL;
 Fila->tamanho++;
}

void Desenfileirar(TFila *Fila, TProduto *Item){
 TCelula* Aux;
 if(!FVazia(*Fila)){
  Aux = Fila->frente->prox;
  Fila->frente->prox = Aux->prox;
  *Item = Aux->item;
  free(Aux);

  if(Fila->frente->prox == NULL){
   Fila->tras = Fila->frente;
  }
  Fila->tamanho--;
 }
}

void ImprimirF(TFila Fila){
    int i;
    int n = Fila.tamanho;
    TProduto x;

    for(i = 0; i < n; i++){
        Desenfileirar(&Fila, &x);
        ImprimirProduto(x);
        Enfileirar(x, &Fila);
    }
}

int PesquisarFila(TFila *Fila, TProduto *x){
    TFila Fila2;
    FFVazia(&Fila2);
    TProduto aux;
    int flag = 0;

    while(!FVazia(*Fila)){
        Desenfileirar(Fila, &aux);
        if(strcmp(x -> nome, aux.nome) == 0){
            *x = aux;
            flag = 1;
        }
        Enfileirar(aux, &Fila2);
    }

    while(!FVazia(Fila2)){
        Desenfileirar(&Fila2, &aux);
        Enfileirar(aux, Fila);
    }
    free(Fila2.frente);

    if(flag == 1){
        return 1;
    }else{
        x -> codigo = -1;
        return 0;
    }
}

int FilasIguais(TFila *Fila, TFila *Fila2){
    int i;
    int z;
    int n = Fila -> tamanho;
    int j = Fila2 -> tamanho;
    TProduto aux;
    TProduto x;
    int cont = 0;

    for(i = 0; i < n; i++){
         Desenfileirar(Fila, &aux);
        for(z = 0; z < j; z++){
            Desenfileirar(Fila2, &x);
            if(x.codigo == aux.codigo){
                cont++;
            }
            Enfileirar(x, Fila2);
        }
        Enfileirar(aux, Fila);
    }

    if(cont == Fila -> tamanho){
        printf("\nSao iguais!");
        return 1;
    }else{
        printf("\nNao sao iguais");
        return 0;
    }
}

void Remover(TFila *Fila, int n){
    int i;
    int t = Fila -> tamanho;
    TProduto aux;

    for(i = 0; i < t; i++){
        Desenfileirar(Fila, &aux);
        if(i != n){
          Enfileirar(aux, Fila);
        }
    }

}

void Intersecao(TFila *Fila, TFila *Fila2, TFila *Fila3){
    TProduto x;
    TProduto x1;
    int i;
    int z;
    int n = Fila -> tamanho;
    int j = Fila2 -> tamanho;

    for(i = 0; i < n; i++){
        Desenfileirar(Fila, &x);
        for(z = 0; z < j; z++){
            Desenfileirar(Fila2, &x1);
            if(x.codigo == x1.codigo){
                Enfileirar(x, Fila3);
            }
            Enfileirar(x1, Fila2);
        }
        Enfileirar(x, Fila);
    }
}

void Diferenca(TFila *Fila, TFila *Fila2, TFila *Fila3){
    TProduto x;
    TProduto x1;
    int i;
    int z;
    int cont = 0;
    int n = Fila -> tamanho;
    int j = Fila2 -> tamanho;

    for(i = 0; i < n; i++){
        Desenfileirar(Fila, &x);
        for(z = 0; z < j; z++){
            Desenfileirar(Fila2, &x1);
            if(x.codigo != x1.codigo){
                cont++;
            }
            Enfileirar(x1, Fila2);
        }
        if(cont == j){
            Enfileirar(x, Fila3);
        }

        cont = 0;
        Enfileirar(x, Fila);
    }
}
