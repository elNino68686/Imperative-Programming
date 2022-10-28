typedef struct nodo {
	int valor;
	struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d) {
	ABin a = malloc (sizeof(struct nodo));
	if (a!=NULL) {
		a->valor = r; a->esq = e; a->dir = d;
	}
	return a;
}






int altura (ABin a){
	int alt = 0,e,d;

	if(a != NULL){
		//alt = max(1+altura(a->esq),1+altura(a->dir));
		//alt = 1 + max(altura(a->esq),altura(a->dir));
		e = altura(a->esq);
		d = altura(a->dir);
		if(e>d) alt = 1 + e;
		else alt = 1 + d;
	}

	return alt;
}


int nFolhas (ABin a){
	int res = 0;

	if(a!=NULL)
		if(a->esq == NULL && a->dir == NULL) res++;
		else res = nFolhas(a->esq) + nFolhas(a->dir);

	return res;

} 


ABin maisEsquerda (ABin a){

	if(a!=NULL){
		while(a->esq != NULL)
			a = a->esq;
	}
	return a;

}


void imprimeNivel (ABin a, int l){

	if(a!=NULL){
		if(l == 0) printf("%d",a->valor);
		else {
			imprimeNivel(a->esq,l-1);
			imprimeNivel(a->dir,l-1);
		}
	}
}



int procuraE (ABin a, int x){
	int r=0;

	if(a!=NULL){
		if(a->valor == x) r=1;
		else r=procuraE(a->esq,x) || procuraE(a->dir,x);
	}	
	return r;

}

int procuraE (ABin a, int x){
	return (a!=NULL && (a->valor == x || procuraE(a->esq,x) || procuraE(a->dir,x)));
}


struct nodo *procura (ABin a, int x){

	while(a!=NULL && a->valor != x)
		if(a->valor > x)
			a=a->esq;
		else a=a->dir;

	return a;	
}


int nivel (ABin a, int x) {
	int r;

	for(r=0; a!=NULL && a->valor != x; r++)
		if(a->valor > x)
			a=a->esq;
		else 
			a=a->dir;

	if(a==NULL) r=-1;	

	return r;
}



void imprimeAte (ABin a, int x){

	if(a!=NULL){
		imprimeAte(a->esq, x);
		if(a->valor < x){
			printf("%d",a->valor);
			imprimeAte(a->dir, x);
		}
	}		
}



















