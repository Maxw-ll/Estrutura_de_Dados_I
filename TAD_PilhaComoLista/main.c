#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "pilha_lista.h"

#define TRUE 1
#define FALSE 0

//#include "pilha_lista.h"

void imprimeMenu(){
    printf("\n");
    printf("[1]: Criar a Matriz\n");
    printf("[2]: Imprimir a Matriz\n");
    printf("[3]: Iniciar o Preenchimento\n");
    printf("[4]: Finalizar o Programa\n");
    printf("\n");
}

int ***CreateMatriz(int m){
    int ***ma = (int***)malloc(sizeof(int**)*m);
    if(ma != NULL){
        for(int i=0; i<m; i++){
            ma[i] = (int**)malloc(sizeof(int*)*m);
            if(ma[i] == NULL){
                for(int j=i; j>-1; j--){
                    free(ma[j]);
                }
                free(ma);
                ma = NULL;
                break;
            }
        } 
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                ma[i][j] = (int*)malloc(sizeof(int)*3);
                if(ma[i][j] == NULL){
                    for(int k=i; k>-1; k--){
                        for(int l=j; j>-1; j++){
                            free(ma[i][j]);
                        }
                    }
                    free(ma);
                    ma = NULL;
                    break;
                }
            }
        }
        if(ma != NULL){
            for(int i=0; i<m; i++){
                for(int j=0; j<m; j++){
                    ma[i][j][0] = (int)(rand()%10)/5;
                    ma[i][j][1] = i;
                    ma[i][j][2] = j;
                }
            }
        }
        return ma;
    }
    return NULL;
} 

void ImprimeMatriz(int ***ma, int m){
    if(ma != NULL){
        for(int i=0; i<m; i++){
            printf("[");
                for(int j=0; j<m; j++){
                    printf(" %d ", ma[i][j][0]);
                }
             printf("]");
            printf("\n");
            }
    }
    
}

int preencheMatriz(int ***ma, int m, int cor, int cor_change, int *cd){
    if(ma != NULL){ 
        SLList *pilha = SLLCreate(); void *data; int * dado; int d;
            if(pilha != NULL){
               SLLAddNode(pilha, (void*)((ma[cd[0]][cd[1]])));
               data = SLLRemoveNode(pilha);
               while(data != NULL){
                    dado = (int*)data;
                    d = dado[0];
                    if(d == cor_change){  
                                     
                            //EM LINHA E COLUNA ↑ → ↓ ←
                            if(dado[1] > 0){
                                SLLAddNode(pilha, (void*)((ma[dado[1]-1][dado[2]])));
                            }
                            if(dado[2] < m-1){
                                SLLAddNode(pilha, (void*)((ma[dado[1]][dado[2]+1])));
                            }
                            if(dado[1] < m-1){
                                SLLAddNode(pilha, (void*)((ma[dado[1]+1][dado[2]])));
                            }
                            if(dado[2] > 0){
                                SLLAddNode(pilha, (void*)((ma[dado[1]][dado[2]-1])));
                            }
                            dado[0] = cor;
                        }
                        data = SLLRemoveNode(pilha);
                    
                } 
            } return TRUE; 
                        
        } return FALSE;
    } 

int main(){
    srand(time(NULL));
    int *** m;                                                  //Matriz
    int ans, pause = TRUE, ordem;                               //Escolha do Menu, condição de parada e tamanho da Matriz 
    int *cd = (int*)malloc(sizeof(int)*2); int cor, cor_change; //Preenchimento, cor para substituir, cor a ser substituída
    while(pause == TRUE){
        imprimeMenu();
        scanf("%d", &ans);
        printf("\n");
        switch (ans){
            case 1: 
                printf("Digite a ordem da Matriz quadrada que voce quer criar: ");
                scanf("%d", &ordem);
                m = CreateMatriz(ordem); 
                if(m == NULL){
                    printf("Erro ao criar a Matriz\n");
                } else{
                    printf("Matriz criada com Sucesso!\n");
                }
                break;

            case 2: 
                ImprimeMatriz(m,ordem); break;

            case 3: 
                printf("Informe a coordernada cuja cor voce deseja alterar: ");
                scanf("%d %d", &cd[0], &cd[1]);
                if(cd[0] >= 0 && cd[0] < ordem && cd[1] >= 0 && cd[1] < ordem){
                    cor_change = m[cd[0]][cd[1]][0];
                    printf("\nInforme para qual cor voce deseja substituir: ");
                    scanf("%d", &cor);
                    if(preencheMatriz(m, ordem, cor, cor_change, cd) == TRUE){
                        printf("Preenchimento feito com sucesso!\n");
                    } else{
                        printf("O Preenchimento nao conseguiu ser realizado!\n");
                    }            
                } else{
                    printf("Coordenadas Invalidas!\n");
                }
                break;

            case 4: 
                printf("Obrigado por usar o programa de Preencher regioes em Matrizes!");
                pause = FALSE; break;
        }
    }
}