#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Fila.h"
#include<time.h>


/*               MAIN                 */

int main(){

    tipoGuiche guicheComum, guichePrioritario;
    tipoFila   filaComum,   filaPrioritaria;
    int i,opcao,quantidadeComum, quantidadePrioritario, removerGuiche,numeroGuiche;    
    char comum='C', prioritario='P', nomeCliente[40], sair;




   
   /* Criação automatica dos Guiches e Filas*/
    CriarGuiche(&guicheComum);
    CriarGuiche(&guichePrioritario);

    CriarFila(&filaComum);
    CriarFila(&filaPrioritaria);
        
    printf("Informe a quantidade de guiches Comuns: ");
    scanf("%d",&quantidadeComum);
    InserirEmQuantidade(&guicheComum,quantidadeComum, comum);
    ExibirGuiches(guicheComum, comum);
    GravarLog(guicheComum,"Inserido", quantidadeComum);
      
    printf("Informe a quantidade de guiches Prioritarios: ");
    scanf("%d",&quantidadePrioritario);
    InserirEmQuantidade(&guichePrioritario,quantidadePrioritario, prioritario);
    ExibirGuiches(guichePrioritario, prioritario);
    GravarLog(guichePrioritario,"Inserido", quantidadePrioritario);

    do
    {
    printf("1- Adicionar Cliente Comum\n2- Adicionar Cliente Prioritario\n3- Atender Cliente Comum\n");
    printf("4- Atender Cliente Prioritario\n5- Remover Caixa Comum\n6- Remover Caixa Prioritario\n0- Sair\n\nOpcao: ");
    fflush(stdin);
    scanf("%d", &opcao);
    
    switch(opcao){
                  case 1:
                       system("cls");
                       printf("Nome do Cliente: ");
                       fflush(stdin);
                       gets(nomeCliente);
                       InserirCliente(&filaComum,nomeCliente, comum);
                       
                       printf("\nFila Comum:\n");
                       ExibirFila(&filaComum, comum);
                       printf("\nFila Prioritaria:\n");
                       ExibirFila(&filaPrioritaria, prioritario);   
                       printf("\n\n");
                       break;                       
                 
                  case 2:
                       system("cls");
                       printf("Nome do Cliente ");
                       fflush(stdin);
                       gets(nomeCliente);
                       InserirCliente(&filaPrioritaria,nomeCliente, prioritario);
                       
                       printf("\nFila Comum:\n");
                       ExibirFila(&filaComum, comum);
                       printf("\nFila Prioritaria:\n");
                       ExibirFila(&filaPrioritaria, prioritario);   
                       printf("\n\n");
                       break;
                  
                  case 3:
                       if(FilaVazia(filaComum)){
                           printf("\nFila Vazia !\n\n");
                           if(!FilaVazia(filaPrioritaria)){
                              printf("Atendendo Fila Prioritaria!\n\n");
                              AtenderCliente(&filaPrioritaria);
                              ExibirFila(&filaPrioritaria, prioritario);
                              }
                          else printf("Nao ha mais Clientes!\n");    
                           break;
                           }
                       else{
                            AtenderCliente(&filaComum);
                            printf("\nFila Comum:\n");
                            ExibirFila(&filaComum, comum);
                            printf("\nFila Prioritaria:\n");
                            ExibirFila(&filaPrioritaria, prioritario);   
                            printf("\n\n");
                       break;
                       }
                  case 4:
                       if(FilaVazia(filaPrioritaria)){
                           printf("\nFila Vazia !\n\n");
                           if(!FilaVazia(filaComum)){
                              printf("Atendendo Fila Comum!\n\n");
                              AtenderCliente(&filaComum);
                              ExibirFila(&filaComum, comum);       
                              }
                          else printf("Nao ha mais Clientes\n\n"); 
                           break;
                           }
                       else{
                           AtenderCliente(&filaPrioritaria);
                           printf("\nFila Comum:\n");
                           ExibirFila(&filaComum, comum);
                           printf("\nFila Prioritaria:\n");
                           ExibirFila(&filaPrioritaria, prioritario);   
                           printf("\n\n");                
                           break;
                       }     
                  case 5:
                          printf("Informe o Guiche a ser Removido: ");
                          scanf("%d",&numeroGuiche);
                          if(!RemoverGuiche(&guicheComum,numeroGuiche)) printf("\n\nGuiche Invalido!\n\n");
                          ExibirGuiches(guicheComum, comum);
                          GravarLog(guicheComum,"Removido",1);
                          break;
                  
                  case 6:
                          printf("Informe o Guiche a ser Removido: ");
                          scanf("%d",&numeroGuiche);
                          if(!RemoverGuiche(&guichePrioritario,numeroGuiche))printf("\n\nGuiche Invalido!\n\n");
                          ExibirGuiches(guichePrioritario, comum);  
                          GravarLog(guichePrioritario,"Removido",1);
                       break;
                       
                       
                  case 0:
                         exit(0);
                  default:
                       exit(0);
                  }
    

    
    
    } while(sair != 's');

    
    
system("PAUSE");
return 0;

}
