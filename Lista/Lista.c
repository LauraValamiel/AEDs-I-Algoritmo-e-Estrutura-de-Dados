#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void FLVazia(TLista *Lista){
    Lista -> primeiro = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> primeiro;
    Lista -> primeiro -> prox = NULL;
    Lista -> tamanho = 0;
}

int Vazia(TLista Lista){
    return (Lista.primeiro == Lista.ultimo);
}

void Inserir(TProduto x, TLista *Lista){
    Lista -> ultimo -> prox = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> ultimo -> prox;
    Lista -> ultimo -> item = x;
    Lista -> ultimo -> prox = NULL;
    Lista -> tamanho++;
}

TCelula* Pesquisar(TLista Lista, TProduto Item){
    TCelula* Aux;
    Aux = Lista.primeiro;
    while(Aux -> prox != NULL){
        if(Aux -> prox -> item.codigo == Item.codigo){
            return Aux;
        }
        Aux = Aux -> prox;
    }
    return NULL;
}

void Excluir(TLista *Lista, TProduto *Item){
    TCelula *Aux1, *Aux2;
    Aux1 = Pesquisar(*Lista, *Item);
    if(Aux1 != NULL){
        Aux2 = Aux1 -> prox;
        Aux1 -> prox = Aux2 -> prox;
        *Item = Aux2 -> item;
        if(Aux1 -> prox == NULL){
            Lista -> ultimo = Aux1;
        }
        free(Aux2);
        Lista -> tamanho--;
    }
}

void Imprimir(TLista Lista){
    TCelula* Aux;
    Aux = Lista.primeiro -> prox;
    while(Aux != NULL){
        printf("%d\n", Aux -> item.codigo);
        printf("Nome: %s\n", Aux -> item.nome);
        printf("Codigo: %d\n", Aux -> item.codigo);
        printf("Descricao: %s\n", Aux -> item.descricao);
        printf("Preco: %f\n", Aux -> item.preco);
        printf("Quantidade: %d\n", Aux -> item.quantidade);
        printf("Peso: %f\n", Aux -> item.peso);
        Aux = Aux -> prox;
    }
}

void LerProduto(TProduto *x){
    printf("Digite o nome do produto: \n");
    fflush(stdin);
    fgets(x -> nome, 100, stdin);

    printf("Digite o codigo do produto: \n");
    fflush(stdin);
    scanf("%d", &x -> codigo);

    printf("Digite a descricao do produto: \n");
    fflush(stdin);
    fgets(x -> descricao, 100, stdin);

    printf("Digite o preco do produto: \n");
    fflush(stdin);
    scanf("%f", &x -> preco);

    printf("Digite a quantidade do produto: \n");
    fflush(stdin);
    scanf("%d", &x -> quantidade);

    printf("Digite o peso do produto: \n");
    fflush(stdin);
    scanf("%f", &x -> peso);

}

void ImprimirProduto(TProduto x){
    printf("Nome: %s\n", x.nome);
    printf("Codigo: %d\n", x.codigo);
    printf("Descricao: %s\n", x.descricao);
    printf("Preco: %f\n", x.preco);
    printf("Quantidade: %d\n", x.quantidade);
    printf("Peso: %f\n", x.peso);

}

void ExcluirImpar(TLista *Lista){
    TCelula *Aux = Lista -> primeiro;
    TProduto Produto;
    while(Aux -> prox != NULL){
       if(Aux -> prox -> item.codigo%2 != 0){
            Produto = Aux -> prox -> item;
            Excluir(Lista, &Produto);

        } else
        Aux = Aux -> prox;
    }

}

//void Liberar(TLista *Lista){
//        TCelula *Aux = Lista -> primeiro;
//        while(Aux -> prox != NULL){
//                if(Aux -> prox == NULL){
//                    Lista -> ultimo = Aux;
//                }
//            Excluir(Lista, &Aux -> prox -> item);
//        }
//        free(Lista);
//    }


void Liberar(TLista *Lista){
    TProduto x;
    while(!Vazia(*Lista)){
        x = Lista -> primeiro -> prox -> item;
        Excluir(Lista, &x);
    }
    free(Lista -> primeiro);
}

void Iguais(TLista *Lista, TLista *Lista2){
    TCelula *aux1;
    TCelula *aux2;
    aux1 = Lista -> primeiro -> prox;
    aux2 = Lista2 -> primeiro -> prox;
    int cont = 0;

    while(aux1 != NULL && aux2 != NULL){//(!Vazia(*Lista) && !Vazia(*Lista2)){
        if(aux1 -> item.codigo == aux2 -> item.codigo){
             cont++;
        }
        aux1 = aux1 -> prox;
        aux2 = aux2 -> prox;
    }
    if(cont == Lista -> tamanho){
        printf("\nSao iguais!");
    }else
        printf("\nNao sao iguais");

}

void ConcatenaListas(TLista *Lista, TLista *Lista2){
    TProduto x;
    while(!Vazia(*Lista2)){
        Inserir(x, Lista);
        Excluir(&Lista2, &x);
    }
    free(Lista2->primeiro);
}

void DivideLista(TLista *Lista, TLista *Lista2, TLista *Lista3){
    int i;
    TProduto x;
    int n = (Lista -> tamanho)/2;
    while(Lista -> tamanho < n){
        Inserir(x, Lista2);
        Excluir(&Lista, &x);
    }
    Lista -> tamanho  = Lista -> tamanho - n;
    while(!Vazia(*Lista)){
        Inserir(x, Lista3);
        Excluir(&Lista, &x);
    }
    free(Lista -> primeiro);
}


void ImprimirDados(TLista *Lista){
    TCelula item;
    int i = 0;
    int p;
    printf("Digite a posicao que deseja imprimir: \n");
    scanf("%d", &p);
    TCelula *Aux;
    Aux = Lista -> primeiro;
    while(Aux -> prox != NULL){
        i++;
        if(i == p){
            ImprimirProduto(Aux->prox->item);
        }
        Aux = Aux -> prox;
    }
    return NULL;

}

void Remover(TLista *Lista){
    TCelula item;
    int i = 0;
    int p;
    printf("Digite a posicao que deseja excluir: \n");
    scanf("%d", &p);
    TCelula *Aux;
    Aux = Lista->primeiro;
    while(Aux -> prox != NULL){
        i++;
        if(i == p){
            Excluir(Lista, &item);
        }
        Aux = Aux -> prox;
    }
    return NULL;


}
/*
TCelula* PesquisarNome(TLista Lista, TProduto Item){
    TCelula* Aux;
    Aux = Lista.primeiro;
    while(Aux -> prox != NULL){
        if(Aux -> prox -> item.nome == Item.nome){
            return Aux;
        }
        Aux = Aux -> prox;
    }
    return Aux;
}

void Atualizar(TLista *Lista, TProduto Item){
    TCelula* Aux;
    Aux = Lista.primeiro
    while(Aux -> prox != NULL){
        i++;
        if(Aux == PesquisarNome(*Lista, Item)){
            Aux = Item;
        }
        Aux = Aux -> prox;
    }
}

void InsereOrdem(TLista *Lista, TProduto Item){
    TCelula *Aux, *Aux2;
    Aux = Lista -> primeiro;
    TProduto Produto;
    while(Aux -> prox != NULL){
        strcmp(Produto.nome, Item.nome);
        if(strcmp(Item.nome, Produto.nome)== -1){
                Aux -> prox = Aux2;
                Aux2 = Aux -> Produto;
                Aux = Item;
        } else
        Aux = Aux -> prox;
    }
}
*/

