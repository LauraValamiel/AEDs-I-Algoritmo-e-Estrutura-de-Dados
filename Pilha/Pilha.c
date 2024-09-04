#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilha.h"

void FPVazia(TPilha *Pilha){
    Pilha -> topo = (TCelula*)malloc(sizeof(TCelula));
    Pilha -> fundo = Pilha -> topo;
    Pilha -> topo -> prox = NULL;
    Pilha -> tamanho = 0;
}

int PVazia(TPilha Pilha){
    return (Pilha.topo == Pilha.fundo);
}

void Empilhar(TProduto x, TPilha *Pilha){
    TCelula *Aux;
    Aux = (TCelula*)malloc(sizeof(TCelula));
    Pilha -> topo -> item = x;
    Aux -> prox = Pilha -> topo;
    Pilha -> topo = Aux;
    Pilha -> tamanho++;
}

void Desempilhar(TPilha *Pilha, TProduto *Item){
    TCelula *q;
    if(PVazia(*Pilha)){
        printf("Erro: pilha vazia!\n");
        return;
    }

    q = Pilha -> topo;
    Pilha -> topo = q -> prox;
    *Item = q -> prox -> item;
    free(q);
    Pilha -> tamanho--;
}

void ImprimirP(TPilha *Pilha){
    int i;
    int n = Pilha -> tamanho;
    TProduto x;
    TPilha PilhaAux;
    FPVazia(&PilhaAux);
    for(i = 0; i < n; i++){
        Desempilhar(Pilha, &x);
        Empilhar(x, &PilhaAux);
    }
    while(!PVazia(PilhaAux)){
        Desempilhar(&PilhaAux, &x);
        ImprimirProduto(x);
        Empilhar(x, Pilha);
    }
}

int PesquisarPilha(TPilha *Pilha, TProduto *x){
    TPilha Pilha2;
    FPVazia(&Pilha2);
    TProduto aux;
    int flag = 0;

    while(!PVazia(*Pilha)){
        Desempilhar(Pilha, &aux);
        if(strcmp(x -> nome, aux.nome)== 0){
            *x = aux;
            flag = 1;
        }
        Empilhar(aux, &Pilha2);
    }

    while(!PVazia(Pilha2)){
        Desempilhar(&Pilha2, &aux);
        Empilhar(aux, Pilha);
    }
    free(Pilha2.topo);

    if(flag == 1){
        return 1;
    }else{
        x -> codigo = -1;
        return 0;
    }
}

void ordemReversa(TFila *Fila, int k){
    TPilha PilhaAux;
    FPVazia(&PilhaAux);
    TFila FilaAux;
    FFVazia(&FilaAux);
    TProduto x;
    int i;

    for(i = 0; i < k; i++){
        Desenfileirar(Fila, &x);
        Empilhar(x, &PilhaAux);
    }

    while(!FVazia(*Fila)){
         Desenfileirar(Fila, &x);
         Enfileirar(x, &FilaAux);
    }

    while(!PVazia(PilhaAux)){
        Desempilhar(&PilhaAux, &x);
        Enfileirar(x, Fila);
    }

    while(!FVazia(FilaAux)){
        Desenfileirar(&FilaAux, &x);
        Enfileirar(x, Fila);
    }
    free(PilhaAux.topo);
    free(FilaAux.frente);

}

void ConverteNumero(int num, int base, TPilha *PilhaC){
    int resto;
    TProduto r;

    while(num > 0){
        resto = (num%2);
        num = (num/base);
        r.codigo = resto;
        Empilhar(r, PilhaC);
    }
}

void ImprimirOrdem(TPilha *Pilha){
    int i;
    int n = Pilha -> tamanho;
    TProduto x;
    TPilha PilhaAux;
    FPVazia(&PilhaAux);
    for(i = 0; i < n; i++){
        Desempilhar(Pilha, &x);
        ImprimirProduto(x);
        Empilhar(x, &PilhaAux);
    }
    while(!PVazia(PilhaAux)){
        Desempilhar(&PilhaAux, &x);
        Empilhar(x, Pilha);
    }
    free(PilhaAux.topo);
}

void TorreHanoi(TPilha *PilhaFonte, TPilha *PilhaDest, int n){
    TPilha PilhaAux;
    FPVazia(&PilhaAux);
    int i;
    TProduto x1;
    TProduto x2;
    int movit = 0;

    movit = pow(2, n) - 1;

    printf("Sera necessario %d movimentos.\n", movit);

    if(n%2 == 0){
        for(i = 1; i <= movit; i++){
            if((i%3) == 1){
                if(PVazia(PilhaAux)){
                    Desempilhar(PilhaFonte, &x1);
                    Empilhar(x1, &PilhaAux);
                }else if(PVazia(*PilhaFonte)){
                    Desempilhar(&PilhaAux, &x1);
                    Empilhar(x1, PilhaFonte);
                }else{
                    Desempilhar(PilhaFonte, &x1);
                    Desempilhar(&PilhaAux, &x2);
                    if(x1.codigo < x2.codigo){
                        Empilhar(x2, &PilhaAux);
                        Empilhar(x1, &PilhaAux);
                    }else{
                        Empilhar(x1, PilhaFonte);
                        Empilhar(x2, PilhaFonte);
                    }
                }

            }else if(i%3 == 2){
                if(PVazia(*PilhaDest)){
                    Desempilhar(PilhaFonte, &x1);
                    Empilhar(x1, PilhaDest);
                }else if(PVazia(*PilhaFonte)){
                    Desempilhar(PilhaDest, &x1);
                    Empilhar(x1, PilhaFonte);
                    }else{
                    Desempilhar(PilhaFonte, &x1);
                    Desempilhar(PilhaDest, &x2);
                    if(x1.codigo < x2.codigo){
                        Empilhar(x2, PilhaDest);
                        Empilhar(x1, PilhaDest);
                    }else{
                        Empilhar(x1, PilhaFonte);
                        Empilhar(x2, PilhaFonte);
                    }
                    }

            }else if(i%3 == 0){
                if(PVazia(PilhaAux)){
                    Desempilhar(PilhaDest, &x1);
                    Empilhar(x1, &PilhaAux);
                }else if(PVazia(*PilhaDest)){
                    Desempilhar(&PilhaAux, &x1);
                    Empilhar(x1, PilhaDest);
                    }else{
                    Desempilhar(PilhaDest, &x1);
                    Desempilhar(&PilhaAux, &x2);
                    if(x1.codigo < x2.codigo){
                        Empilhar(x2, &PilhaAux);
                        Empilhar(x1, &PilhaAux);
                    }else{
                        Empilhar(x1, PilhaDest);
                        Empilhar(x2, PilhaDest);
                    }
                }
            }
        }
    }else if((n%2) != 0){
        for(i = 1; i <= movit; i++){
            if(i%3 == 1){
                if(PVazia(*PilhaDest)){
                    Desempilhar(PilhaFonte, &x1);
                    Empilhar(x1, PilhaDest);
                }else if(PVazia(*PilhaFonte)){
                    Desempilhar(PilhaDest, &x1);
                    Empilhar(x1, PilhaFonte);
                    }else{
                    Desempilhar(PilhaFonte, &x1);
                    Desempilhar(PilhaDest, &x2);
                    if(x1.codigo < x2.codigo){
                        Empilhar(x2, PilhaDest);
                        Empilhar(x1, PilhaDest);
                    }else{
                        Empilhar(x1, PilhaFonte);
                        Empilhar(x2, PilhaFonte);
                    }
                }

            }else if(i%3 == 2){
                if(PVazia(PilhaAux)){
                    Desempilhar(PilhaFonte, &x1);
                    Empilhar(x1, &PilhaAux);
                }else if(PVazia(*PilhaFonte)){
                    Desempilhar(&PilhaAux, &x1);
                    Empilhar(x1, PilhaFonte);
                    }else{
                    Desempilhar(PilhaFonte, &x1);
                    Desempilhar(&PilhaAux, &x2);
                    if(x1.codigo < x2.codigo){
                        Empilhar(x2, &PilhaAux);
                        Empilhar(x1, &PilhaAux);
                    }else{
                        Empilhar(x1, PilhaFonte);
                        Empilhar(x2, PilhaFonte);
                    }
                }

            }else if(i%3 == 0){
                if(PVazia(*PilhaDest)){
                    Desempilhar(&PilhaAux, &x1);
                    Empilhar(x1, PilhaDest);
                }else if(PVazia(PilhaAux)){
                    Desempilhar(PilhaDest, &x1);
                    Empilhar(x1, &PilhaAux);
                    }else{
                    Desempilhar(&PilhaAux, &x1);
                    Desempilhar(PilhaDest, &x2);
                    if(x1.codigo < x2.codigo){
                        Empilhar(x2, PilhaDest);
                        Empilhar(x1, PilhaDest);
                    }else{
                        Empilhar(x1, &PilhaAux);
                        Empilhar(x2, &PilhaAux);
                    }
                }

            }
        }

    }

    free(PilhaAux.topo);
}

void Substring(TPilha *PilhaS){
    int i;
    TProduto x;
    int saida = 0;
    printf("Digite um numero de abre e fecha parentesis desejado: \n ");
    fflush(stdin);
    fgets(x.nome, 100, stdin);

    for(i = 0; i < 100; i++){
        if(x.nome[i] == '('){
            x.substring = '(';
            Empilhar(x, PilhaS);

           }else if(x.nome[i] == ')' && PilhaS->topo->prox != NULL){
               Desempilhar(PilhaS, &x);
               saida += 2;
           }
    }

    printf("Saida: %d", saida);

}

void MultiplosParentesis(TPilha *PilhaM){
    int i;
    TProduto x;
    int n = PilhaM -> tamanho;
    int cont = 0;
    printf("Digite uma expressao valida: \n ");
    fflush(stdin);
    fgets(x.nome, 100, stdin);

    for(i = 0; i < 100; i++){
        if(x.nome[i] != ')'){
            x.substring = x.nome[i];
            Empilhar(x, PilhaM);

           }else if(x.nome[i] == ')' && PilhaM->topo->prox != NULL){
               for(i = 0; i < n; i++){
                    while (x.nome[i] != '('){
                        Desempilhar(PilhaM, &x);
                        cont++;

                       }
               }

           }
    }

    if(cont < 1){
        printf("A expressao possui %d parentesis duplicados.\n", cont);
    }else{
        printf("A expressao nao possui parentesis duplicados.\n");
    }

}
