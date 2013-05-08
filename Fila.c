#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Fila.h"
#include <time.h>
/* Função para Gerar as fichas dos cliente baseada em 2 variaveis globais
   onde são chamadas, atualizadas e atribuida ao cliente */
int FichaComumAtual = 0, FichaPrioritariaAtual = 0; // Variaveis Das Fichas
int GerarFichas(char Prioridade_) {
    if(Prioridade_ == 'C') {
        FichaComumAtual++;
        return FichaComumAtual;
    } else {
        FichaPrioritariaAtual++;
        return FichaPrioritariaAtual;
    }
}

//Cria Fila e incrementa um contador "tamanho" para controle
void CriarFila(tipoFila *Fila_) {
    Fila_ -> inicio = Fila_ -> final = NULL;
    Fila_ -> tamanho = 0;
}

//Verifica se a Fila está vazia
int FilaVazia(tipoFila Fila_) {
    return(Fila_.inicio == NULL && Fila_.final == NULL);
}

//Adiciona novo cliente na fila de espera de acordo com sua Prioridade
int InserirCliente(tipoFila *Fila_, char Nome_[], char Prioridade_) {
    tno *novoCliente;
    novoCliente = (tno*) malloc(sizeof(tno));

    if(novoCliente == NULL) return 0; /* Erro: mem¢ria insuficiente */

    novoCliente -> NumeroFicha = GerarFichas(Prioridade_);
    strcpy(novoCliente -> NomeCliente, Nome_);

    novoCliente -> Proximo = NULL;

    if(FilaVazia(*Fila_)) {
        Fila_ -> inicio = novoCliente;
    } else {
        (Fila_->final)->Proximo = novoCliente;
    }

    Fila_ -> final = novoCliente;
    Fila_ -> tamanho++;
    GravarLog(Fila_, "Entrou na Fila");

    return 1;
}

//Exibe os clientes da fila baseado no tamanho da fila guardado em "tamanho"
void ExibirFila(tipoFila *Fila_, char Prioridade_) {
    tno *atual= Fila_->inicio;
    int i;

    if(Prioridade_ == 'C') {
        for(i = 0; i < Fila_ -> tamanho; ++i) {
            printf("C%03d - %s\n",atual->NumeroFicha, atual->NomeCliente);
            atual = atual->Proximo;
        }
    } else {
        for(i = 0; i < Fila_ -> tamanho; ++i) {
            printf("P%03d - %s\n", atual -> NumeroFicha, atual -> NomeCliente);
            atual = atual -> Proximo;
        }
    }
}

//Remove Cliente da Fila de Espera para seu atendimento
void AtenderCliente(tipoFila *Fila_) {
    GravarLogRemover(Fila_);
    tno *auxiliar; // ponteiro para auxiliar a remoção do cliente na fila

    if(Fila_ -> inicio == Fila_ -> final) Fila_ -> final = NULL;
    auxiliar = Fila_ -> inicio;
    Fila_ -> inicio = (Fila_ -> inicio) -> Proximo;
    free(auxiliar);
    Fila_->tamanho--;
}

//Registra a entrada do cliente
int GravarLog(tipoFila *Fila_, char Mensagem_[]) {
    tno *atual = Fila_ -> inicio;

    FILE *log;
    int i;
    time_t tempo;
    char* atualTempo;
    
    
    log = fopen("LOG.TXT","a");

    if(log == NULL) {
        printf("Erro na abertura do arquivo");
        return 0;
    }

    tempo = time(NULL);    
    atualTempo = ctime(&tempo);

    for(i = 0; i < Fila_ -> tamanho; ++i) {
        fprintf(log,"%s %03d %s As: %s\n", atual -> NomeCliente, atual -> NumeroFicha, Mensagem_ ,atualTempo);
        atual = atual -> Proximo;
    }

   fclose(log);
return 0;
}

//Registra a saida do cliente
int GravarLogRemover(tipoFila *Fila_) {
    tno *atual = Fila_ -> inicio;

    time_t tempo;
    char* atualTempo;
    FILE *log;
    int i;
    
    log = fopen("LOG.TXT", "a");

    if (log == NULL) {
        printf("Erro na abertura do arquivo");
        return 0;
    }
    tempo = time(NULL);    
    atualTempo = ctime(&tempo);
    fprintf(log, "%s %03d Atendido As: %s\n", atual -> NomeCliente, atual -> NumeroFicha, atualTempo);
    fclose(log);

    return 1;    
}


