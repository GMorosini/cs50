#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main()
{
    //Obter texto do usúario
    string text = get_string("Text: ");
    
    int count_f = 0;
    int count_p = 1;
    int count_l = 0;

    //Contar letras, palavras e frases
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] > 64)
        {
            count_l++;
        }
        if (text[i] == 32)
        {
            count_p++;
        }
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            count_f++;
        }
    }
    printf ("Letras: %i\n", count_l);
    printf ("Palavras: %i\n", count_p);
    printf ("Frases: %i\n", count_f);
    
    //Calculo da faixa etária
    float L = (count_l * 100.0f) / count_p;
    float S = (count_f * 100.0f) / count_p;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index > 0)
    {
        printf("Grade %i\n", index);
    }
    else 
    {
        printf("Before Grade 1\n");
    }
}
