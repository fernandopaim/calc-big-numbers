// Implementação das funções de manipulação de números grandes
//
// Parte do trabalho final de Laboratorio de Programação I
//                                             l12020a, ufsm

#include "numerao.h"
#include "mem.h"
#include "util.h"
#include <stdio.h> // @TODO: remover depois dos testes
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool num_ok(char *str)
{
  // Se string vazia
  if(!strlen(str)) return false;

  // Se primeiro caracter inválido
  if(str[0] != '+' && str[0] != '-' && char2int(str[0]) == -1) return false;

  // Se somente 1 caracter e este inválido
  if (strlen(str) == 1 && char2int(str[0]) == -1) return false;

  // Se mais de 1 caracter e estes inválidos
  if (strlen(str) > 1) {
    for(int i = 1; i < strlen(str); i++) {
      if (char2int(str[i]) == -1) return false;
    }
  }

  return true;
}

bool numerao_de_str(numerao *num, char *str)
{
  if (!num_ok(str)) return false;

  num->sinal = '+';
  if (str[0] == '+' || str[0] == '-') {
    if (str[0] == '-') num->sinal = '-';
    str++;
  }

  num->n_dig = strlen(str);

  num->dig = (char *) m_aloca(strlen(str) * sizeof(char));

  for(int i = num->n_dig - 1; i >= 0; i--) {
    num->dig[num->n_dig - i - 1] = str[i];
  }

  return true;
}

void numerao_para_str(numerao *num, char *str)
{
  str[0] = num->sinal;
  for(int i = 0; i < num->n_dig; i++) {
    str[i+1] = num->dig[num->n_dig - i - 1];
  }
  str[num->n_dig+1] = '\0';
}

void numerao_copia(numerao *original, numerao *copia)
{
  copia->sinal = original->sinal;
  copia->n_dig = original->n_dig;
  copia->dig = (char *) m_aloca(original->n_dig * sizeof(char));
  for(int i = 0; i < original->n_dig; i++) {
    copia->dig[i] = original->dig[i];
  }
}

void numerao_canon(numerao *num)
{
  // ...
}

void numerao_aux_ndig(numerao *num, int ndig)
{
  // ...
}

int numerao_compara(numerao *n, numerao *m)
{
  // ...
  return 0; // ou 1 ou -1
}

void numerao_aux_soma(numerao *num, numerao *num2)
{
  // ...
}

void numerao_aux_subtrai(numerao *num, numerao *num2)
{
  // ...
}

void numerao_soma(numerao *a, numerao *b)
{
  // ...
}

void numerao_subtrai(numerao *a, numerao *b)
{
  // ...
}


// falta a Parte II

