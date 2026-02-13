#include <stdio.h>
#include <stdlib.h>

typedef struct Pedido {
    int id;                         // Identificador único do pedido
    char nome_cliente[50];          // Nome para entrega
    float itens_precos[10];         // Array fixo com preços dos itens (exigência do projeto)
    int status;                     // 0: Pendente, 1: Em preparo, 2: Entregue
    struct Pedido *proximo;         // Ponteiro para o próximo nó (Lista/Fila)
} Pedido;
