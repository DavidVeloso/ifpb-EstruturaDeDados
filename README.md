#Projeto da disciplina de Estrutura de Dados em C

Curso de Sistemas para Intenet - IFPB

#Descrição


Considere uma empresa que possui vários guichês para o atendimento de seus clientes. Existirão duas filas: uma para os Clientes Comuns e outra para os Clientes Prioritários. Cada cliente que chega informa o seu nome, sua condição (Comum ou Prioritário) e fica aguardando em uma das filas. Nesse instante, o cliente recebe um código de atendimento, do tipo Cxxx ou Pxxx (C para cliente comum, P para prioritário e xxx é um número sequencial incrementado a cada novo cliente).

Os guichês, um a cada vez, podem fazer a chamada do próximo cliente da fila, iniciando então o seu atendimento. Os guichês podem ser do tipo Comum ou Prioritário e devem chamar os clientes respectivos, exceto no caso da fila de clientes prioritários estiver vazia então um guichê Prioritário pode chamar um cliente Comum.

Deseja-se um programa em C para controlar o atendimento nesses guichês.

O programa deve mostrar, a todo instante, a situação atual dos guichês e das filas. Deve também mostrar um menu contendo opções para a chegada de um novo cliente, para o atendimento de um cliente da fila e para abertura/fechamento de um guichê.

Observações:

- Os guichês deverão ser representados por duas Listas Ordenadas, uma para Clientes Comuns e outra para Clientes prioritários. Cada uma delas irá armazenar, para cada guichê, o número do guichê, o código do atendimento e o nome do cliente.
- Deverão ser criadas duas bibliotecas: uma com o TAD Lista Ordenada e outra com o TAD Fila, ambas com implementação encadeada.
- Todas as operações deve ter seu momento (data e hora) registrado. Fica a cargo da equipe pesquisar como manipular a data e hora do sistema em C.
- Ao ser finalizado, o programa deve ter gerado arquivo(s) de log (histórico de ocorrências) contendo o registro temporal de todas o movimento (abertura/fechamento de guichês e atendimentos).