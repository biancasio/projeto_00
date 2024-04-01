#include <stdio.h>

int main(){
    int opcao;
    do{
        printf("\nMenu Principal\n");
        printf("1 - Criar Tarefa\n");
        printf("2 - Deletar Tarefa\n");
        printf("3 - Listar Tarefa\n");
        printf("0 - SAIR\n");
        printf("Escolha uma Opção: ");
        scanf("%d", &opcao); //para receber a opção do usuario
        printf("Opção Escolhida: %d\n", opcao);
    } while(opcao); //considera o 0 e sai do loop
}