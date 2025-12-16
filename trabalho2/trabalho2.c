#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

/*int vetorPrincipal[TAM];*/

EstruturaAux vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0;
    int idx = 0;

    if(ehPosicaoValida(posicao) != SUCESSO){
        return  POSICAO_INVALIDA;
    }

    idx = posicao -1;

    if(tamanho < 1){
        return TAMANHO_INVALIDO;
    }

    if(vetorPrincipal[idx].dados != NULL){
    return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    vetorPrincipal[idx].dados =  malloc(tamanho * sizeof(int));

    if(vetorPrincipal[idx].dados == NULL){
    return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[idx].tam = tamanho;
    vetorPrincipal[idx].qtdElementos = 0;

    retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int idx = 0;

    if (ehPosicaoValida(posicao) != SUCESSO)
        return  POSICAO_INVALIDA;
  

    else
    {
        idx = posicao - 1;

        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[idx].dados != NULL)
        {
            if (vetorPrincipal[idx].qtdElementos < vetorPrincipal[idx].tam)
            {
                vetorPrincipal[idx].dados[vetorPrincipal[idx].qtdElementos] = valor;
                vetorPrincipal[idx].qtdElementos++;
                return  SUCESSO;
            }
            else
            {
                return  SEM_ESPACO;
            }
        }
        else
        {
            return  SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    if(ehPosicaoValida(posicao) != SUCESSO){
        return POSICAO_INVALIDA;
    }
    int idx = posicao - 1;

    if(vetorPrincipal[idx].dados == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if(vetorPrincipal[idx].qtdElementos == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    vetorPrincipal[idx].qtdElementos--;

    return SUCESSO;
    
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int idx = 0;

    if(ehPosicaoValida(posicao) !=SUCESSO){
        return POSICAO_INVALIDA;
    }
    
    idx =posicao -1;

    if(vetorPrincipal[idx].dados == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    if(vetorPrincipal[idx].qtdElementos == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    for(int i = 0;i < vetorPrincipal[idx].qtdElementos; i++){
        if(vetorPrincipal[idx].dados[i] == valor){
            for(int j = i; j < vetorPrincipal[idx].qtdElementos - 1 ; j++){
                vetorPrincipal[idx].dados[j] = vetorPrincipal[idx].dados[j + 1];
            }
            vetorPrincipal[idx].qtdElementos--;
            return SUCESSO;
        }
    }
    return NUMERO_INEXISTENTE;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/


int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int idx = 0;

    if(ehPosicaoValida(posicao) != SUCESSO){
        return POSICAO_INVALIDA;
    }

    idx = posicao -1;

    if(vetorPrincipal[idx].dados == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    int limite = vetorPrincipal[idx].qtdElementos;
    if (limite > vetorPrincipal[idx].tam) {
    limite = vetorPrincipal[idx].tam;
    }

    for(int i = 0; i < limite; i++){
    vetorAux[i] = vetorPrincipal[idx].dados[i];
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
int idx = 0;
int aux;

if(ehPosicaoValida(posicao)!= SUCESSO){
    return POSICAO_INVALIDA;
}

idx = posicao -1;

if(vetorPrincipal[idx].dados == NULL){
    return SEM_ESTRUTURA_AUXILIAR;
}


int limite = vetorPrincipal[idx].qtdElementos;
if (limite > vetorPrincipal[idx].tam) {
    limite = vetorPrincipal[idx].tam;
}

for(int i = 0; i < limite; i++){
    vetorAux[i] = vetorPrincipal[idx].dados[i];
}


for(int i = 0;i < limite - 1 ;i++){
    for(int j = 0; j < limite - 1;j++){
        if(vetorAux[j]>vetorAux[j+1]){
            aux = vetorAux[j];
            vetorAux[j] = vetorAux[j + 1];
            vetorAux[j + 1] = aux;
        }
    }
}
    
    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int temElemento = 0;
    int count = 0;

    for(int i = 0; i< TAM; i++){
        if(vetorPrincipal[i].dados != NULL && vetorPrincipal[i].qtdElementos > 0){
            temElemento = 1;

            for(int j = 0; j < vetorPrincipal[i].qtdElementos; j++){
            vetorAux[count++] = vetorPrincipal[i].dados[j];
            }
        }
    }

if(!temElemento){
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
}

return SUCESSO;

}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int total =0;
    int aux;
    int retorno;

    retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);
    if(retorno != SUCESSO){
        return retorno;
    }

    for(int i = 0; i < TAM; i++){
        if(vetorPrincipal[i].dados != NULL){
            total += vetorPrincipal[i].qtdElementos;
        }
    }

    for(int i = 0; i < total-1;i++){
        for(int j= 0; j < total - 1 - i; j++){
            if(vetorAux[j] > vetorAux[j + 1]){
                aux = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j+1] = aux;
            }
        }
    }


    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int novoTamanhoTotal;
    int *novoVetor;

    if(ehPosicaoValida(posicao) != SUCESSO){
        return POSICAO_INVALIDA;
    }

    int idx = posicao -1;

    if(vetorPrincipal[idx].dados == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }


    novoTamanhoTotal = vetorPrincipal[idx].tam + novoTamanho;

    if(novoTamanhoTotal < 1){
        return NOVO_TAMANHO_INVALIDO;
    }

    novoVetor = realloc(vetorPrincipal[idx].dados, novoTamanhoTotal * sizeof(int));

    if(novoVetor == NULL){
        return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[idx].dados =novoVetor;
    vetorPrincipal[idx].tam = novoTamanhoTotal;

    if(vetorPrincipal[idx].qtdElementos > novoTamanhoTotal){
        vetorPrincipal[idx].qtdElementos = novoTamanhoTotal;
    }


    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/

int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int idx = 0;

    if(ehPosicaoValida(posicao)!= SUCESSO){
        return POSICAO_INVALIDA;
    }

    idx = posicao -1;

    if(vetorPrincipal[idx].dados == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    /*if(vetorPrincipal[idx]. qtdElementos == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }*/

    return vetorPrincipal[idx].qtdElementos;

}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    No *cabecote, *novo, *fim;
    int temElemento = 0;

    cabecote = malloc(sizeof(No));
    if(cabecote == NULL){
        return NULL;
    }

    cabecote->prox = NULL;
    fim = cabecote;
    for(int i= 0; i < TAM; i++){
        if(vetorPrincipal[i].dados != NULL && vetorPrincipal[i].qtdElementos>0){
            for(int j = 0; j < vetorPrincipal[i].qtdElementos; j++){
                novo = malloc(sizeof(No));
                if(novo == NULL){
                    continue;
                }

                novo->conteudo = vetorPrincipal[i].dados[j];
                novo->prox = NULL;

                fim->prox = novo;
                fim = novo;

                temElemento = 1;
            }

        }
    }

    if(!temElemento){
        free(cabecote);
        return NULL;
    }

    return cabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    No *atual;

    if (inicio == NULL)
        return;

    atual = inicio->prox;

    int i =0;
    while (atual != NULL) {
        vetorAux[i++] = atual->conteudo;
        atual = atual->prox;
    }

}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{

    No *atual, *prox;

    if(inicio == NULL || *inicio == NULL){
        return;
    }

    atual =*inicio;

    while(atual !=NULL){
        prox = atual->prox;
        free(atual);
        atual = prox;

    }

    *inicio = NULL;

}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{

    for(int i = 0; i<TAM;i++){
        vetorPrincipal[i].dados = NULL;
        vetorPrincipal[i].tam = 0;
        vetorPrincipal[i].qtdElementos = 0;
    }


}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    for(int i = 0;i <TAM;i++){
        if(vetorPrincipal[i].dados != NULL){
            free(vetorPrincipal[i].dados);
            vetorPrincipal[i].dados = NULL;
        }
        vetorPrincipal[i].tam = 0;
        vetorPrincipal[i].qtdElementos = 0;
    }


}