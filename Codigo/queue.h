#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <string.h>

typedef struct QNode
{ // nó da fila
  void *data;
  struct QNode *next;
} QNode;

typedef struct
{ // a fila
  QNode *front;
  QNode *rear;
  size_t element_size;
  size_t size;
} Queue;

Queue queue_create(size_t element_size);

void queue_enqueue(Queue *queue, void *value); // insere no fim

void queue_dequeue(Queue *queue); // remove do inicio

void *queue_front_ptr(Queue *queue); // retorna ponteiro do primeiro elemento

void queue_free(Queue *queue); // libera toda a fila

#define QUEUE_FRONT(type, queue) (*(type *)queue_front_ptr(queue))

#endif
