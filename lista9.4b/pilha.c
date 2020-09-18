#define TAMANHO 6
struct noh {
    int info;
    struct noh *esq, *dir;
};
typedef struct noh *TREE;

struct p {
    TREE dados[TAMANHO];
    int topo; // Sera a variavel onde vou colocar o topo da pilha;
};
typedef struct p PILHA; // typedef Essa forma de programação ajuda em dois sentidos: 1º. Fica mais simples entender para que serve tal tipo de dado; 2º. É a única forma de conseguirmos referenciar uma estrutura de dados dentro de outra (struct dentro de struct).



// declaração das funções
void push(PILHA *p, TREE vr);
void pop(PILHA *p);
TREE top(PILHA p);
int empty(PILHA p);
int full(PILHA p);
void init (PILHA *p);

void push(PILHA *p, TREE vr){
    if(!full(*p)){ // Chama a função full para verificar se a pilha esta cheia
        (*p).dados[++((*p).topo)] = vr;// a pilha recebe um valor no seu topo
    }
}

void pop(PILHA *p){
    if(!empty(*p)){ // Chama a função empty para verificar se a pilha esta vazia
        p->topo--;
    }
}

TREE top(PILHA p){ // Retorna o topo da pilha
    return p.dados[p.topo];
}


int empty(PILHA p){ // Verifica se a pilha esta vazia
    return !(p.topo+1);
}

int full(PILHA p){ // verifica se a pilha esta cheia se ela não estiver cheia ele retorna 0 caso contrario retorna 1
    return !((TAMANHO -1)-p.topo); // se o resultado for igual de zero o return retorna a negação no caso 1
    // se o resultado for diferente de zero ele retorna a negação no caso 0
}

void init(PILHA *p){ // inicia a pilha colocando ela com -1
    (*p).topo=-1;
}
