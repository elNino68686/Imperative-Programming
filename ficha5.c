#include <stdio.h>
#include <math.h.h>

typedef struct aluno {
	int numero;
	char nome[100];
	int miniT [6];
	float teste;
} Aluno;

//a.numero
//a->numero <=> (*a).numero



//PERGUNTA 1 

int nota (Aluno a){
	//notas dos minitestes * 0.3 -> >=8
	//nota do teste * 0.7 -> >= 8

	int i, notaF = 0; 
	float somaMiniT = 0;
	
	for(i=0; i<6; i++)
		somaMiniT += a.miniT[i];

	//12 -> 20 
	//soma -> x
	somaMiniT = (somaMiniT * 20) / 12;

	if(somaMiniT >=8 && a.teste >=8)
		notaF = round(somaMiniT * 0.3 + a.teste * 0.7);


	return notaF;
}

//PERGUNTA 2

int procuraNum(int num, Aluno t[], int N){

	int i, r=-1;

	for(i=0; i<N && t[i].numero<num; i++);
	//sai do ciclo quano: i==N ou t[i].numero >= num	
	
	if(i<N && t[i].numero == num)
		r = i;

	return r;
	
}


//PERGUNTA 3

void ordenaPorNum (Aluno t[], int N){
	int i,j,min;
	Aluno tmp;

	for(i=0; i<N; i++){
		min = i;
		for(j=i+1; j<N; j++)
			if(t[j].numero < t[min].numero)
				min = j;

		tmp = t[i];
		t[i] = t[min];
		t[min] = tmp;	
	}
}


//PERGUNTA 4

void criaIndPorNum(Aluno t[], int N, int ind[]){
	int i, j, min;
	int tmp;

  for(i=0; i<N; i++)
  ind[i] = i;

  for(i=0; i<N; i++)
  	min = i;

  for(j=i+1; j<N; j++)
  	if(t[ind[j]].numero < t[ind[min]].numero)
  		min = j;

  //swap indices     
  tmp = ind[i];
  ind[i] = ind[min];
  ind[min] = tmp;
	
} 

//ou
/*int bubbleInd(Aluno t [], int N, int ind[]){

  int i, maxIndTroca=0;

  int tmp;

   

  for(i=1; i<N; i++)

    if(t[ind[i]].numero < t[ind[i-1]].numero){

      tmp = ind[i-1];

      ind[i-1] = ind[i];

      ind[i] = tmp;

      maxIndTroca = i;

    }

   

  return maxIndTroca;

}



void criaIndPorNum (Aluno t [], int N, int ind[]){

  int i;

  for(i=0; i<N; i++)

    ind[i] = i;

     

  while(N = bubbleInd(t,N,ind));

 }  

   */

//PERGUNTA 5
void imprimeTurmaInd (int ind[], Aluno t[], int N){
	int i;

	for(i=0; i<N; i++)
		imprimeAluno(t + ind[i]);
}


//PERGUNTA 6
int procuraNumInd(int num, int ind[], Aluno t[], int N){
	int i, indice = -1;

	for(i=0; i<N && t[ind[i]].numero > num; i++);

	if(i<N && t[ind[i]].numero == num)
		indice = i;
	    //ou indice = ind[i]  se quiser a posição no array original (sem estar ordenado)



	return indice;
}


//PERGUNTA 7













