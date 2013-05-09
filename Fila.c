#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Fila.h"
#include <time.h>

int FichaComumAtual = 0, FichaPrioritariaAtual = 0; 

int GerarFichas(char Prioridade_) {
    if(Prioridade_ == 'C') {
        FichaComumAtual++;
        return FichaComumAtual;
    } else {
        FichaPrioritariaAtual++;
        return FichaPrioritariaAtual;
    }
}

void CriarFila(tipoFila *Fila_) {
    Fila_ -> inicio = Fila_ -> final = NULL;
    Fila_ -> tamanho = 0;
}


int FilaVazia(tipoFila Fila_) {
    return(Fila_.inicio == NULL && Fila_.final == NULL);
}


int InserirCliente(tipoFila *Fila_, char Nome_[], char Prioridade_) {
    tno *novoCliente;
    novoCliente = (tno*) malloc(sizeof(tno));

    if(novoCliente == NULL) return 0; 

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


void AtenderCliente(tipoFila *Fila_) {
    GravarLogRemover(Fila_);
    tno *auxiliar; 

    if(Fila_ -> inicio == Fila_ -> final) Fila_ -> final = NULL;
    auxiliar = Fila_ -> inicio;
    Fila_ -> inicio = (Fila_ -> inicio) -> Proximo;
    free(auxiliar);
    Fila_->tamanho--;
}


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


