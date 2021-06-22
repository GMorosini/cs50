#include <stdio.h>
#include <math.h>

int main() 
{
    int notas[6] = {100, 50, 20, 10, 5, 2};
    double moedas[6] = {1.00, 0.50, 0.25, 0.10, 0.05, 0.01};
    double valor;
    
    scanf("%lf", &valor);
    
    //NOTAS
    printf("NOTAS:\n");
    
    for (int i = 0; i < 6; i++)
    {
        int n = valor / notas[i];
        valor -= n * notas[i];
        
        printf("%i nota(s) de R$ %i.00\n", n, notas[i]);
    }
    
    //MOEDAS
    printf("MOEDAS:\n");
    
    for (int i = 0; i < 6; i++)
    {
        int m = valor / moedas[i];
        valor -= m * moedas[i];
    
        printf("%i moeda(s) de R$ %.2lf\n", m, moedas[i]);
    }
}