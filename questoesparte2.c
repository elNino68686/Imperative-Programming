typedef struct lligada {
	int valor;
	struct lligada *prox;
} *LInt;


//PERGUNTA 1
int length (LInt l){
	int r = 0;
	if(l != NULL) r = 1 + length(l->prox);

	return r;
}

//PERGUNTA 2
