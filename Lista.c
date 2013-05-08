#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Lista.h"
#include<time.h>

//Cria a lista de guiches
void CriarGuiche(tipoGuiche *ListaGuiches_) {
    *ListaGuiches_ = NULL;
}

 // Grava o log do estado do guiche
int GravarLog(tipoGuiche Guiche_, char Mensagem_[], int quantidade) {
    
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
    
    for(i=0; i<=quantidade; i++){
       while(Guiche_ != NULL) {
            fprintf(log,"Caixa %02d %s As: %s\n", Guiche_ -> Valor, Mensagem_ ,atualTempo);       
            Guiche_ = Guiche_ -> Proximo;
            }
       }     
   fclose(log);
return 0;
}



//Adiciona um novo guiche de acordo com seu tipo o deixando pronto para atendimento
int InserirGuiche(tipoGuiche *Guiche, TipoElemento NumeroGuiche) {
    tipoGuiche atual_, anterior_, novo_;

    novo_ = (tipoGuiche) malloc(sizeof(noGuiche));

    if(novo_ == NULL) return 0; // Memória insuficiente !

    novo_->Valor = NumeroGuiche;
    novo_->Proximo = NULL;
    anterior_ = NULL;
    atual_ = *Guiche;

    while(atual_ != NULL && NumeroGuiche >= atual_ -> Valor) {
        if(atual_ -> Valor == NumeroGuiche) return 0; /* Valor já existente ! */

        anterior_ = atual_;
        atual_ = atual_ -> Proximo;
    }

    if(anterior_ == NULL) {
        novo_ -> Proximo = *Guiche;
        *Guiche = novo_;
    } else {
        anterior_ -> Proximo = novo_;
        novo_ -> Proximo = atual_;
    }
    
    return 1;
}

//Insere Guiches em Massa
void InserirEmQuantidade(tipoGuiche* Guiche_, int Quantidade_, char Tipo_) {
    int i;

    if(Tipo_=='C') {
        for(i = 0; i < Quantidade_; i++) {
            InserirGuiche(Guiche_, i+1);
            }
            
    } else {
        for(i = 0; i < Quantidade_; i++) {
            InserirGuiche(Guiche_, i+1);
            
            }
    }
}

//Esxibe a Lista de Guiches
void ExibirGuiches(tipoGuiche Guiche_, char Tipo_) {
    if(Tipo_ == 'C') {
        while(Guiche_ != NULL) {
            printf("Caixa Comum %02d\n", Guiche_ -> Valor);
            Guiche_ = Guiche_ -> Proximo;
        }

    printf("\n\n");
    } else {
        while (Guiche_ != NULL) {
            printf("Caixa Prioritario %02d\n", Guiche_ -> Valor);
            Guiche_ = Guiche_ -> Proximo;
        }

        printf("\n\n");
    }
}

//Remove Guiche apartir de seu número 
int RemoverGuiche(tipoGuiche *Guiche_, int posicao_) {
    tipoGuiche anterior_, proximo_;
    int iterador = 1;

    proximo_ = *Guiche_;

    while((iterador <= posicao_ - 1) && (proximo_ != NULL)) {
        anterior_ = proximo_;
        proximo_  = proximo_ -> Proximo;
        iterador++;
    }

    if(proximo_ == NULL) return 0; /* Posição inválida */

    if(posicao_ == 1) {
        *Guiche_ = proximo_ -> Proximo;
    } else {
       anterior_ -> Proximo = proximo_ -> Proximo;
       free(proximo_);
    }
    return(1);
}

