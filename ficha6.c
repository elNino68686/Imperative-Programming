//FICHA 6
#define Max 10;

//LIFO
typedef struct staticStack {
int sp;
int values [Max];
} STACK, *SStack;

//typedef struct statickstack *SStack

void SinitStack (SStack s){
	s->sp = 0; 
}



int SisEmpty (SStack s){
	return (s->sp == 0);
}



int Spush (SStack s, int x){
	int r =1;
	if (s->sp < Max) {
		s->values[s->sp++] = x;
		r=0;
	}
	return r;		 
} 


int Spop (SStack s, int *x){
	int r=1;
	if(s->sp > 0){
		s->sp--;
		*x = s->values[--s->sp];
		r=0;

	}
	return r;
} 



int Stop (SStack s, int *x){
	int r=1;
	if(s->sp > 0){
		*x = s->values[s->sp-1];
		r=0;

	}
	return r;	
} 



 
//FIFO
typedef struct staticQueue {
	int front;
	int length;
	int values [Max];
} QUEUE, *SQueue;


void SinitQueue (SQueue q){
	q->lenght = 0;
	q->front = 0; 
} 



int SisEmptyQ (SQueue q){
	return (q->lenght == 0);
}



int Senqueue (SQueue q, int x){
	int r=1;
	if (q->lenght < Max){
		r=0;
		q->values[(q->front + q->lenght) % Max] = x;
		q->lenght++;  
	}
	return r;
}


int Sdequeue (SQueue q, int *x){
	int r=1;
	if(q->lenght > 0){
		r=0;
		*x = q->values[q->front];
		q->front = (q->front + 1) % Max;
		q->lenght--;
	}
	return r;
}


 int Sfront (SQueue q, int *x){
 	int r=1;
	if(q->lenght > 0){
		r=0;
		*x = q->values[q->front];
	}
	return r;
 }



typedef struct dinStack {
	int size; // guarda o tamanho do array values
	int sp;
	int *values;
} *DStack;


void Dinit(DStack s){
	s->sp = 0;
	s->size = Max;
	s->values = malloc(sizeof(int) * s->size);
}


int SisemptyD(DStack s){
	return (s->sp == 0);
}


int Dpush (SStack s, int x){
	int r=0;
	if(s->sp == s->size)
		r = dupStack(s);
	if(r==0)
		s->values[s->sp++] = x;
	return r;
}


int dupStack(DStack s){
	int r=1,i;
	int *t = malloc(sizeof(int) * 2 * s->size);
	if(t != NULL){
		r=0;
		for(i=0; i < s->size; i++)
			t[i] = s->values[i];
		free(s->values);
		s->values = t;
		s->size *=2;
	}
	return r; 
}


//realloc vê se existe espaço logo a segui
//se existir realoca se não faz malloc












