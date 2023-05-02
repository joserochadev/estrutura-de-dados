#include "lista.h" //Implementação da biblioteca de lista
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  type_list *initial_list =
      NULL;                          // Variavel do tipo lista. Deve ser inicializada sempre
  initial_list = list_reserve_mem(); // Reserva de memória para a lista

  int recived_value = 0, break_point = 0; // Variáveis auxiliares

  printf("\n");

  while (recived_value != EOF)
  { // Loop para adiciona valores para a lista
    printf("insert_value: ");
    scanf("%d", &recived_value);               // Valor a ser inserido
    insert_value(initial_list, recived_value); // Inserção do valor recebido

    printf("stop_insertion (1 = stop, anyValue = add): ");
    scanf("%d", &recived_value); // Valor de parada ou continuação

    if (recived_value == 1)
      break; // Condição de parada do loop

    printf("\n");
  }

  show_list_itens(initial_list); // Mostra de valores inseridos

  printf("point_list_break: ");
  scanf("%d", &break_point); // Valor que gera a quebra

  printf("\nbroke ");
  show_list_itens(
      list_point_break(initial_list,
                       break_point)); // Função de quebra e retorno da lista

  free_full_list(initial_list);    // Limpeza dos valores internos da lista
  clean_list_memory(initial_list); // Limpeza da alocação de memória da lista

  printf("programa_encerrado\n"); // Fim do programa
  return 0;
}
