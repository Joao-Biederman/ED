#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

typedef struct
{
    int *dado;
    unsigned n;
} TVetDin;

void initVetDin(TVetDin *V, unsigned size)
{
    V->dado = (int *)malloc(size * sizeof(int));
    if (!V->dado)
    {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }
    else
    {
        V->n = size;
        return;
    }
}

void deleteVetDin(TVetDin *V)
{
    free(V->dado);
}

void printVetDin(TVetDin V)
{
    printf("[");
    for (unsigned i = 0; i < V.n; i++)
    {
        printf("%d", V.dado[i]);
        if (i < V.n - 1)
        {
            printf(", ");
        }
    }
    printf("]");
    return;
}

void insertionChange(TVetDin *V, int i)
{
    for (i; i > 0; i--)
    {
        if (V->dado[i] > V->dado[i - 1])
        {
            return;
        }
        int aux = V->dado[i];
        V->dado[i] = V->dado[i - 1];
        V->dado[i - 1] = aux;
    }
}

void insertionSort(TVetDin *V)
{
    for (int i = 0; i < V->n; i++)
    {
        insertionChange(V, i);
    }
}

int main()
{
    TVetDin lista;
    int n, x;
    float tempo;
    FILE *in;
    clock_t timeStart, timeEnd;

    in = fopen("../numeros.txt", "r");

    if (!in)
    {
        cout << "Arquivo não encontrado\n";
        exit(1);
    }

    cout << "Digite a quantidade de elementos" << endl;
    scanf("%d", &n);
    initVetDin(&lista, n);

    for (int i = 0; i < n; i++)
    {
        fscanf(in, "%d", &x);
        lista.dado[i];
    }

    timeStart = clock();

    timeEnd = clock();
    tempo = (float)(((timeEnd - timeStart) + 0.0) / CLOCKS_PER_SEC);

    printVetDin(lista);
    insertionSort(&lista);
    printVetDin(lista);

    printf("\n\nTempo:%.3f\n", tempo);
}