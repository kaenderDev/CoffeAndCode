#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <string.h>

typedef struct SNode // nó da pilha
{
  void *data;
  struct SNode *next;
} SNode;

typedef struct // a pilha
{
  SNode *top;
  size_t element_size;
  size_t size;
} Stack;

Stack stack_create(size_t element_size);

void stack_push(Stack *stack, void *value); // insere no topo

void stack_pop(Stack *stack); // remove do topo

void *stack_top_ptr(Stack *stack); // retorna ponteiro do topo

void stack_free(Stack *stack); // libera toda a pilha

#define STACK_TOP(type, stack) (*(type *)stack_top_ptr(stack))

#endif
