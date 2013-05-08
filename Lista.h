#ifndef LISTA
#define LISTA

typedef int TipoElemento;

typedef struct noo{
    TipoElemento Valor;
    struct noo* Proximo; /* Ponteiro para o próximo nó */
}noGuiche;

typedef noGuiche* tipoGuiche;

int InserirGuiche(tipoGuiche *Guiche, TipoElemento NumeroGuiche);
void CriarGuiche(tipoGuiche *ListaGuiches_);
void InserirEmQuantidade(tipoGuiche* Guiche_, int Quantidade_, char Tipo_);
void ExibirGuiches(tipoGuiche Guiche_, char Tipo_);
int RemoverGuiche(tipoGuiche *Guiche_, int posicao_);
int GerarFichas(char Prioridade_);
int GravarLog(tipoGuiche Guiche_, char Mensagem_[], int quantidade);
#endif
