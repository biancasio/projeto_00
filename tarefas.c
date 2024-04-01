// arquivo que eu posso compilar
#include <stdio.h>
#include <string.h>
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
    //testar se existem tarefas
    if (*pos == 0)
        return SEM_TAREFAS;
    
    //verificar se a tarefa escolhida existe
    int pos_deletar;
    printf("Entre com a Posição da Tarefa a ser Deletada: ");
    scanf("%d", &pos_deletar);
    pos_deletar --; //garantir a posição certa no array
    if(pos_deletar >= *pos || pos_deletar <0)
        return NAO_ENCONTRADO;

    for (int i = pos_deletar; i< *pos; i++){
        tarefas[i].prioridade = tarefas[i+1].prioridade;
        strcpy(tarefas[i].categoria, tarefas[i+1].categoria);
        strcpy(tarefas[i].descricao, tarefas[i+1].descricao);
    }

    *pos = *pos - 1;

    return OK;
}

ERROS listar(Tarefa tarefas[], int *pos){
    if (*pos == 0)
        return SEM_TAREFAS;

    for(int i=0; i<*pos; i++){
        printf("Pos: %d\t", i+1);
        printf("Prioridade: %d\t", tarefas[i].prioridade);
        printf("Categoria: %s\t", tarefas[i].categoria);
        printf("Descrição: %s\n", tarefas[i].descricao);

    }

    return OK;
}

ERROS salvar(Tarefa tarefas[], int *pos){
    FILE *f = fopen("tarefas.bin","wb");
    if (f == NULL)
        return ABRIR;

    int qtd = fwrite(tarefas, TOTAL, sizeof(Tarefa), f);
    if (qtd == 0 ) 
        return ESCREVER;

    qtd = fwrite(pos, 1, sizeof(int), f);
    if (qtd == 0 ) 
        return ESCREVER;

    if(fclose(f))
        return FECHAR;

    return OK;
}

ERROS carregar(Tarefa tarefas[], int *pos){
    FILE *f = fopen("tarefas.bin","rb");
    if (f == NULL)
        return ABRIR;

    int qtd = fread(tarefas, TOTAL, sizeof(Tarefa), f);
    if (qtd == 0 ) 
        return LER;

    qtd = fread(pos, 1, sizeof(int), f);
    if (qtd == 0 ) 
        return LER;

    if(fclose(f))
        return FECHAR;

    return OK;
}


void clearBuffer(){
    int c;
    //lendo um caracter armazendo em c que n é um char mas é um inteiro, ao mesmo tempo compara para ver se é diferente do final do arquivo 
    while ((c = getchar()) != '\n' && c != EOF){}
}