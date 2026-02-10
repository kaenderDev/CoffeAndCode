#include "doubly_linkedlist.h"

static DNode *create_dnode(void *value, size_t element_size)
{ // cria novo nó
  DNode *node = malloc(sizeof(DNode));
  node->data = malloc(element_size);
  memcpy(node->data, value, element_size);
  node->prev = NULL;
  node->next = NULL;
  return node;
}

DoublyLinkedList dlist_create(size_t element_size)
{ // cria lista vazia
  DoublyLinkedList list;
  list.head = NULL;
  list.tail = NULL;
  list.element_size = element_size;
  list.size = 0;
  return list;
}

void dlist_push_front(DoublyLinkedList *list, void *value)
{ // insere no inicio
  DNode *node = create_dnode(value, list->element_size);

  node->next = list->head;

  if (list->head != NULL)
    list->head->prev = node;
  else
    list->tail = node;

  list->head = node;
  list->size++;
}

void dlist_push_back(DoublyLinkedList *list, void *value)
{ // insere no fim
  DNode *node = create_dnode(value, list->element_size);

  node->prev = list->tail;

  if (list->tail != NULL)
    list->tail->next = node;
  else
    list->head = node;

  list->tail = node;
  list->size++;
}

void *dlist_get_ptr(DoublyLinkedList *list, size_t index) // retorna ponteiro do indice
{
  if (index >= list->size)
    return NULL;

  DNode *current;

  // otimização: decide de qual lado percorrer
  if (index < list->size / 2)
  {
    current = list->head;
    for (size_t i = 0; i < index; i++)
      current = current->next;
  }
  else
  {
    current = list->tail;
    for (size_t i = list->size - 1; i > index; i--)
      current = current->prev;
  }

  return current->data;
}

void dlist_remove(DoublyLinkedList *list, size_t index)
{ // remove elemento
  if (index >= list->size)
    return;

  DNode *current;

  if (index < list->size / 2)
  {
    current = list->head;
    for (size_t i = 0; i < index; i++)
      current = current->next;
  }
  else
  {
    current = list->tail;
    for (size_t i = list->size - 1; i > index; i--)
      current = current->prev;
  }

  if (current->prev != NULL)
    current->prev->next = current->next;
  else
    list->head = current->next;

  if (current->next != NULL)
    current->next->prev = current->prev;
  else
    list->tail = current->prev;

  free(current->data);
  free(current);

  list->size--;
}

void dlist_free(DoublyLinkedList *list) // libera toda a lista
{
  DNode *current = list->head;

  while (current != NULL)
  {
    DNode *next = current->next;
    free(current->data);
    free(current);
    current = next;
  }

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}
