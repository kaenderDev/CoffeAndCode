# Sistema de Cadastramento Academico

Desenvolvimento do resto aqui

## Estruturas de Dados

Este módulo implementa descreve as estruturas que servem como base para o sistema de cadastramento acadêmico. Todas as estruturas são **genéricas**, utilizando `void*` e `element_size` para permitir o armazenamento de qualquer tipo de dado.

Cada estrutura é modularizada em arquivos `.h` (interface) e `.c` (implementação), facilitando reutilização e manutenção.

---

### Lista Encadeada

A lista encadeada é implementada com nós que armazenam:

- um ponteiro genérico para dados (`void*`)
- um ponteiro para o próximo nó

A lista mantém um ponteiro para o primeiro nó (`head`) e o tamanho atual. Inserções criam novos nós com alocação dinâmica e cópia via `memcpy`. A remoção percorre a lista até o índice desejado, ajusta os ponteiros e libera a memória do nó removido.

#### Complexidade

| Operação           | Complexidade |
| ------------------ | ------------ |
| Inserção no início | **O(1)**     |
| Inserção no fim    | **O(n)**     |
| Acesso por índice  | **O(n)**     |
| Remoção por índice | **O(n)**     |
| Liberação total    | **O(n)**     |

---

### Lista Duplamente Encadeada

A lista duplamente encadeada adiciona ponteiros `prev` e `tail`, permitindo navegação bidirecional. O acesso por índice é otimizado escolhendo o percurso mais curto (a partir do início ou do fim). Inserções e remoções atualizam os ponteiros vizinhos para manter a integridade da estrutura.

#### Complexidade

| Operação           | Complexidade |
| ------------------ | ------------ |
| Inserção no início | **O(1)**     |
| Inserção no fim    | **O(1)**     |
| Acesso por índice  | **O(n)**     |
| Remoção por índice | **O(n)**     |
| Liberação total    | **O(n)**     |

---

### Fila (Queue)

A fila segue o modelo **FIFO (First In, First Out)** e utiliza ponteiros para o primeiro (`front`) e último (`rear`) elemento. Inserções ocorrem no final e remoções no início, sem necessidade de percorrer a estrutura.

#### Complexidade

| Operação           | Complexidade |
| ------------------ | ------------ |
| Enqueue (inserção) | **O(1)**     |
| Dequeue (remoção)  | **O(1)**     |
| Acesso ao primeiro | **O(1)**     |
| Liberação total    | **O(n)**     |

---

### Pilha (Stack)

A pilha segue o modelo **LIFO (Last In, First Out)** e mantém apenas um ponteiro para o topo (`top`). Push e pop operam exclusivamente no topo, garantindo operações constantes.

#### Complexidade

| Operação        | Complexidade |
| --------------- | ------------ |
| Push (inserção) | **O(1)**     |
| Pop (remoção)   | **O(1)**     |
| Acesso ao topo  | **O(1)**     |
| Liberação total | **O(n)**     |

---

### Gerenciamento de memória

Todas as estruturas utilizam:

- `malloc` para alocação dinâmica
- `memcpy` para cópia genérica de dados
- funções específicas para liberação completa da memória

Macros são fornecidas para facilitar o acesso tipado aos dados armazenados. Essas macros assumem que o índice é válido e que o tipo informado corresponde ao tipo armazenado; o uso incorreto pode resultar em comportamento indefinido.
