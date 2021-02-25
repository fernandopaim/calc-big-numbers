#include "util.h"
#include "numerao.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// char *substr(char str[], int start, int end)
// {
//   int i, j;
//   char *sub;

//   // Verifica valores incompatíveis e
//   // retorna NULL
//   if (start >= end || end > strlen(str))
//   {
//     return NULL;
//   }

//   // Aloca memória para a substring
//   sub = (char *)malloc(sizeof(char) * (end - start + 1));

//   // Copia a substring para a variável
//   for (i = start, j = 0; i < end; i++, j++)
//   {
//     sub[j] = str[i];
//   }

//   sub[j] = '\0';

//   return &sub;
// }

int char2int(char c) {
  int i = c - '0';

  if(i < 0 || i > 9) return -1;

  return i;
}

/**
 * OBS: Not work with negative numbers
 */
char int2char(int n) {
  if(n > 0 && n < 9)
    return n + '0';

  return abs(n) + '0';
}

void printBigNumber(numerao *num) {
  printf("\nNúmero de dígitos: %d\n", num->n_dig);
  printf("Sinal: %c\n", num->sinal);
  printf("Número: ");
  for(int i = num->n_dig - 1; i >= 0 ; i--) {
    printf("%c", num->dig[i]);
  }
  printf("\n");
}