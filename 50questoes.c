
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>


//Pergunta 1 
void maior () 
{
    int num;
    int max=INT_MIN;
    while (1)
    {
        printf("Insira numeros(um por linha):\n");
        scanf("%d", &num);
        if (num==0) break;
        if (num>max) max=num;
    }
    printf("Maior: %d\n", max);
}


//Pergunta 2
void media () 
{
    int num;
    float soma=0;
    float total=0;
    while (1)
    {
        printf("Insira numeros(um por linha):\n");
        scanf("%d", &num);
        if (num==0) break;
        soma += num;
        total += 1;
    }
    float media = soma/total;
    printf("Media:: %.2f\n", media);
}



//Pergunta 3 
void segundo_maior () {
    int num;
    int max = INT_MIN;
    int segundo_max = INT_MIN;

    while (1)
    {
        printf("Insira numeros(um por linha):\n");
        scanf("%d", &num);
        if (num==0) break;
        if (num>max)
        {
            segundo_max=max;
            max=num;
        } else if (num>smax) segundo_max = num;
    }
    printf("segundo_max: %d\n", segundo_max);
}



//Pergunta 4
int bitsUM (unsigned int n)
 {
    int bits=0;
    while (n)
    {
        bits += (n % 2);
        n=n/2;
    }
     return bits;
}

//Pergunta 5 

int trailingZ (unsigned int n) {
    if(n % 2) return 0;
    else return 1 + trailingZ(n >> 1);
}



//Pergunta 6
int qDig (unsigned int n)
 {
    int dig=0;
    if (n==0) dig=1;
    else
    while (n)
    {
       dig++;
       n=n/10;
    }
     return dig;
}


//Pergunta 7

char *strcat(char s1[], char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; ++i);
    for (j = 0; s2[j] != '\0'; ++j, ++i) {
        s1[i] = s2[j];
    }
    s1[i] = '\0';
    return s1;
}

//OU

char* mystrcat(char s1[], char s2[]) {
    char *cat = s1;
    while(*s1) s1++;
    while((*s1 = *s2)) {s1++; s2++;}
    *s1 = '\0';
    return cat;
}


//Pergunta 8

char *strcpy(char *dest, char source[]){
	char *result = dest;
    while((*dest = *source)) { source++; dest++; }
    return result;
}


//Pergunta 9

int strcmp (char s1[], char s2[]){

	while(*s1 == *s2 && *s1) { s1++; s2++; }
    return *s1 - *s2;
}


//Pergunta 10

char *strstr (char s1[], char s2[]){
    int i,j,k;
    char * = NULL;;

    for(i=0; s1[i] != '\0' && r == NULL; i++){
        for(j=0, k=i; s2[j] != '\0' && s1[k] == s2[j]; j++, k++)
            ;
        if(s2[j] == '\0')
            r = s1 + i;
    } 
    if (s2[0] == '\0') r = s1;
       
    return r;
} 



//Pergunta 11

void strrev (char s[]){
    int i,len = strlen(s);
    char rev[len];

    for(i=0; i < len; i++) rev[i] = s[len - i - 1];
    for(i=0; i < len; i++) s[i] = rev[i];

}


//Pergunta 12 

void strnoV (char s[]){
    int i, j = 0;
    char p[strlen(s)];
    
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != 'a' ) {
            //falta adicionar as outras vogais com ||
            p[j] = s[i];
            j++;
        }
    }
    for(i=0; i<strlen(s);i++) s[i] = p[i];
}


//Pergunta 13 

void truncW (char t[], int n){

}


//PERGUNTA 14
int charOcorre(char s[], char ch){
    int i,total=0;

    for(i=0; s[i] != '\0'; i++)
        if(s[i] == ch) total++;
    
    return total;

}

char charMaisfreq (char s[]){
    char maisfreq = 0;

    int i,maxOcorre=0, freq;

    for(i=0; s[i]; i++){
        freq = charOcorre(s,s[i]);
        if(freq >= maxOcorre){
            maxOcorre = freq;
            maisfreq = s[i];
        }
    }

    return maisfreq;
}


//PERGUNTA 15
int iguaisConsecutivos (char s[]){
    int i,max = 0, consec = 1;

    for(i=0; s[i]; i++){
        if(s[i] == s[i+1]) consec++;
        else {
            if(consec > max) max = consec;
            consec = 1;
        }
    }

    return max;

}


//PERGUNTA 16
int difConsecutivos (char s[]){
}  



//PERGUNTA 17
int maiorPrefixo (char s1 [], char s2 []){
    int i;

    for(i = 0; s1[i] == s2[i] && s1[i]; i++);
        
    return i;    

} 



//PERGUNTA 18
int maiorSufixo (char s1 [], char s2 []){
    int i r=0;
    int len1 = strlen(s1) - 1;
    int len2 = strlen(s2) - 1;

    for(i=len1, j=len2; s1[i] == s2[j] && s1[i]; i--,j--) r++;

    return r;    


}

//PERGUNTA 19
int sufPref (char s1[], char s2[]){
    int i,j=0,r=0;

    for(i=0; s1[i]; i++){
        if(s1[i] == s2[j]){
            j++;
            r++;
        }    
    }

     return r;   

}



//PERGUNTA 20
int contaPal (char s[]){
    int i, word = 0, r=0;

    for(i=0; s[i]; i++){
        if(s[i] == ' ' || s[i] == '\n'){
            if(word == 1){
                r++;
                word = 0;
            }
        else word = 1;    
        }
    }

    if(word == 1) r++;

    return r;
} 




//PERGUNTA 21
int contaVogais (char s[]){
    int i, r=0;

    for(i=0; s[i]; i++){
        if(s[i] == 'A' || s[i] == 'a') r++;   
    }
    //adicionar o resto das vogais

    return r;
}


//PERGUNTA 22
int contem(char ch, char s[]){
    int i, r=0;
    char c;

    for(i=0; s[i] && r==0; i++)
        if(s[i] == ch) r=1;

    return r;
}


int contida (char a[], char b[]){
    int i, r=1;

    for(i=0; a[i] && r==1; i++){
        if(contem(a[i],b) == 0) r=0;
    }
    return r;
}


//PERGUNTA 23
int palindorome (char s[]){
    int i,j, r=1;
    int lens = strlen(s) - 1

    for(i=0, j=lens; s[i] && r==1 && i< lens/2; i++,j--){
        if(s[i] != s[j]) r=0;
    }

    return r;


}

//PERGUNTA 24
int remRep (char x[]){
    int i,j;
    for (i=0;x[i];){
        if (x[i]==x[i+1])
            for (j = i + 1; x[j]; j++) {
                x[j] = x[j + 1];
            }
        if (x[i] != x[i+1]) i++;
        }
    return i;
}



//PERGUNTA 25
int limpaEspacos (char t[]){

}


//PERGUNTA 26
void insere (int v[], int N, int x){
    int j;
    for(j=N-1; j>=0 && v[j]>x; j--)
        v[j+1] = v[j];
    v[j+1]=x;


} 


//PERGUNTA 27
void merge (int r [], int a[], int b[], int na, int nb){
    int i=j=0, k=0;

    while(k < na + nb){
        if((a[i] < b[j] && i < na) || j>=nb){
            r[k] = a[i];
            k++;
            i++;
        }
        else {
            r[k] = b[j];
            k++;
            j++
        }
    }
} 

//PERGUNTA 28
int crescente(int a[], int i, int j){
    int r=1;

    while(i<j && r==1){
        if(a[i] > a[i + 1]) r=0;
        i++;
    }

    return r;
}



//PERGUNTA 29
int retiraNeg(int v[], int N){
   
    int j,i=0;
    int count = N;
    while(i<N){
      if(v[i]<0){
        for (j = i; j<N-1; j++) v[j] = v[j + 1];
        N--;
        count--;
      }  
      else i++;
    }
    return count;
}



//Pergunta 30 
int menosFreq (int v[], int N){
    int i, freq =1, menosf = N, res = v[0];

    for(i=1; i < N; i++){
        if(v[i] == v[i-1]) freq++;
        if(v[i] != v[i-1]){
            if(freq < menosf){
                menosf = freq;
                res = v[i-1];
            }
            freq = 1;
        }

    }
    if(v[N-1] != v[N-2] && menosf > 1) 
        res = v[N-1];
    return res;
}


//PERGUNTA 31
int maisfreq (int v[], int N){
    int i, freq=1, maisf = 1, res = v[0];

    for(i=1; i<N; i++){
        if(v[i] == v[i-1]) freq++;
        if(v[i] != v[i-1]){
            if(freq > maisf){
                maisf = freq;
                res = v[i-1];
            }

            freq = 1;
        }
    }
    return res;
}

//PERGUNTA 32
int maxCres(int v[], int N){
    int i, count = 1, res = 1;

    for(i=0; i<N; i++){
        if(v[i] <= v[i+1]) count++;
        if(v[i] > v[i+1]){
            if(count > res){
                res=count;
            }
        count = 1;    
        }
    }
    return res;
}


//PERGUNTA 33
int elimRep(int v[], int n){

}









//PERGUNTA 37
int minInd (int v[], int n){
    int i, r=0;

    for(i=1; i < n; i++)
        if(s[i] < s[r]) r = i;

    return r;
    
}


//PERGUNTA 38
void somaAc (int v[], int Ac[], int N){
    int i, soma=0;

    for(i=0; i<N; i++){
        soma += v[i];
        Ac[i] = soma;
    }
}


//PERGUNTA 39
int triSup (int N, float m [N][N]){
    int i,j,r = 1;
    for(i = 0; i < N && r==1; i++) {
        for( j = 0; j < i; j++) {
            if(m[i][j] != 0) r = 0;
        }
    }
    return r;
} 



//PERGUNTA 40
void transposta (int N, float m [N][N]){
    int i,j,temp;
    for(i=0; i<N; i++){
        for(j=0; j < i; j++){
            temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

//PERGUNTA 41
void addTo (int N, int M, int a [N][M], int b[N][{M]{
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            a[i][j] = a[i][j] + b[i][j];
        }
    }
}


//PERGUNTA 42
int unionSet (int N, int v1[N], int v2[N], int r[N]){
    int i,c=0;

    for(i=0; i<N; i++){
        if(v1[i] || v2[i]){
            r[i] = 1;
            c++;
        }    
        else r[i] = 0;
    }
    return c;

}


//PERGUNTA 43
int intersectSet (int N, int v1[N], int v2[N], int r[N]){
    int c=0,i;
    for(i=0; i<N; i++){
         if(v1[i] && v2[i]) {
             r[i] = 1;
             c++;
         }    
         else r[i] = 0;
    } 
    return c;
}

//PERGUNTA 42
 int unionSet (int N, int v1[N], int v2[N], int r[N]){ 
    int i;
    for (i=0;i<N;i++){
        if(v1[i] == 1 || v2[i] == 1) r[i] = 1;
        else r[i] = 0;
    }
    return 1;
}


//PERGUNTA 43








typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;

typedef struct posicao {
    int x, y;
} Posicao;

//PERGUNTA 47
Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i;

    for(i=0; i<N; i++){
        if(mov[i] == Norte) inicial.y++;
        if(mov[i] == Sul) inicial.y--;
        if(mov[i] == Este) inicial.x++;
        if(mov[i] == Oeste) inicial.x--;
    }
    return inicial;
}



//PERGUNTA 48
int caminho(Posicao inicial, Posicao final, Movimento mov[], int N){
    
}






















