#include <stdio.h>

int calculo_anos();
int main()
{
    int tamanho_inicial, tamanho_final, anos;
    printf("Tamanho inicial:\n");
    do
    {
        scanf("%i", &tamanho_inicial);
    }
    while (tamanho_inicial < 9);
    printf("Tamanho final:\n");
    do
    {
        scanf("%i", &tamanho_final);
    }
    while (tamanho_final < tamanho_inicial);
    anos = calculo_anos(tamanho_inicial, tamanho_final);
    printf("Anos: %i\n", anos);
}
int calculo_anos(int ti, int tf)
{
    int y;
    for (y = 0; ti < tf; y += 1)
    {
        int nascimento = ti / 3;
        int morte = ti / 4;
        ti = ti + nascimento - morte;
    }
    return y; 
}