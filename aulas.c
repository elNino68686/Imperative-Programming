#include <stdlib.h>
#include <stdio.h>


int procura (int x, int v[], int N){

	int i,r = (-1);

	while (i < N && r==-1)
		i++;
	if (v[i] == x) r = i;

	return r;
}


//procura em arrays ordenados(crescente)

int procura1(int x, int v[], int N){
//v esta ordenado
	int i;

	while(i<N && v[i]<x)
		i++;
	if (i<N && v[i] == x) return i;
	else return -1;

}





int procuraB (int x, int v[], int N){
	//v ordenado
	//procura binaria 

	return (procuraEntre (x,v,N,0,N-1));
}

int procuraEntre(int x, int v[], int N, int a, int b){
	int meio;
	int r;

	if(a>b) r=(-1);
	else {
		meio = (a+b)/2;
		if (v[meio] == x) r = meio;

		else if (v[meio] > x) r = procuraEntre(x,v,N,a,meio);

		else r = procuraEntre(x,v,N, meio + 1, b);
	}
	return r; 
}	



int procuraB(int x, int v[], int N){
	int r,meio;

	if (N == 0) r = -1;
	else {
		meio = N/2;
		if (v[meio] == x) r = x;
		else if (v[meio] > x) r = procuraB(x,v,meio);
		else r = meio + 1 + procuraB(x,v + meio + 1,N - meio - 1);
	}
	return r;
}



//ordenar arrays

void ordenaR (int v[], int N){
	
	int m,i;

	if (N > 1){
		//descobrir o indice do menor elemento
        m = 0;
        for(i=1; i<N; i++){
        	if (v[i] < v[m]) m=i;
        }
        swap(v,0,m);
        ordenaR(v+1, N-1);
	}	 
}


void minSort(int v[], in N){
	int m, i, j;

	for (j=0; j<N-1; j++){
		//descobrir o menor elemento desde j até N
		m=j;
		for(i=j+1; i<N; i++)
			if (v[i] < v[m]) m=i;
		swap(v,j,i);
	}
}


void selSort(int v[], int N){
	int i,j;

	for(j=0; j<N-1; j++)
		for(i=j+1; i<N; i++)
			if (v[i] < v[j]) 
				swap(v,i,j);
}


void bubble(int v[], int N){
	int i;

	for(i=0; i<N-1; i++)
		if (v[i] > v[i+1]) swap(v, i, i+1);
}


void bubbleSort(int v[], int N){
	int i;

	for(i=0; i<N; i++)
		bubble(v,N);
}


int bubble2(int v[], int N){
	int i;
	int r=0;

	for(i=0; i<N-1; i++)
		if(v[i] > v[i+1]){
			swap(v,i,i+1);
			r=i;
		}
	return r;	
}

void insere(int v[], int N, int x){
	//v[0..N[ está ordenado
	//inserir o x
	//no final v[0..N+1[ está ordenado
	int j;
	for(j=N-1; j>=0 && v[j]>x; j--)
		v[j+1] = v[j];
	v[j+1]=x;
}




void insSort(int v[], int N){
	int i;

	//no array v, nos indices [0..i[ está ordenado
	i=1;
	while(i<N){
		insere(v,i,v[i]);
		i++;
	} 
}


//divisao e conquista

void merge(int a[], int na, int b[], int nb, int r[]);
//funde dois arrays ordenados num só


void mergeSort(int v[], int N){
	int m,i;

	if (N > 1){
		m=m/2;
		//1ª metade v[0..m[ que tem m elementos
		//2ª metade v[m..N[ que tem N- m elementos
		mergeSort(v,m);
		mergeSort(v+m,N-m);
		merge(v,m,v+m,N-m,aux);
		for(i=0; i<N; i++) v[i] = aux[i];

	}
}


int partition(int v[], int N){
	//usa como pivot v[N-1]
	int r,i;

	//r = i = 0;
	//while(i<N-1){
	//	if(v[i] > v[N-1]) i++;
	//	else {swap(v, r, i); r++; i++}
	//}
	//
	for(r=i=0; i<N-1; i++)
		if(v[i] <= v[N-1]) swap(v, r++, i);

	swap(v, r, N-1);
	return r;
}


void quickSort(int v[], int N){
	int p;

	if(N>1){
		p = partition(v,N);
		quickSort(v, p);
		quickSort(v+p+1, N-p-1);
	}
}

//Definição de tuplos em c

struct s {
	int sp;
	int valores [Max];
};

struct s a, b[40]; 

//a componente sp do a paasa a ser 5
a.sp = 5;


a.valores[3] = 42; //
b[2].sp = 3;
b[3].vaalores[5] = 44;

---exemplo de implementação de stack de inteiros---

typedef struct stack{
	int valores[100];
	int quantos;
} STACK;

//os valores são inseridos da esquerda para a direita
















STACK push (int x, STACK s){
	s.valores[s.quantos++] = x;
	return s;
}

STACK pop (STACK s){
	s.quantos--;
}

int top (STACK s){
	return (s.valores[s.quantos-1]);
}

int empty (STACK s){
	return (s.quantos == 0);
}


//nao cria copia
void push (int x, STACK *s){
	(*s).valores[(*s).quantos++] = x;
}


void pop (STACK *s){
	(*s).quantos--;
}

int top (STACK *s){
	return ((*s).valores[(*s).quantos-1]);
}

int empty (STACK *s){
	return ((*s).quantos == 0);
}


//existe uma abreviatura para (*a).b
//a é um endereço de uma struct que tem um campo b
//é costume escrever a->b


void push (int x, STACK *s){
	s->valores[s->quantos++] = x;
}


void pop (STACK *s){
	s->quantos--;
}

int top (STACK *s){
	return (s->valores[s->quantos-1]);
}

int empty (STACK *s){
	return (s->quantos == 0);
}

typedef struct stack{
	int valores[100];
	int quantos;
} STACK, *SStack;
//define 2 tipos
//STACK que é o mesmo que struct stack
//SStack que é um endereço de STACK


void push (int x, SStack s){
	s->valores[s->quantos++] = x;
}


void pop (SStack s){
	s->quantos--;
}

int top (SStack s){
	return (s->valores[s->quantos-1]);
}

int empty (SStack s){
	return (s->quantos == 0);
}






typedef struct stack{
	int N;
	int *valores; //valores é um array de tamanho N
	int quantos;
} STACK, *SStack;


void initStack (SStack s, int tamanho){
	s->valores = (int *) malloc(tamanho * sizeof(int));
	s->N = tamanho;
}


//malloc para reservar memoria(realloc, calloc)
//free para libertar memoria

typedef struct lista{
	int valor;
	struct lista *prox;
} *Lista

//x = []
x = NULL;
//Y=42;
Y = malloc(sizeof(struct lista));
y->valor = 42;
y->prox = NULL; 


Lista newLista(int x, Lista l){
	Lista r;
	r  = malloc(sizeof(struct lista));
	r->valor = x;
	r->prox = l;
	return r;
}


//z = [1,2,3]
//z = malloc(sizeof(struct lista));
//z->valor = 1;
//z->cauda = malloc(sizeof(struct lista));
//z->cauda->valor = 2;
//z->cauda->cauda = malloc(sizeof(struct lista));
//z->cauda->cauda->valor = 3;
//z->cauda->cauda->cauda = NULL;

//z=[1,2,3]
z = NULL;
z = newLista(3,z);
z = newLista(2,z);
z = newLista(1,z);

Lista fromArray(int v[], int N){
	//constroi uma lista com os N elementos de v
	//lista por ordem inversa
	Lista r = NULL;
	int i;
	for(i=N-1; i>=0; i--)
		r = newLista(v[i],r):

	return r;
}


Lista fromArray(int v[], int N){
	Lista r = NULL;
	if(N>0){
		r = newLista(v[0],fromArray(v+1,N-1));
	}
}	


Lista cloneL (Lista l){
	Lista r;

	if(l==NULL) r = NULL;
	else  
		r = newLista(l->valor,cloneL(l->prox));
	
	return r;
}


Lista cloneL (Lista l){
	Lista r, ult;

	if(l==NULL) r = NULL;
	else {
		r = malloc(sizeof(struct lista));
		r->valor = l->valor;
		ult = r;
		l = l->prox;

		while (l != NULL){
			nova = malloc(sizeof(struct lista));
			nova->valor = l->valor;
			ult->prox = nova;
			ult = nova;
			l = l->prox;
		}
		ult->prox = NULL;
	}

	return r;
}


Lista cloneL (Lista l){
	Lista r, ult;

	if(l==NULL) r = NULL;
	else {
		r = malloc(sizeof(struct lista));
		r->valor = l->valor;
		ult = r;
		l = l->prox;

		while (l != NULL){
			ult->prox = malloc(sizeof(struct lista));
			ult = ult->prox;
			ult->valor = l->valor;
			l = l->prox;
		}
		ult->prox = NULL;
	}

	return r;
}



Lista cloneL (Lista l){
	Lista r, ult, *sitio;

	sitio = &r;

	while (l != NULL){
		*sitio = malloc(sizeof(struct lista));
		(*sitio)->valor = l->valor;
		l = l->prox;
		sitio = &((*sitio)->prox);
	}
	*sitio = NULL;
	return r;
}


Lista insereOrd (Lista l, int x){
	//l esta ordenada

	Lista nova, pt = l, ant;

	//criar celula para o novo elemento
	nova = malloc(sizeof (struct lista));
	nova->valor = x;

	if(l==NULL || l->valor > x){
		//inserir no inicio
		nova->prox = l;
		l = nova;
	}
	else{
		//percorrer a lista ate encontrar um elemento maior do que x
		while (pt != NULL && pt->valor < x){
			ant = pt;
			pt = pt->prox;
		}
	
		//inserir a celula nesse sitio da lista
		nova->prox = pt;
		ant->prox = nova;
	}
	
	return l;
}


Lista insereOrd (Lista l, int x){
	//l esta ordenada

	Lista nova, *sitio;

	//criar celula para o novo elemento
	nova = malloc(sizeof (struct lista));
	nova->valor = x;

	sitio = &l;
	while (*sitio != NULL && (*sitio)->valor < x)
		sitio = &((*sitio)->prox);

	nova->prox = *sitio;
	*sitio = nova;
	
	
	return l;
}


void insereOrd (Lista *l, int x){
	//l esta ordenada

	Lista nova;

	//criar celula para o novo elemento
	nova = malloc(sizeof (struct lista));
	nova->valor = x;

	sitio = &l;
	while (*l != NULL && (*l)->valor < x)
		l = &((*l)->prox);

	nova->prox = *l;
	*l = nova;
		
}



Lista remove(Lista *l, int x){
	//l esta ordenada
	//sucesso se possivel, 0 se correr bem , 1 se o elemento nao existe na lista
	Lista pt,ant;
	//assume lista ordenada
	//procurar x em l
	pt = l;

	while(pt != NULL && pt->valor < x){
		ant = pt;
		pt = pt->prox;
	}
	if(pt != NULL && pt->valor == x){
		//encontrado
		if (pt != l) ant->prox = pt->prox;
		else l = l->prox;
		free(pt);
	}
	else{
		//nao exitse
	}


	return l;
}


lista remove(Lista *l, int x){
	Lista pt, *sitio;

	sitio = &l;
	while(*sitio != NULL && (*sitio)->valor = x){
		sitio = &((*sitio)->prox);
	}

	if(*sitio != NULL && (*sitio)->valor == x){
		pt = *sitio;
		*sitio = (*sitio)->prox;
		free(pt);
	}
	else{
		//nada
	}

	return l;
}


/////////////Arvores Binarias\\\\\\\\\\\\\\

typedef struct arvore{
	int valor;
	struct arvore *esq, *dir;
}*Arv;


int compLista(Lista l){
	int r;
	r=0;
	while( l != NULL){
		l = l->prox;
		r++; 
	}
	return r;
}




int compArv (Arv a){
	int r=0;

	if( a != NULL){
		r = 1 + compArv(a->esq) + compArv(a->dir);
	}
	return r;  
}



Arv arvFromArray(int v[], int N){
	Arv r = NULL;
	int m = N/2;

	if(N > 0){
		r = malloc(sizeof(struct arvore));
		r->valor = v[m];
		r->esq = arvFromArray(v,N)
		r->dir = arvFromArray(v+m+1,N-m-1);
	}

	return r;
}


void travessiaParaArray(Arv a, int v[], int N){
	//retorna o numero de elementos escritos no array
	int r = 0;
	if(a == NULL && N<=0)
	else {
		r += travessiaParaArray(a->esq, v+r, N-r);
		if(r < N){
			v[r] = a->valor;
			r++;
			r += travessiaParaArray(a->dir, v+r, N-r);
		}
	}
	return r;	
}


//Arvores binarias de procura
//binary serach tree

int search(Arv a, int x){
	//retorna verdadeiro se x existe em a
	int r;
	if (a == NULL) r=0;
	else if (a->valor == x) r=1;
	else if (a->valor > x) r= search(a->esq, x);
	else r= search(a->dir, x);

	return r;
}


//fazer uma função para inserir um novo elemento numa bst


int nexiste(char x[], int i, int j){

	for(z=i; i<j; i++){
		if(x[i] == x[j]) return 0;
	}

	return 1;
}




int difConsecutivos(char s[]){
	int i,j,res = 0, consec = 0;

	for(i=0; s[i]; i++){
		for(j=0; s[j]; j++)
			if(nexiste(s,i,j)) consec++;
		 
		if (consec > res) res = consec;

		consec = 0;
	}

	return res;
}	











































