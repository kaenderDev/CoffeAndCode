#include "stack.h"

static SNode *create_snode(void *value, size_t element_size) // cria um novo nó
{
  SNode *node = malloc(sizeof(SNode));
  node->data = malloc(element_size);
  memcpy(node->data, value, element_size);
  node->next = NULL;
  return node;
}

Stack stack_create(size_t element_size) // cria pilha vazia
{
  Stack stack;
  stack.top = NULL;
  stack.element_size = element_size;
  stack.size = 0;
  return stack;
}

void stack_push(Stack *stack, void *value) // insere no topo
{
  SNode *node = create_snode(value, stack->element_size);
  node->next = stack->top;
  stack->top = node;
  stack->size++;
}

void stack_pop(Stack *stack) // remove do topo
{
  if (stack->top == NULL)
    return;

  SNode *temp = stack->top;
  stack->top = temp->next;

  free(temp->data);
  free(temp);

  stack->size--;
}

void *stack_top_ptr(Stack *stack) // retorna ponteiro do topo
{
  return stack->top ? stack->top->data : NULL;
}

void stack_free(Stack *stack) // libera toda a pilha
{
  while (stack->top != NULL)
  {
    stack_pop(stack);
  }
}
