#include <stdio.h>

//EXERCICIO 2
void swapM(int *x, int*y){

	int temp1 = *x;
	int temp2 = *y;
	*x = temp2;
	*y = temp1;

	// int temp = *x;
	// *x = *y;
	// *y = temp;
}


//EXERCICIO 3
void swap(int v[], int i, int j){

	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;

	//swapM(&v[i], &v[j]);

	//swapM(v+i, v+j);
}

//&v[i] -> &(*(v+i))


//EXERCICIO 4
int soma(int v[], int N){

	int i,soma = 0;

	for(i = 0; i<N; i++){
		soma += v[i];
	}

	//for(i = 0; i<N; soma += v[i], i++);

	//for(i = 0; i<N; soma += v[i++]);

	return soma;
}


//EXERCICIO 5
void inverteArray(int v[], int N){

	int i;
	for(i=0; i<N; i++, N--){
		swap(v,i,N-1);
	}
	
}



//EXERCIO 6
int maximum(int v[], int N, int *m){

int r =1;

	if(N>0){
		*m = v[0];
		for (int i = 1; i < N; ++i){
			if(v[i] > *m){
				*m = v[i];
			}
		}
		
		r = 0;
	}

	return r;
}




//EXERCICIO 7
void quadrados (int q[], int N){

	int i;
	//
	//for (i = 0; i < N; ++i){
	//	q[i] = i*i;
	//}

	if(N>0){
		q[0] = 0;
		for(i=1; i<N; i++){
			q[i] = q[i-1] + (2*i-1); // ... + (2*(i-1) + 1)
		}
	}

// o quandrado do numero n é igual á soma dos n primeiros impares
}




//EXERCICIO 8
void pascal(int v[], int N){


	if(N==1) V[0] = 1;
	else{
		int linhaanterior[N-1];
		pascal(linhaanterior,N-1);
		v[0] = 1;
		v[N-1] = 1;
		for(int i=1; i<N-1; i++){
			v[i] = linhaanterior[i] + linhaanterior[i-1];
		}
	}
}




















