// João Vitor Biederman
// Questão 3

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    FILE *in = fopen("hanoi.in", "r");

    if (!in){
        fcloseall();
        cout << "Houve um erro na abertura do arquivo de leitura. Abortando programa" << endl;
        exit(1);
    }

    FILE *out = fopen("hanoi.out", "w");

    if (!out) {
        fcloseall();
        cout << "Houve um erro na abertura do arquivo de escrita. Abortando programa" << endl;
        exit(2);
    }

    int x, count = 0;
    while (fscanf(in, "%d", &x) && x)
    {
        fprintf(out, "Teste %d\n", ++count);
        fprintf(out, "%d\n\n", int(pow(2, x)) - 1);
    }
    
    fcloseall();
}