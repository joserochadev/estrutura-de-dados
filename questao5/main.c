// 5) Dadas duas listas duplamente encadeadas e dinâmicas L1 e L2 de números
// inteiros, implemente a operação UNION, que cria uma terceira lista duplamente
// encadeada L3 com a união entre as duas listas.

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void *Union(type_list *l1, type_list *l2)
{
  type_list *l3;           // cira nova lista
  l3 = list_reserve_mem(); // aloca memoria pra ela

  type_list *current;
  current = l1->next_value;

  // adiciona os items da lista 01 a lista 03
  while (current != NULL)
  {
    insert_value(l3, current->current_value);
    current = current->next_value;
  }

  // adiciona os items da lista 02 a lista 03
  current = l2->next_value;
  while (current != NULL)
  {
    insert_value(l3, current->current_value);
    current = current->next_value;
  }

  show_list_itens(l3);
  // return l3;
}

int main()
{

  type_list *l1, *l2;
  int recived_value = 0;
  char break_loop;

  l1 = list_reserve_mem();
  l2 = list_reserve_mem();

  start_list(l1);
  start_list(l2);

  while (recived_value != EOF)
  {
    printf("Adicionar valor na lista 01: ");
    scanf("%d", &recived_value);
    insert_value(l1, recived_value);

    printf("Adicionar valor na lista 02: ");
    scanf("%d", &recived_value);
    insert_value(l2, recived_value);

    if (recived_value == 0)
    {
      break;
    }
  }

  // show_list_itens(Union(l1, l2));
  printf("lista 01:");
  show_list_itens(l1);

  printf("lista 02:");
  show_list_itens(l2);

  printf("lista 03:");
  Union(l1, l2);

  printf("fim");

  return 0;
}
