#include <stdio.h>
#include <stdlib.h>

struct noh {
    int item;
    struct noh *l, *r;
};
typedef struct noh *link;

void STACKinit(int N);

int STACKempty();

void STACKpush(int item);

int STACKpop();

int *s;
int topo;
int Item;
int main() {

}

// Imprime o item de cada nó de uma árvore binária h.
// A função supõe que h != NULL e que a altura da árvore
// não passa de 100.
//
void imprime_red(link h) {
    STACKinit(100);
    STACKpush(h);
    while (!STACKempty()) {
        h = STACKpop();
        printf("%d\n", h->item);
        if (h->r != NULL) STACKpush(h->r);
        if (h->l != NULL) STACKpush(h->l);
    }
}

// Cria uma pilha vazia, com espaço para N elementos,
// no vetor global s.
void STACKinit(int N) {
    s = malloc(N * sizeof(Item));
    topo = 0;
}

// Devolve 1 se a pilha estiver vazia e 0 em caso contrário.
int STACKempty() {
    return topo == 0;
}

// Coloca item no topo da pilha.
void STACKpush(int item) {
    s[topo++] = item;
}

// Retira o item que estiver no topo da pilha.
// Devolve o valor do elemento retirado.
int STACKpop() {
    return s[--topo];
}