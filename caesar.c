#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>

bool checar_chave();
int main(int argc, string argv[])
{
    if (argc != 2 || checar_chave(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string texto = get_string("plaintext: ");
        printf("ciphertext: ");

        int chave = atoi(argv[1]);
        int formato = 0;

        for (int i = 0, n = strlen(texto); i < n; i++)
        {
            char c = texto[i];
            if (isalpha(c))
            {
                formato = 65;
                if (islower(c))
                {
                    formato = 97;
                }
                printf("%c", (c - formato + chave) % 26 + formato);
            }
            else
            {
                printf("%c", c);
            }
        }
    }
    printf("\n");
}
bool checar_chave(string k)
{
    int acumulador = 0;
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if (k[i] < 58 && k[i] > 47)
        {
            acumulador++;
        }
    }
    if (acumulador == strlen(k))
    {
        return false;
    }
    else
    {
        return true;
    }
}
