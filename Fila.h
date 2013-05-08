#ifndef FILA
#define FILA

typedef struct no{
    char NomeCliente[40];
    int NumeroFicha;
    struct no* Proximo;
}tno;

typedef struct fila{

    tno* inicio;
    tno* final;
    int  tamanho;
}tipoFila;

void CriarFila(tipoFila *Fila_);
int FilaVazia(tipoFila Fila_);
int InserirCliente(tipoFila *Fila_, char Nome_[], char Prioridade_);
void ExibirFila(tipoFila *Fila_, char Prioridade_);
void AtenderCliente(tipoFila *Fila_);
int GravarLog(tipoFila *Fila_, char Mensagem_[] );
int GravarLogRemover(tipoFila *Fila_);
#endif
