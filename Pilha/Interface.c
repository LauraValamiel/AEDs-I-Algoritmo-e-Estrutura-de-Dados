#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "interface.h"



void MSG_MENU( )
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. EMPILHAR");
    printf("  \n\t2. DESEMPILHAR");
    printf("  \n\t3. PESQUISAR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. SAIR");
    printf("  \n\t6. REVERTER ORDEM DOS PRIMEIROS K ELEMENTOS DA FILA");
    printf("  \n\t7. CONVERTER NUMERO DE NOTACAO DECIMAL");
    printf("  \n\t8. TORRE DE HANOI");
    printf("  \n\t9. SUBSTRING DE PARENTESIS BALANCEADO");
    printf("  \n\t10.PARENTESIS DUPLICADOS");


}

void MENU(TPilha *Pilha){
    TProduto produto;
    int opcao=0;
    int i;
    TCelula *Aux;
    TFila Fila;
    FFVazia(&Fila);
    TPilha PilhaFonte;
    FPVazia(&PilhaFonte);
    TPilha PilhaDest;
    FPVazia(&PilhaDest);
    TPilha PilhaS;
    FPVazia(&PilhaS);
    TPilha PilhaC;
    FPVazia(&PilhaC);
    TPilha PilhaM;
    FPVazia(&PilhaM);

    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                /**
                    Código para opção de menu Empilhar
                */
                LerProduto(&produto);
                Empilhar(produto, Pilha);
                system("PAUSE");
                break;
            case 2:
                /**
                    Código para opção de menu Desempilhar
                */

                Desempilhar(Pilha, &produto);
                printf("Produto desempilhado:\n");
                ImprimirProduto(produto);
                system("PAUSE");
                break;
            case 3:
                /**
                    Código para opção de menu Pesquisar
                */
                LerProduto(&produto);
                if(PesquisarPilha(Pilha, &produto) == 1){
                    printf("Produto encontrado: \n");
                    ImprimirProduto(produto);
                }
                system("PAUSE");
                break;
            case 4:
                /**
                    Código para opção de menu Imprimir
                */
                ImprimirP(Pilha);
                system("PAUSE");
                break;
            case 5:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                system("PAUSE");
                break;
            case 6:
                system("cls");
                int k;
                int aux;
                LerProduto(&produto);
                Enfileirar(produto, &Fila);
                printf("Digite 1 para inserir elementos e 0 para parar: \n");
                scanf("%d", &aux);
                while(aux != 0){
                    LerProduto(&produto);
                    Enfileirar(produto, &Fila);
                    printf("Digite 1 para inserir elementos e 0 para parar: \n");
                    scanf("%d", &aux);

                }

                printf("Digite um valor para k:\n");
                scanf("%d",&k);
                if(k > Fila.tamanho){
                    printf("Valor invalido!!");
                }
                ordemReversa(&Fila, k);
                ImprimirF(Fila);

                system("PAUSE");
                break;
            case 7:
                system("cls");
                int num;
                int base;
                printf("Digite um numero maior que zero: \n");
                scanf("%d", &num);
                printf("Digite a base do numero entre 2 e 9:\n");
                scanf("%d", &base);
                ConverteNumero(num, base, &PilhaC);
                ImprimirOrdem(&PilhaC);
                system("PAUSE");
                break;
            case 8:
                system("cls");
                int n;
                TProduto x1;
                printf("Digite quantos discos a torre de hanoi tera: \n");
                scanf("%d", &n);
                printf("Digite os codigos dos produtos em ordem decrescente para formar a pilha: \n");
                for(i = 0; i < n; i++){
                    scanf("%d", &x1.codigo);
                    Empilhar(x1, &PilhaFonte);
                }
                TorreHanoi(&PilhaFonte, &PilhaDest, n);
                printf("Pilha original:\n");
                ImprimirOrdem(&PilhaFonte);
                printf("Pilha de destino:\n");
                ImprimirOrdem(&PilhaDest);
                system("PAUSE");
                break;
            case 9:
                system("cls");

                Substring(&PilhaS);

                system("PAUSE");
                break;
            case 10:
                system("cls");

                MultiplosParentesis(&PilhaM);

                system("PAUSE");
                break;

            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 5);
}


