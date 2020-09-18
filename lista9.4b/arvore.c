#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pilha.c"

void PesqIn(TREE arv);

void PesqPOS(TREE arv);

void insArvoreIN(TREE *arv, int vr);

void imprime_red(TREE arv, PILHA *pilha);
void ImprimePosNaoRecursivo(TREE arv, PILHA *pilha);
int main() {
    TREE arvore = NULL, x;
    int i;
    PILHA pilha;
    insArvoreIN(&arvore, 5);
    insArvoreIN(&arvore, 4);
    insArvoreIN(&arvore, 2);
    insArvoreIN(&arvore, 3);
//    insArvoreIN(&arvore, 1);
//    insArvoreIN(&arvore, 2);
    insArvoreIN(&arvore, 8);
    insArvoreIN(&arvore, 6);
    insArvoreIN(&arvore, 10);


    printf("Posfixa: ");
    PesqPOS(arvore);
    printf("\n");
    //tRemove (&arvore,10);
    printf("FUNÇÃO DE IMPRESSÃO.\n");
    ImprimePosNaoRecursivo(arvore,&pilha);
    printf("\n");

/*
    printf ("Infixa: ");
    PesqIn (arvore);
    printf ("\n");

    x = NohMaiorABB(arvore);

    if (x)
        printf ("\nMaior noh: %d\n",x->info);
    else
        printf ("Nula\n");

    x = NohMenorABB(arvore);

    if (x)
        printf ("Menor noh: %d\n",x->info);
    else
        printf ("Nula\n");

    x = tPesq(&arvore,8);
    if (x)
        printf ("Noh Pesquisado: %d\n",x->info);
    else
        printf ("Nula\n");
    printf ("Árvore completa: %d\n",arvCompleta(arvore));
    printf ("Arvore estritamente binária: %d\n",arvEstBin(arvore));
    i = 10;
    printf ("Maior valor: %d\n",NohMaiorVrABB(arvore));
    printf ("Menor valor: %d\n",NohMenorVrABB(arvore));
    printf ("O nível do nó %d é %d\n",i,nivelNoh(arvore,i));
    printf ("A lista tem %d nós\n",contaNoh(arvore));
    printf ("A soma dos nós é: %d\n",somaNoh(arvore));

    printf ("Nós não folha: "); nohNaoFolha(arvore);
    printf ("Nós folha: "); nohFolha(arvore);

    printf ("\nArvore possui o valor %d: %d\n",i,procuraValor(arvore,i));
*/
return 0;

}

void ImprimePosNaoRecursivo(TREE arv, PILHA *pilha){
    imprime_red(arv->esq,&(*pilha));
    imprime_red(arv->dir,&(*pilha));
    printf("[%d]", arv->info);
}

void nohMaisEsquerda (TREE arv, PILHA *pilha){
    //Leva até o nó mais a esquerda da árvore, armazenando na pilha todos os nós do caminho.
    while (arv) {
        push(&(*pilha),arv);
        arv = arv->esq;
    }
}

void imprime_red(TREE arv, PILHA *pilha) {
    init(&(*pilha));
    TREE topo, arvAux = arv;

    nohMaisEsquerda(arvAux, &(*pilha));

    while (pilha->topo != -1 ) {
        topo = top(*pilha);
        if (topo->esq == NULL && topo->dir == NULL){
            printf ("[%d] ", topo->info);
            pop(&(*pilha));
        } else {
            printf ("[%d] ", topo->info);
            pop(&(*pilha));
            nohMaisEsquerda(topo->dir, &(*pilha));
        }
    }
}

void PesqIn(TREE arv) {
//Infixa

    if (arv != NULL) {
        PesqIn(arv->esq);
        printf("%i ", arv->info);
        PesqIn(arv->dir);
    }
}

void PesqPOS(TREE arv) {
//Pos Fixa

    if (arv != NULL) {
        PesqIn(arv->esq);
        PesqIn(arv->dir);
        printf("%i ", arv->info);
    }
}

void insArvoreIN(TREE *arv, int vr) {
//Infixa
    if (*arv == NULL) {
        *arv = (TREE) malloc(sizeof(struct noh));
        (*arv)->info = vr;
        (*arv)->esq = NULL;
        (*arv)->dir = NULL;
    } else {
        if (vr < (*arv)->info)
            insArvoreIN(&((*arv)->esq), vr);
        else
            insArvoreIN(&((*arv)->dir), vr);
    }
}
