#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

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
