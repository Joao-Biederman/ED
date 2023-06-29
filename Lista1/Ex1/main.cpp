#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    char *dados;
    unsigned n;
} TVetDin;

void initVetDin(TVetDin *V, unsigned size){
    V->dados = (char*)malloc(size*sizeof(char));
    if (!V->dados)
    {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    } else {
        V->n = size;
        return;
    }
}

void deleteVetDin(TVetDin *V)
{
    free(V->dados);
}

void printVetDin(TVetDin V){
    printf("[");
    for (unsigned i = 0; i < V.n; i++)
    {
        printf("%d", V.dados[i]);
        if (i < V.n - 1)
        {
            printf(", ");
        }
    }
    printf("]");
    return;
}

int main(int argc, char const *argv[])
{
    FILE *entrada, *saida;
    int M=0, N=0; // Tamanho de p (palavra a ser buscada) e t (tamanho da cadeia de busca)
    TVetDin p, t;    

    entrada = fopen("genoma.in", "r");

    if(!entrada)
    {
        cout << "Arquivo não encontrado\n";
        exit(1);
    }

    while (!feof(entrada))
    {
        /* code */

        fscanf(entrada, "%d", &M);
            
        fscanf(entrada, "%d", &N);

        if(M > N)
        {
            cout << "A string P não pode ser maior do que a T\n";
            exit(1);
        }

        initVetDin(&p, M);
        initVetDin(&t, N);
        int ocorrenciaC[N], ocorrenciaI[N];

        fscanf(entrada, "%s", p);
        fscanf(entrada, "%s", t);

        cout << M << " " << N << endl;
        cout << p.dados << endl;
        cout << t.dados << endl;

    }
    
    fclose(entrada);

    return 0;
}
