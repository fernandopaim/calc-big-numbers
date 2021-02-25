#ifndef _numerao_h_
#define _numerao_h_

// Tipo de dados e funções para manipular grandes números
//
// Parte do trabalho final de Laboratorio de Programação I
//                                             l12020a, ufsm

#include <stdbool.h>

// O registro usado para armazenar um numerao
// dig deve ser alocado dinamicamente
typedef struct {
  int n_dig;     // quantidade de dígitos atual do numero (mínimo 1)
  char sinal;    // sinal do número '-' ou '+'
  char *dig;     // vetor com n_dig dígitos, cada um entre '0' e '9'
} numerao;

// Parte I

bool num_ok(char *str);
// Recebe uma string, e diz se ela contém um número válido.
// Um número válido é uma sequência de caracteres '0' a '9',
// opcionalmente precedidos de '-' ou '+'.
// Qualquer outro caractere na string caracteriza como não válido.

bool numerao_de_str(numerao *num, char *str);
// inicializa o numerao apontado por `num` para o valor do número um `str`.
// O numerao é considerado não inicializado na entrada da função
// (em especial, o campo `dig` não aponta para uma região de memória
// que deva ser liberada).
// Se `str` contiver um número inválido (conforme num_ok()),
// `num` não deve ser alterado e a função deve retornar `false`.
// Se a inicialização der certo, deve retornar `true`.
// A função deve alocar memória em quantidade necessária para armazenar
// os dígitos.
// Não esqueça que os dígitos são colocados em um numerao em ordem invertida.
// Não esqueça de remover os zeros supérfluos.

void numerao_para_str(numerao *num, char *str);
// Coloca o valor do numerao em num na string str, em formato para impressao.
// Quem chama essa função deve passar em str um ponteiro para uma região de
// memória com capacidade suficiente.

void numerao_copia(numerao *original, numerao *copia);
// copia o numerao `original` para `copia`.
// A estrutura apontada por `copia` não está inicializada.

void numerao_canon(numerao *num);
// altera (se necessário) o numerao apontado por `num` para a representação
// canônica (sem zeros no início).
// Não esqueça que o vetor de digitos deve ser realocado caso o número de
// dígitos seja alterado.

void numerao_aux_ndig(numerao *num, int ndig);
// altera o numerão `num` para que tenha pelo menos `ndig` dígitos,
// acrescentando dígitos '0' se necessário.
// É uma função auxiliar, para facilitar o alinhamento de números para as
// operações de soma e subtração.
// O numerao ficará não canônico caso sejam acrescentados zeros.

int numerao_compara(numerao *n, numerao *m);
// compara os valores de `n` e `m`,
// retorna 1 se `n` é maior, 0 se são iguais e -1 se `m` é maior.

void numerao_aux_soma(numerao *num, numerao *num2);
// altera `num` para conter o resultado da soma dos valores absolutos
// de `num` e `num2`.
// Ignora o sinal dos dois números.
// Na entrada, `num` e `num2` têm o mesmo número de dígitos,
// e esse número é suficiente para conter o resultado da soma.
// Essa é uma função auxiliar para a implementação de soma e subtração e
// não deve ser usada por usuários externos.

void numerao_aux_subtrai(numerao *num, numerao *num2);
// altera `num` para conter o resultado da subtração entre os valores
// absolutos de `num` e `num2`. Ignora o sinal dos dois números.
// Na entrada, `num` e `num2` têm o mesmo número de dígitos e o valor
// absoluto de `num` não é menor que o de `num2`.
// Essa é uma função auxiliar para a implementação de soma e subtração e
// não deve ser usada por usuários externos.

void numerao_soma(numerao *a, numerao *b);
// altera `a` para conter o resultado da soma entre os valores de `a` e `b`.
// O valor de `b` não deve ser alterado.
// O valor que é retornado em `a` deve estar no formato canônico.
// Esta função deve ser implementada verificando os sinais e valores de
// `a` e `b`, escolhendo qual das funções auxiliares usar (soma ou subtração),
// gerando valores como esperados para as funções auxiliares, usando essas
// (e outras) funções auxiliares. Caso seja necessário (e provavelmente será)
// usar variáveis `numerao` auxiliares, não esqueça de liberar a memória
// alocada por elas depois do uso.

void numerao_subtrai(numerao *a, numerao *b);
// como a função anterior, mas calcula `a=a-b`.

void numerao_libera_men(numerao *num, char *funcao, int linha);
// Função adicional criada para liberar a memória usada por numerão


// falta a Parte II


#endif // _numerao_h_
