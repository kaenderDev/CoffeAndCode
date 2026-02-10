#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <stdlib.h>
#include <string.h>

typedef struct DNode // nó da lista duplamente encadeada
{
  void *data;
  struct DNode *prev;
  struct DNode *next;
} DNode;

typedef struct // a lista
{
  DNode *head;
  DNode *tail;
  size_t element_size;
  size_t size;
} DoublyLinkedList;

DoublyLinkedList dlist_create(size_t element_size);

void dlist_push_front(DoublyLinkedList *list, void *value); // insere no inicio

void dlist_push_back(DoublyLinkedList *list, void *value); // insere no fim

void *dlist_get_ptr(DoublyLinkedList *list, size_t index); // retorna ponteiro do indice

void dlist_remove(DoublyLinkedList *list, size_t index); // remove elemento

void dlist_free(DoublyLinkedList *list); // libera a lista

#define DLIST_GET(type, list, index) (*(type *)dlist_get_ptr(list, index))

#endif
