typedef struct slist {
	int valor;
	struct slist * prox;
} * LInt;


LInt newLInt (int x, LInt xs) {
	LInt r = malloc (sizeof(struct slist));
	if (r!=NULL) {
	r->valor = x; t->prox = xs;
	}
	return r;
}


typedef struct {
	LInt inicio,fim;
} Queue;


void initQueue(Queue *q){
	 q->inicio = NULL;
	 q->fim = NULL;
}

//se nao alterar a estrututa nao preciso de passar o apontador
//basta apenas escrever o . em vez da ->

 int QisEmpty (Queue q){
 	return (q.inicio == NULL);
 }



int enqueue (Queue *q, int x){
	LInt nova = newLInt(x,NULL);
	int r = 1;
	if(nova != NULL){
		r=0;
		if(QisEmpty(*q))//if(q->inicio == Null)
			q->inicio = q->fim = nova;
		else {
			q->fim->prox = nova;
			q->fim = nova;
		}
	}

	return r;

}



int dequeue (Queue *q, int *x){

	int r=1;
	if(q->inicio != NULL){
		r=0;
		aux=q->inicio;
		*x = q->inicio->valor;
		if(q->inicio == q->fim)
			q->inicio = q->fim = NULL;
		else 
			q->inico = q->inicio->prox;
		free(aux);
	}

	return r;
}


int front (Queue q, int *x){
	int r=1;
	if(q.inicio != NULL){
		r=0;
		*x = q.inicio->valor;
	
	}

	return r
}



typedef LInt QueueC;

void initQueue (QueueC *q){
	*q = NULL;
}


int QisEmpty (QueueC q){
 	return (q == NULL);
 }


int enqueue (QueueC *q, int x){
	LInt nova = newLInt(x,NULL);
	int r=1;
	if(nova != NULL){
		r=0;
		if(*q == NULL){
			nova->prox = nova;
			*q = nova;
		}
		else {
			nova->prox = (*q)->prox;
			(*q)->prox = nova;
			*q = nova;
		}
	}
	return r;
}  



int dequeue (QueueC *q, int *x){
	int r=1;
	LInt aux;

	if(*q != NULL){
		r=0;
		aux = (*q)->prox;
		*x=aux->valor;//(*q)->prox->valor
		if(*q == (*q)->prox)
			*q = NULL;
		else 
		(*q)->prox = (*q)->prox->prox;
	
	}
	free(aux);
	return r;

}



typedef struct dlist {
	int valor;
	struct dlist *ant, *prox;
} *DList;

typedef struct {
	DList back, front;
} Deque	

//DList newDList (int x, DList ant, DList prox){






int pushBack (Deque *q, int x){
	DList nova = newDList (x,NULL,q->back);
	int r=1;
	if(nova != NULL){
		r=0;
		if(q->back == NULL){
			q->back = q->front = nova;
		}
		else {
			q->back->ant = nova;
			q->back = nova;
		}
	}
	return r;
}


int pushFront (Deque *q, int x){
	DList nova = newDList (x,q->front,NULL);
	int r=1;
	if(nova != NULL){
		r=0;
		if(q->back == NULL){
			q->back = q->front = nova;
		}
		else {
			q->front->prox = nova;
			q->prox = nova;
		}
	}
	return r;
}





















