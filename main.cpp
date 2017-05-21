#include <cstdlib>
#include <cstdio>

using namespace std;

int numero_digitos(int temp)
{
    int ndigitos=1;
    while (temp/10 != 0)
    {
        temp=temp/10;
        ndigitos++;
    }
    return ndigitos;
}

int reversa(int numero)
{
    int reverso=0;
    int ndigitos=1;
    
    ndigitos=numero_digitos(numero);
    
    while (ndigitos>0 )
    {
        int potencia=1;
        int j=ndigitos;
        while (j >1)
        {
            potencia=potencia*10;
            j--;
        }
        reverso=reverso+(numero%10)*potencia;
        numero=numero/10;
        ndigitos--;
    }
    return reverso;
}


int es_primo(int numero)
{
    int es_primo =1;
    int i=1;
    while (i<numero){
        int modulo=numero%i;
        if (i!=1 && i!=numero && modulo==0){
            es_primo=0;
        }
        i++;
    }    
    return es_primo;
}

int main() {
    int numero=1;
    int contador=0;
    while (contador < 1000){
        if (es_primo(numero)==1){
            if (numero_digitos(numero)>1)
            {
                if(es_primo(reversa(numero)))
                {
                    contador++;
                    printf("%d\n",numero);
                    if (contador==201)
                    {
                        break;
                    }
                }
            }
        }
        numero++;
    }
    printf("El primo número %d es: %d \n",contador,numero);
    return 0;
}