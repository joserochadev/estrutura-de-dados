#include <stdio.h>
#include <stdlib.h>
// Core List Functions

//
// Geral VARIABLES
//

// Lugar onde armazenará os dados da lista
struct storage_list
{ 
  int current_value;               // valor do item da lista
  struct storage_list *next_value; // Estrutura aninhada onde mostrará o próximo
                                   // valor a ser guardado
};

// Uso de typedef para evitar reescritas maiores. Usado para criar novas listas
typedef struct storage_list type_list;

// Contador do tamanho da lista - pode ser implementado se necessário
int size_list_count = 0;

//
// FUNCTIONS
//

// Garantia que todas as funções poderam se reconhecer
void start_list(type_list *current_list);
int is_next_void(type_list *current_list);
void clean_list_memory(type_list *current_list);
type_list *list_point_break(type_list *current_list, int value_break);
type_list *list_reserve_mem();
void free_full_list(type_list *current_list);
void insert_value(type_list *current_list, int value);
void show_list_itens(type_list *current_list);

// Função para alocar mémoria para a lista criada do tipo type_list
type_list *list_reserve_mem()
{
  type_list *current_list = (type_list *)malloc(
      sizeof(type_list)); // Alocação de memória da da nova lista

  if (!current_list)
  {
    printf("Sem_memoria_disponivel!\n"); // feedback
    exit(1);                             // encerramento forçado do programa
  }
  else
  {
    start_list(current_list);
    return current_list; // Retornando uma lista com memória já alocada
  }
}

// Função para liberar os espaços internos de cada ponteiro
void free_full_list(type_list *current_list)
{

  // Verificação se a lista tem valores mínimos para executar a ação
  if (!is_next_void(current_list))
  {
    type_list *next_position,
        *current_position; // declaração das listas para trocas de valores

    current_position = current_list->next_value;

    while (current_position != NULL)
    {
      next_position =
          current_position
              ->next_value;   // Avanço para camadas mais internas da lista
      free(current_position); // Liberação da memória
      current_position = next_position;
    }
  }
}

// função para limpar a memória de uma determinada lista
void clean_list_memory(type_list *current_list)
{
  free(current_list);           // Liberando a memória alocada
  printf("memória_liberada\n"); // feedback
}

// Função para iniciar a nova lista
void start_list(type_list *current_list)
{
  current_list->next_value = NULL; // Inicia o próximo elemento como o final
  size_list_count = 0;             // contador de elementos da lista
}

// Verificação se a lista está com um próximo valor
int is_next_void(type_list *current_list)
{
  if (current_list->next_value == NULL)
    return 1;
  else
    return 0;
}

void insert_value(type_list *current_list, int value)
{

  type_list *new_item = list_reserve_mem();

  new_item->current_value = value;

  type_list *old_next = current_list->next_value;

  current_list->next_value = new_item;
  new_item->next_value = old_next;

  size_list_count++;
}

void show_list_itens(type_list *current_list)
{
  system("clear"); // Clean prompt

  if (is_next_void(current_list))
  {
    printf("lista_vazia\n\n"); // Verificação se a lista é vazia
  }
  else
  {

    type_list *modular_list; // Lista temporária para armazenamento

    modular_list = current_list->next_value; // Inialização da lista temporária
    printf("list: [");

    // Loop para percorrer todos os valores da lista
    while (modular_list != NULL)
    {
      printf("%d", modular_list->current_value); // Imprime o valor
      modular_list = modular_list->next_value;   // Passa para o próximo valor

      if (modular_list != NULL)
        printf(", "); // Condição simples para impressão de valor estetico
    }
    printf("]\n\n");
  }
}

// Função que quebra a partir do ponto escolhido
type_list *list_point_break(type_list *current_list, int value_break)
{

  type_list *returned_list = NULL;    // Lista temporária para armazenamento
  returned_list = list_reserve_mem(); // Alocação de memória da da nova lista

  // Verificação se é possivel prosseguir
  if (!is_next_void(current_list))
  {

    type_list *modular_list; // Lista temporária para armazenamento

    modular_list = current_list->next_value; // Inialização da lista temporária
    /*printf("list_broke: [");*/

    int turn_on = 0; // Variavel de controle

    // Loop para percorrer todos os valores da lista
    while (modular_list != NULL)
    {

      if (modular_list->current_value == value_break &&
          !is_next_void(modular_list))
      {
        modular_list = modular_list->next_value; // Passa para o próximo valor}
        turn_on = 1;
      }

      if (turn_on)
      {
        insert_value(
            returned_list,
            modular_list->current_value); // Inserção na lista secondaria
      }

      modular_list = modular_list->next_value; // Passa para o próximo valor
    }
  }

  return returned_list; // Retorno da lista com a quebra

  free_full_list(returned_list); // Limpeza da lista auxiliar
  clean_list_memory(returned_list);
}