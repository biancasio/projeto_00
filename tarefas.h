#define TOTAL 100
// este arquivo é somemente o cabeçalho, pois posso incluir
typedef struct {
    int prioridade;
    char descricao [300];
    char categoria [100];
} Tarefa;

// OK é para verificar se deu certo
//Max tarefas é pq chegou no maximo de tarefas...
typedef enum{OK, MAX_TAREFA, SEM_TAREFAS, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER} ERROS;

//tipo novo q retorna os erros, ponteiro aponta para qualquer função que retorna um erro e recerbe um array de tarefa e um ponteiro de inteiro
typedef ERROS (*funcao)(Tarefa[], int*);

ERROS criar(Tarefa tarefas[], int *pos);
ERROS deletar(Tarefa tarefas[], int *pos);
ERROS listar(Tarefa tarefas[], int *pos);
ERROS salvar(Tarefa tarefas[], int *pos);
ERROS carregar(Tarefa tarefas[], int *pos);

void clearBuffer();
