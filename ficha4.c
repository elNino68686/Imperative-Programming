#include <stdio.h>
#include <string.h>

//Parte 1
//EXERCICIO 1

int contaVogais(char *s)
{
    int i,j, count=0;
    char v[10] = "AaEeIiOoUu";

    for(i=0; s[i] != '\0'; i++)
        for (j = 0; j < 10; j++)
            if (s[i] == v[j]) count++;

    return count;
}

//ou

int isVogal(char c){

	int r=0;
	if(c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' || c=='u' || c=='U')
		r=1;

	return r;
}

int contaVogais(char *s){
	int soma=0,i;

	for(i=0; s[i] != '\0'; i++)
		if(isVogal(s[i])) soma++;

	return soma;
}


//Exercicio 2

int retiraVogaisRep(char *s){
	char aux[strlen(s)];
	int r,w;

	for(r=0, w=0; s[r]!= '\0'; r++)
		// nao quero escrever no aux quando:
		//s[r] == s[r+1] && isVogal(s[r])
		//quero escrever quando !(s[r] == s[r+1] && isVogal(s[r])) <==> s[r] != s[r+1] || !(isVogal(s[r]))
		if(s[r]!=s[r+1] || !(isvogal(s[r])))
			aux[w++] = s[r];

	aux[w] = '\0';
	strcpy(s,aux);

	return(r-w);
}


int retiraVogaisRep(char *s){
	int r,w;

	for(r=0, w=0; s[r]!= '\0'; r++)
		if(s[r]!=s[r+1] || !(isvogal(s[r])))
			s[w++] = s[r];

	s[w] = '\0';
	

	return(r-w);
}


//EXERCICIO 3

int duplicaVogais(char *s){
	int vogais = contaVogais(s);
	char aux[strlen(s) + vogais];
	int r,w;

	for(r=0, w=0; s[r]!='\0'; r++){
		aux[w++]=s[r];
		if(isVogal(s[r])){
			aux[w++]=s[r];
		}
		
	}
	aux[w]='\0';
	strcpy(s,aux);

	return vogais;
}	


int duplicaVogais(char *s){
	int vogais = contaVogais(s);
	int r=strlen(s)-1;
	int w=r+vogais;

	s[w+1]='\0';

	while(r>=0){
		s[w--]=s[r--];
		if(isVogal(s[r]))
			s[w--]=s[r];
	}
	return vogais;
}	


//PARTE 2

//Exercicio 1

int ordenado (int v[], int N){
	int i, r=1;

	for(i=0; i<N-1 && r==1; i++);
		if(a[i] > a[i+1])
			r=0;

	return r;	
} 

//EXERCICIO 2

void merge (int a[], int na, int b[], int nb, int r[]){
	int i,j,x;
	i=j=x=0;

	for(x=0; x < na + nb; x++){
		if(a[i] < b[j] && i < na || j == nb)
			r[x] = a[i++];
		else
			r[x] = b[j++];			
	}
}

//ou

void merge (int a[], int na, int b[], int nb, int r[]){
	int ra=0, rb=0, w=0;

	while(ra<na && rb<nb){
		if(a[ra] < b[rb])
			r[w++] = a[ra++];
		else
			r[w++] = b[rb++];
	}

	//apenas entra num dos seguintes whiles
	//condições quando um dos arrays termina e outro
	//ainda tem elementos
	while(ra<na)
		r[w++] = a[ra++];

	while(rb<nb)
		r[w++] = b[rb++];
}


//EXERCICIO 3


























