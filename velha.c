#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char velha [3][3];
void mostrar_velha();
bool validar_jogada();
char mudar_jogador();
bool fim_de_jogo();
int main()
{
    int cont = 49;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            velha [i][j] = cont;
            cont++;
        }
    }
    mostrar_velha();
    bool jogada;
    char simbolo = 'X';
    do
    {
        do 
        {
            int po;
            printf("Vez do jogador %c !!\n", simbolo);
            printf("Posição: ");
            scanf("%i", &po);
            jogada = validar_jogada(simbolo, po);
            if (jogada == false)
            {
                printf("JOGADA INVÁLIDA!\n");
            }
        }
        while (jogada == false);
        system("clear");
        mostrar_velha();
        simbolo = mudar_jogador(simbolo);
        fim_de_jogo();
    }
    while (fim_de_jogo() == false);
    printf("JOGO FINALIZADO!!\n");
}
void mostrar_velha()
{
    for (int i = 0; i < 3; i++)
    {
        printf("|---|---|---|\n");
        for (int j = 0; j < 3; j++)
        {
            printf("|  %c", velha[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("|---|---|---|\n");
}
bool validar_jogada(int S, int P)
{
    P += 48;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (velha[i][j] == P)
            {
                velha[i][j] = S;
                return true;
            }
        }
    }
    return false;
}
char mudar_jogador(int s)
{
    s = (s == 'X') ? 'O': 'X';
    return s;
}
bool fim_de_jogo()
{
    //Linhas
    
    for (int i = 0; i < 3; i++)
    {
        if (velha[i][0] == velha[i][1] && velha[i][1] == velha[i][2])
        {
            return true;  
        }
    }
    
    //Colunas
    
    for (int j = 0; j < 3; j++)
    {
        if (velha[0][j] == velha[1][j] && velha[1][j] == velha[2][j])
        {
            return true;  
        }
    }
    
    //Diagonais
    
    if (velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2] && velha[0][0] == velha[2][2])
    {
        return true;
    }
    
    if (velha[0][2] == velha[1][1] && velha[1][1] == velha[2][0] && velha[0][2] == velha[2][0])
    {
        return true;
    }
return false;
}
