
//Exercico 1
 float multInt1 ( int n, float m)
{
    float r=0;
    for (int i = 0; i < n; ++i)
    {
        r+=m;
    }
    return r;
}


//Exercicio 2 
float multInt2 ( int n, float m)
{
    float r=0;
    while(n>0)
    {
        if (n%2 == 1) r+=m;
        n /=2;
        m *=2;
    }
    return r;
}

float multInt3 (int n, float m, int *count){
    float r=0;
    *count =0;

    while(n>0)
    {
        if (n%2 == 1) r+=m;
        n /=2;
        m *=2;
        (*count)++;
    }
    return r;

}


//Exercicio 3

int mdc1(int a, int b){

    int menor, r=1;
    if (a>b) menor = b;
    else menor = a;

    while (menor >0 && r==1){
        if(a%menor==0 && b%menor==0){
            r = menor;
        }
        menor--;
    }
    return r;
}


//Exercicio 4
int mdc2 (int a, int b)
{
    while ( a>0 && b>0)
    {

        if (a>b) a-=b;
        else b-=a;
    }
    return (a+b);    
}

int mdc3 (int a, int b, int *count)
{
    *count=0;
    while ( a>0 && b>0)
    {

        if (a>b) a-=b;
        else b-=a;
        (*count)++;
    }
    return (a+b);    
}



//Exercicio 5 
int mdc4 (int a, int b, int *count)
{
    *count=0;
    while ( a>0 && b>0)
    {

        if (a>b) a%=b;
        else b%=a;
        (*count)++;
    }
    return (a+b);    
}






//Exercicio 6

int fib1 (int n){
    int r;
    if (n=0) r=0;
        else if (n=1) r=1;
            else r = fib(n-1) + fib(n-2);

    return r;
}



int fib2 (int n){

    int f;
    int f1 = 1;
    int f2 = 1;

    for(int i = 3; i<=n; i++){
        f = f2;
        f2 += f1;
        f1 = f;
    }

    return f2;
}

























