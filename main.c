#include <stdio.h>
#include "tarefas.h"

int main(){
    funcao fs[] = {criar, deletar, listar,salvar, carregar};


    Tarefa tarefas[TOTAL];
    // ele começa como lixo de memoria ent so declara pq se tudo der certo somente subscreve
    int pos;
    //retorna as tarefas e a posição do ultimo elemento para forçar p comecar do 0 do array
    ERROS erro = fs[4](tarefas, &pos);
    if (erro != OK)
        pos = 0;

    int opcao;
    do{
        printf("\nMenu Principal\n");
        printf("1 - Criar Tarefa\n");
        printf("2 - Deletar Tarefa\n");
        printf("3 - Listar Tarefa\n");
        printf("0 - SAIR\n");
        printf("Escolha uma Opção: ");
        scanf("%d", &opcao); //para receber a opção do usuario
        opcao --;
        if (opcao > 2)
            printf("Opção Inválida\n");
        else if(opcao >=0)
            fs[opcao](tarefas, &pos);
        else
            printf("Sair... \n");

    } while(opcao >= 0); //considera o 0 e sai do loop
}