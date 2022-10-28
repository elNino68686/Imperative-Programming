typedef struct celula {
char *palavra;
int ocorr;
struct celula * prox;
} * Palavras;


void libertaLista (Palavra l){
	Palavras aux;
	while(l != NULL){
		aux = l->palavra;
		l = l->prox;
		free(aux->palavras);
		free aux;
	}
}








Palavras acrescentaInicio(Palavras l, char *p){

	Palavras nova = malloc(sizeof(struct celula));

	nova->palavra = p;
	nova->ocorr = 1;
	nova->prox = l;

	return nova;
}










Palavras acrescentaFim(Palavras l, char *p){
	Palavras nova = malloc(sizeof(struct celula));
	Palavras res = l;

	if(l==NULL)
		res = nova;
	else{
		while(l->prox != NULL)
			l=l->prox;
	
		l->prox = nova;
		nova->palavra = p;
		nova->ocorr = 1;
		nova->prox = NULL;
	}

	return
}

Palavras acrescenta (Palavras l, char *p){

	if(l!=NULL){
		while(l->palavra != p && l != NULL)
			l=l->prox;
		if(l==p)
			l->ocorr++;
		else {
			acrescentaInicio(l,p);
		}

	}
}	

struct celula * maisFreq (Palavras l){
	int max=0;
	Palavras res = NULL;

	while(l!=NULL){
		if((l->ocorr) > max){
			max = l->ocorr;
			res = l;
		}

	l=l->prox;	
	}

	return res;
}








int quantasP (Palavras l){
	int count = 0;
	while(l != NULL){
		count++;
		l = l->prox;
	}
	return count;
}


void listaPal(Palavras l){
	while(l != NULL){
		printf("%s->%d"\n, l->palavra, l->ocorr);
		l->l->prox;
	}
}


char * ultima (Palavras l){
	char *res = NULL;
	if(l->prox != NULL)
		l=l->prox;
	res = l->palavra;

	return res;
}




 Palavras acrescentaInicio (Palavras l, char *p){
 	
 	Palavras y = malloc(sizeof(struct celula));
 	y->palavra = strdup(p);
 	y->ocorr = 1;
 	y->prox = l;
 	return y;
 }



 Palavras acrescentaFim (Palavras l, char *p){
 	
 	Palavras nova = acrescentaInicio(NULL,p);
 	Palavras res = l;

 	if(l==NULL)
 		res = nova;
 	else{
 		while(l->prox != NULL)
 			l=l->prox;
 		l->prox=nova;
 	}
 	return res;
 }
 

Palavras acrescenta (Palavras l, char *p) {

	Palavras res = l; 
	while(l != NULL && strcmp(l->palavra,p) != 0)
			l=l->prox;	
		
	if(l==NULL)
		res = acrescentaInicio(res,p);
	else 
		l->ocorr++;

	return res;	
}
//no strcmp o menor e maior representa a ordem alfabetica

//struct celula == Palavras

struct celula * maisFreq (Palavras l){
	int max = 0;
	Palavras res = NULL;
	while(l != NULL){
		if(l->ocorr > max){
			max=l->ocorr;
			res = l;
		}

	l=l->prox;	
	}

	return res;
}

struct celula * maisFreq (Palavras l){

	Palavras maisf = l;
	while(l != NULL){
		if(l->ocorr > maisf->ocorr)
			maisf = l;
		l=l->prox;	
	}

	return maisf;
}







