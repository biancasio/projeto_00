// arquivo que eu posso compilar
#include <stdio.h>
#include "tarefas.h"

ERROS criar(Tarefa tarefas[], int *pos){
    //testa para ver se a quantidade de tarefas é maior que o total
    if(*pos >= TOTAL)
        return MAX_TAREFA;
// se n for eu peço para entrar com a prioridade e a categoria
    printf("Entre com a prioridade: ");
    scanf("%d", &tarefas[*pos].prioridade);

    clearBuffer();
    printf("Entre com a categoria: ");
    fgets(tarefas[*pos].categoria, 100, stdin);
    

    printf("Entre com a descrição: ");
    fgets(tarefas[*pos].descricao, 300, stdin);

 // soma 1+1 no valor da categoria
    *pos = *pos + 1;

    return OK;
}

ERROS deletar(Tarefa tarefas[], int *pos){
    printf("Função de Deletar Tarefas\n");
    return OK;
}

ERROS listar(Tarefa tarefas[], int *pos){
    printf("Função de Listar Tarefas\n");
    return OK;
}

ERROS salvar(Tarefa tarefas[], int *pos){
    printf("Função de Salvar Tarefas\n");
    return OK;
}

ERROS carregar(Tarefa tarefas[], int *pos){
    printf("Função de Carregar Tarefas\n");
    return OK;
}


void clearBuffer(){
    int c;
    //lendo um caracter armazendo em c que n é um char mas é um inteiro, ao mesmo tempo compara para ver se é diferente do final do arquivo 
    while ((c = getchar()) != '\n' && c != EOF){}
}