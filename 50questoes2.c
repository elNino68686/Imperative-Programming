#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

typedef struct lligada {
	int valor;
	struct lligada *prox;
} *LInt;


//PERGUNTA 1
int length (LInt l){
	int r;

	if(l == NULL) r=0;
	else r = 1 + length(l->prox);

	return r;
}

//PERGUNTA 2
void freeL (LInt l){

	while(l){
		LInt temp = l;
		l = l->prox;
		free(temp);
	}
}


//PERGUNTA 3
void imprimeL (LInt l){

	while(l!=NULL){
		printf("%d", l->valor);
		l = l->prox;
	}
} 


//PERGUNTA 4
LInt reverseL (LInt l){
	int len = length(l);
    LInt array[len];
    for(int i = 0; i < len; l = l->prox) array[i++] = l;
    for(int i = len - 1; i > 0; i--) array[i]->prox = array[i-1];
    array[0]->prox = NULL;
    return array[len - 1];
}


LInt reverseL2(LInt l) {
    LInt prox = l->prox;
    l->prox = NULL;
    while(prox) {
        LInt temp = prox->prox;
        prox->prox = l;
        l = prox;
        prox = temp;
    }
    return l;
}


//PERGUNTA 5
void insertOrd (LInt* l, int x) {
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    LInt prev = NULL;
    for(;*l && (*l)->valor < x; prev = (*l), l = &((*l)->prox));
    if(prev) {
        new->prox = (*l);
        prev->prox = new;
    }
    else {
        new->prox = (*l);
        *l = new;
    }
}


//PERGUNTA 6
int removeOneOrd(LInt *l, int x) {
    LInt prev = NULL;
    for(;*l && x != (*l)->valor; prev = *l, l = &((*l)->prox));
    if(!(*l)) return 1;
    if(!prev) (*l) = (*l)->prox;
    else prev->prox = (*l)->prox;
    return 0;
}


int removeOneOrd2(LInt* l, int x) {
    if((*l)->valor == x) {
        LInt temp = (*l);
        (*l) = (*l)->prox;
        free(temp);
        return 0;
    }
    LInt prev = (*l);
    while(prev->prox) {
        LInt list = prev->prox;
        if(list->valor == x) {
            prev->prox = list->prox;
            free(list);
            return 0;
        }
        prev = prev->prox;
    }
    return 1;
}


//PERGUNTA 7
void merge(LInt* r, LInt a, LInt b) {
    if(!a && !b) return;
    if(b == NULL || a != NULL && a->valor < b->valor) {
        (*r) = a;
        merge(&((*r)->prox),a->prox,b);
    }
    else {
        (*r) = b;
        merge(&((*r)->prox),a,b->prox);
    }
}

//PERGUNTA 8

void splitQS(LInt l, int x, LInt *mx, LInt *Mx) {
    if(!l) return;
    if(l->valor < x) {
        (*mx) = l;
        (*Mx) = NULL;
        splitQS(l->prox, x, &((*mx)->prox), Mx);
    }
    else {
        (*Mx) = l;
        (*mx) = NULL;
        splitQS(l->prox, x, mx, &((*Mx)->prox));
    }
}

//PERGUNTA 9

LInt parteAmeio (LInt *l){
    int meio = length(*l)/2;
    if(meio == 0) return NULL;
    LInt y = (*l);
    LInt prev = NULL;
    for(int i = 0; i < meio; i++) {
        prev = (*l);
        (*l) = (*l)->prox;
    }
    prev->prox = NULL;
    return y;
}

//PERGUNTA 10

int removeAll(LInt *l, int x) {
    int rem = 0;
    LInt prev = NULL;
    while(*l) {
        if((*l)->valor == x) {
            if(!prev) (*l) = (*l)->prox;
            else prev->prox = (*l)->prox;
            rem++;
        }
        else {
            prev = (*l);
            l = &((*l)->prox);
        }
    }
    return rem;
}

//PERGUNTA 11

int removeDups(LInt *l) {
    int rem = 0;
    for(;*l; l = &((*l)->prox)) {
        LInt prevAux = (*l), aux = (*l)->prox;
        for(; aux; aux = prevAux->prox) {
            if(aux->valor == (*l)->valor) {
                prevAux->prox = aux->prox;
                rem++;
                free(aux);
            }
            else prevAux = aux;
        }
    }
    return rem;
}

//PERGUNTA 12

int removeMaiorL(LInt *l) {
    int max = (*l)->valor;
    LInt prev = NULL;
    LInt maxPrev = NULL;
    LInt maxL = (*l);
    LInt list = (*l);
    for(;list; list = list->prox) {
        if(list->valor > max) {
            maxPrev = prev;
            maxL = list;
            max = list->valor;
        }
        prev = list;
    }
    if(!maxPrev) (*l) = (*l)->prox;
    else maxPrev->prox = maxL->prox;
    return max;
}

//PERGUNTA 13

void init (LInt *l) {
    LInt prev = NULL;
    for(;(*l)->prox;prev = *l, l = &((*l)->prox));
    if(!prev) {
        free(*l);
        *l = NULL;
    }
    else {
        prev->prox = NULL;
        free(*l);
    }
}

//PERGUNTA 14

void appendL (LInt *l, int x) {
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    if(!(*l)) (*l) = new;
    else {
        for(;(*l)->prox; l = &((*l)->prox));
        (*l)->prox = new;
    }
}

//PERGUNTA 15

void concatL (LInt *a, LInt b) {
    if(*a) concatL(&((*a)->prox),b);
    else (*a) = b;
}













