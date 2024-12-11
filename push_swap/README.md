# Push Swap

## Descrição

O **Push Swap** é um projeto que visa implementar um algoritmo eficiente para ordenar uma lista de números utilizando apenas duas pilhas e um conjunto restrito de operações. O objetivo é desenvolver um programa que receba uma sequência de números e os ordene da forma mais eficiente possível, minimizando o número de movimentos necessários.

O projeto está dividido em duas partes:
1. **push_swap**: Um programa que calcula e exibe a sequência de operações necessárias para ordenar a pilha `a`.
2. **checker**: Um programa opcional que verifica se a lista de operações gerada pelo `push_swap` resulta em uma pilha ordenada.

## Operações Permitidas

As operações que podem ser realizadas entre as duas pilhas (`a` e `b`) são:

- `sa`: Troca os dois primeiros elementos da pilha `a`.
- `sb`: Troca os dois primeiros elementos da pilha `b`.
- `ss`: Troca os dois primeiros elementos de ambas as pilhas `a` e `b`.
- `pa`: Pega o primeiro elemento de `b` e o coloca no topo de `a`.
- `pb`: Pega o primeiro elemento de `a` e o coloca no topo de `b`.
- `ra`: Roda todos os elementos da pilha `a` para cima (o primeiro elemento vai para o final).
- `rb`: Roda todos os elementos da pilha `b` para cima.
- `rr`: Roda todos os elementos de ambas as pilhas `a` e `b` para cima.
- `rra`: Roda todos os elementos da pilha `a` para baixo (o último elemento vai para o topo).
- `rrb`: Roda todos os elementos da pilha `b` para baixo.
- `rrr`: Roda todos os elementos de ambas as pilhas `a` e `b` para baixo.

## Como Funciona

O algoritmo do **Push Swap** envolve calcular a melhor sequência de operações para ordenar a pilha `a` movendo elementos para a pilha `b` e vice-versa. O desafio é fazer isso com a menor quantidade de movimentos possível.

push_swap/
├── algoritmo/            # Implementação do algoritmo principal
│   ├── algoritmo.c       # Arquivo relacionado à lógica de ordenação
│   └── algoritmo_extras.c       # Extras do algoritmo
├── movements/            # Funções relacionadas aos movimentos das pilhas
│   ├── movements.c       # Implementação das operações nas pilhas (sa, sb, pa, etc.)
│   └── movements_extras.c       # Cabeçalhos relacionados aos movimentos
├── includes/             # Arquivos de cabeçalho principais
│└── push_swap.h       # Cabeçalho principal com declarações de funções e estruturas
│   ├──push_swap.h     # Cabeçalho principal com declarações de funções e estruturas
│   └── Makefile       # Arquivo para compilação
├── extras/               # Funções auxiliares e extras
│   ├── error_handle.c           # Funções auxiliares (ex.: parsing, validações)
│   ├── stack_manipulation.c     #stack related functions
│   ├── split.c             #split function
│   └── extras.c           # Cabeçalhos para funções auxiliares
├── push_swap.c           # Arquivo principal do programa
└── README.md             # Documentação do projeto
