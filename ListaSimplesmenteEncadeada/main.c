/*
*   main.c
*   
*   FUNCOES QUE APRESENTAO OS MENUS
*   E CHAMAM AS FUNCOES AUXILIARES.
*
*   Arquivo com a implementação das funções 
*   que exibem os menus da interface de texto
*   e auxiliam as chamadas das operações
*/
// Protótipos das operacões de Lista
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sLList.h"

// Estrutura  de tipo escolhida
typedef struct _aluno_{
    int matr;
    char nome[30];
    float nota;
}Aluno;

// Função para criar uma coleção e verificar se foi criada com sucesso
SLList *criarLista() {
    
    SLList *c = sllCreate();
    if(c != NULL) {
        printf("\n**lista Criada Com Sucesso**\n");
        return c;
    } 
    return NULL;
}

// Função para imprimir informações do aluno
void imprimeInfo(void *data) {
    Aluno *a = (Aluno *)data;
    if (a != NULL) {
        printf("\n");
        printf("NOME: %s\n", a->nome);
        printf("MATRICULA: %d\n", a->matr);
        printf("NOTA: %.2f\n", a->nota);
        printf("\n");
    } else {
        printf("\n**Nao encontrado**\n");
    }
}

void sllList(SLList *c) {  
    
    if(c != NULL) {
        sllListElements(c, imprimeInfo);
    }   
}


// Funções para comparar tipos (para busca ou remoção)
int cmpMatr(void *a, void *b) {
    Aluno *pa; int *pb;
    pa = (Aluno *) a; 
    pb = (int *) b;
    if(pa->matr == *pb) {
        return TRUE;     
    }else {
        return FALSE;
        
    }
}

int cmpNota(void *a, void *b) {
    Aluno *pa; float *pb;
    pa = (Aluno *) a; 
    pb = (float *) b;
    int x = (int)(pa->nota * 10);
    int y = (int)(*pb * 10);
    if(x == y) {
        return TRUE;     
    }else {
        return FALSE; 
    }
}

int cmpNome(void *a, void *b) {
    Aluno *pa; char *pb;
    pa = (Aluno *) a; 
    pb = (char *) b;
    if(strcmp(pa->nome, pb) == 0) {
        return TRUE;     
    }else {
        return FALSE;
        
    }
}

// Função para inserir alunos na coleção
void insereAlunos(SLList *c) {
    if(c != NULL) {
        int matr;
        char nome[30];
        float nota;  
        printf("Digite Nome: ");
        scanf("%s", nome);
        printf("Digite Matricula: ");
        scanf("%d", &matr);
        printf("Digite Nota: ");
        scanf("%f", &nota);
            
        Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
        aluno->matr = matr;
        aluno->nota = nota;
        strcpy(aluno->nome, nome);
        sllInsertFirst(c, aluno);
        printf("\n**Adicionado Com Sucesso**\n\n");     
    }
}

// Função para buscar por nome e imprimir informações do aluno
void buscarNome(SLList *c) {
    char nome[30];
    scanf("%s",nome);
    Aluno *a = (Aluno *)sllQuery(c, nome, cmpNome);
    imprimeInfo(a);
}

// Função para buscar por matrícula e imprimir informações do aluno
void buscarMatr(SLList *c) {
    int matr;
    scanf("%d", &matr);
    Aluno *a;
    a = (Aluno *)sllQuery(c, &matr, cmpMatr);
    imprimeInfo(a);
}

// Função para buscar por nota e imprimir informações do aluno
void buscarNota(SLList *c) {
    float nota;
    scanf("%f", &nota);
    Aluno *a;
    a = (Aluno *)sllQuery(c, &nota, cmpNota);
    imprimeInfo(a);
}

// Função para escolher critério de busca (nome, matrícula ou nota)
void consultaAluno(SLList *lista) {
    int opcao;
    if(lista != NULL) {
        printf("\n---------------------\n");
        printf("Como Deseja Consultar:\n");
        printf("1 - NOME\n");
        printf("2 - MATRICULA\n");
        printf("3 - NOTA\n");
        printf("\n---------------------\n");
        printf("Escolha Uma Opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: 
                printf("Digite o NOME: ");
                buscarNome(lista);
                break;
            case 2:
                printf("Digite MATRICULA: ");
                buscarMatr(lista);
                break;
            case 3:
                printf("Digite NOTA: ");
                buscarNota(lista);
                break;
            default:
                printf("Opcao Invalida!\n");
        }
    }
}

// Função para buscar e remover aluno (nome, matrícula ou nota)
void removerAluno(SLList *lista) {
    int opcao;
    if(lista != NULL) {
        Aluno *aluno;
        int matr;
        char nome[30];
        float nota;
        printf("\n---------------------\n");
        printf("Como Deseja Remover:\n");
        printf("1 - NOME\n");
        printf("2 - MATRICULA\n");
        printf("3 - NOTA\n");
        printf("\n---------------------\n");
        printf("Escolha Uma Opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:    
                printf("Digite o NOME: ");
                scanf("%s", nome);
                aluno = (Aluno *)sllRemoveSpec(lista, nome, cmpNome);
                if (aluno != NULL) {
                    printf("\nRemovendo: %s matr: %d nota: %.2f\n", aluno->nome, aluno->matr, aluno->nota);
                    printf("\n**Removido**\n");
                } else {
                    printf("\n**Nao Encontrado**\n");
                }
                break;
            case 2:     
                printf("Digite MATRICULA: ");
                scanf("%d", &matr);
                aluno = (Aluno *)sllRemoveSpec(lista, &matr, cmpMatr);
                if (aluno != NULL) {
                    printf("\nRemovendo: %s matr: %d nota: %.2f\n", aluno->nome, aluno->matr, aluno->nota);
                    printf("\n**Removido**\n");;
                } else {
                    printf("\n**Nao Encontrado**\n");
                }
                break;
            case 3:
                printf("Digite NOTA: ");
                scanf("%f", &nota);
                aluno = (Aluno *)sllRemoveSpec(lista, &nota, cmpNota);
                if (aluno != NULL) {
                     printf("\nRemovendo: %s matr: %d nota: %.2f\n", aluno->nome, aluno->matr, aluno->nota);
                    printf("\n**Removido**\n");
                } else {
                    printf("\n**Nao Encontrado**\n");
                }
                break;
            default:
                printf("Opcao Invalida!\n");
        }
    }
}

//Menu de manipulacao da lista e chamada das funcoes
void manipulaList(SLList *lista) {
    int opcao;
    do {
        printf("\n------------------------------------\n");
        printf("1 - Inserir Aluno Na lista\n");
        printf("2 - Remover Aluno Da lista\n");
        printf("3 - Consultar Um Aluno Na lista\n");
        printf("4 - Listar Alunos da lista\n");
        printf("5 - Esvaziar lista\n");
        printf("6 - Destruir lista\n");
        printf("------------------------------------\n");
        printf("Escolha Uma Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            insereAlunos(lista);
            break;
        case 2:
            removerAluno(lista);
            break;
        case 3:
            consultaAluno(lista);
            break;
        case 4:
            sllList(lista);
            break;
        case 5:
            sllEmpty(lista);
            printf("\n**Esvaziando lista...**\n");
            break;
        case 6:
            if(sllDestroy(lista)) {
                printf("\n**lista Destruida**\n");
                opcao = 0;
            }else {
                printf("\n**Esvazie A lista Antes**\n");
            }
            break;
        default:
            printf("Opcao Invalida!\n");
        }

    } while(opcao != 0);

}

int main() {
    printf("BEM VINDO :)\n");
    SLList *lista;
    int opcao;
    do {
        printf("\n---------------------\n");
        printf("1 - Criar Lista\n");
        printf("0 - Sair\n");
        printf("---------------------\n");
        printf("Escolha Uma Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            lista = criarLista();
            if(lista != NULL) {
                manipulaList(lista);
            }else {
                break;
            }  
            break;
        case 0:
            printf("Saindo...");
            break;
        
        default:
            printf("Opcao Invalida!\n");
        }

    } while(opcao != 0);
    return 0;
}