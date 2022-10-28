
//Exercicio 1
void quadrado(int x){

    for (int i = 0; i < x; ++i)
    {
        for (int i = 0; i < x; ++i)
        {
            printf("#");
        }
    printf("\n");   
    }

}

int main(){

    int x;
    printf("Insira o tamanho do quadrado:\n");
    scanf("%i", &x);
    quadrado(x);

}

//ou

int main(){
    int n;
    printf("Tamanho quadrado:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
         putchar('#');
        }
       printf("\n");
    }
}    





//Exercicio 3 
void quadrado(int x){

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
         if (i%2==0)
             if(j%2 == 0) putchar('#');
             else putchar('_');
         else
            if (j%2 == 0) putchar('_');
            else putchar('#');
        }

        printf("\n");
    }
}






//Exercicio 2


void trianguloVertical(int x){

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < x; ++j)
        {
            if(i >= j) putchar('#');
        }

     printf("\n");  
    } 
}



//Triangulo Horizontal 

void trianguloHorizontal(int x){

    for (int i = 0; i < x; ++i)
    {
        int j = i;
        for(int k = 0; k < x - 1 - j; k++) putchar(' ');
        for(int k = 0; k < 2 * j + 1; k++) putchar('#');
        printf("\n");   
    } 
}

int circulo (int raio){

  // (x-raio)*(x-raio) + (y-raio)*(y-raio) <= r*r 

   

  int i,j, c=0;

   

  for(i=0; i<=2*raio; i++){

    for(j=0; j<=2*raio; j++){

      if(((i-raio)*(i-raio) + (j-raio)*(j-raio)) <= raio*raio){

        putchar('#');

        c++;

      }

      else putchar (' ');

    }

    putchar('\n');

  }

   

   

  return c;

}





