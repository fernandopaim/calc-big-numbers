#include "numerao.h"
#include "mem.h"
#include <stdio.h>
#include <stdbool.h>

void le_numerao(numerao *n) {
  char str[1000];
  printf("Digite um número: ");
  while (true) {
    scanf("%s", str);
    if (!num_ok(str)) {
      printf("Número não reconhecido, tente novamente: ");
      continue;
    }
    if (numerao_de_str(n, str)) break;

    printf("Não foi possível converter o número, tente novamente!");
  }
}

int main() {
  numerao acumulador, aux;
  char str[1000];

  printf("Somador de grandes números\n");

  le_numerao(&acumulador);
  for (;;) {
    char op;
    do {
      printf("qual operação (+, - ou f)? ");
      scanf(" %c", &op);
    } while (op != '+' && op != '-' && op != 'f');

    if (op == 'f') break;

    le_numerao(&aux);
    if (op == '+') {
      numerao_soma(&acumulador, &aux);
    } else {
      numerao_subtrai(&acumulador, &aux);
    }
    numerao_para_str(&acumulador, str);
    printf("Resultado: %s\n", str);
  }
  printf("Ciao\n");
  // se foi feita alguma operacao, o relatorio deve mostrar 2 alocacoes
  // a mais que liberacoes (os dados que estao em acumulador e aux)
  m_relat();
  return 0;
}