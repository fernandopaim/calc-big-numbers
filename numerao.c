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
  int countZeros = 0;

  for(int i = num->n_dig - 1; i >= 0; i--) {
    if (num->dig[i] == '0') countZeros ++;
    else break;
  }

  if (countZeros > 0) {
    num->n_dig -= countZeros;
    char *digAux = num->dig;
    numerao_libera_men(num, "numerao_canon", 87);

    num->dig = (char *) m_aloca(num->n_dig * sizeof(char));
    for(int i = 0; i < num->n_dig; i++) {
      num->dig[i] = digAux[i];
    }
  }
}

void numerao_aux_ndig(numerao *num, int ndig)
{
  if (ndig > 0 && ndig > num->n_dig) {
    int oldSize = num->n_dig;
    char *digAux = num->dig;
    numerao_libera_men(num, "numerao_aux_ndig", 101);

    num->dig = (char *) m_aloca(ndig * sizeof(char));
    for(int i = 0; i < num->n_dig; i++) {
      num->dig[i] = digAux[i];
    }

    num->n_dig = ndig;
    for(int i = oldSize; i < num->n_dig; i++) {
      num->dig[i] = '0';
    }
  }
}

void numerao_libera_men(numerao *num, char *funcao, int linha) {
  m_libera_mesmo(num->dig, funcao, linha);
}

int numerao_compara(numerao *n, numerao *m)
{
  numerao n_aux, m_aux;
  numerao_copia(n, &n_aux);
  numerao_copia(m, &m_aux);
  numerao_canon(&n_aux);
  numerao_canon(&m_aux);

  if (n_aux.n_dig > m_aux.n_dig) {
    numerao_libera_men(&n_aux, "numerao_compara", 128);
    numerao_libera_men(&m_aux, "numerao_compara", 129);
    return 1;
  } else if (n_aux.n_dig < m_aux.n_dig) {
    numerao_libera_men(&n_aux, "numerao_compara", 132);
    numerao_libera_men(&m_aux, "numerao_compara", 133);
    return -1;
  } else {
    int flagEqual = 0;

    for (int i = n_aux.n_dig-1; i >= 0; i--) {
      if (n_aux.dig[i] > m_aux.dig[i]) {
        flagEqual = 1;
        break;
      } else if (n_aux.dig[i] < m_aux.dig[i]) {
        flagEqual = -1;
        break;
      }
    }

    numerao_libera_men(&n_aux, "numerao_compara", 148);
    numerao_libera_men(&m_aux, "numerao_compara", 149);

    if (flagEqual) return flagEqual;
  }

  return 0;
}

void numerao_aux_soma(numerao *num, numerao *num2)
{
  int sum = 0, auxSum = 0;

  if (!(num->n_dig == num2->n_dig
      && char2int(num->dig[num->n_dig-1]) + char2int(num2->dig[num2->n_dig-1]) <= 9)) {
    printf("Erro na funcao numerao_aux_soma! Parametros nao atendem ao criterio de soma");
    return;
  }

  for (int i = 0; i < num->n_dig; i++) {
    sum = char2int(num->dig[i]) + char2int(num2->dig[i]) + auxSum;
    if (sum > 9) {
      auxSum = sum / 10;
      sum = sum % 10;
    } else {
      auxSum = 0;
    }
    num->dig[i] = int2char(sum);
  }
}

void numerao_aux_subtrai(numerao *num, numerao *num2)
{
  int sub = 0, auxSub = 0;

  if (!(num->n_dig == num2->n_dig && numerao_compara(num, num2) >= 0)) {
    printf("Erro na funcao numerao_aux_subtrai! Parametros nao atendem ao criterio de soma");
    return;
  }

  for (int i = 0; i < num->n_dig; i++) {
    sub = char2int(num->dig[i]) - char2int(num2->dig[i]) - auxSub;
    if (sub < 0) {
      auxSub = -1;
      printf("%d", auxSub);
      sub = abs(sub);
    } else {
      auxSub = 0;
    }
    num->dig[i] = int2char(sub);
  }
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

