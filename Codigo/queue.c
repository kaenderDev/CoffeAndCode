#include "queue.h"

static QNode *create_qnode(void *value, size_t element_size)
{ // cria um novo nó
  QNode *node = malloc(sizeof(QNode));
  node->data = malloc(element_size);
  memcpy(node->data, value, element_size);
  node->next = NULL;
  return node;
}

Queue queue_create(size_t element_size)
{ // cria fila vazia
  Queue queue;
  queue.front = NULL;
  queue.rear = NULL;
  queue.element_size = element_size;
  queue.size = 0;
  return queue;
}

void queue_enqueue(Queue *queue, void *value)
{ // insere no fim
  QNode *node = create_qnode(value, queue->element_size);

  if (queue->rear == NULL)
  {
    queue->front = node;
    queue->rear = node;
  }
  else
  {
    queue->rear->next = node;
    queue->rear = node;
  }

  queue->size++;
}

void queue_dequeue(Queue *queue)
{ // remove do inicio
  if (queue->front == NULL)
    return;

  QNode *temp = queue->front;
  queue->front = temp->next;

  if (queue->front == NULL)
    queue->rear = NULL;

  free(temp->data);
  free(temp);

  queue->size--;
}

void *queue_front_ptr(Queue *queue)
{ // retorna ponteiro do primeiro elemento
  return queue->front ? queue->front->data : NULL;
}

void queue_free(Queue *queue)
{ // libera toda a fila
  while (queue->front != NULL)
  {
    queue_dequeue(queue);
  }
}
