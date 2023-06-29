#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX_M = 80;
#define MAX_N = 50;

int construcao(int mapa[80][50])
{
    return 1;
}

int main(int argc, char const *argv[])
{
    FILE *in, *out;

    in = fopen("imagem.in", "r");
    if(!in)
    {
        printf("ERRO 1: O arquivo 'imagem.in' não foi encontrado.");
        exit(1);
    }

    out = fopen("imagem.out", "w");
    if(!out)
    {
        printf("ERRO 2: O arquivo 'imagem.out' não foi encontrado.");
        exit(2);
    }

    int m, n, cosntrCount, teste=0;
    char mapa[80][50];

    // fscanf(in, "%d %d", &m, &n);
    // printf("%d %d\n", m, n);


    while (fscanf(in, "%d %d", &m, &n) && m && n)
    {
        fprintf(out, "Teste %d\n", ++teste);
        cosntrCount = 0;


        for (int i = 0; i < m; i++)
                fscanf(in, "%s\n", &mapa[i]);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << mapa[i][j];
            cout << "\n";
        }
    }

    return 0;
}
