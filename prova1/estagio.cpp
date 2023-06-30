// João Vitor Biederman
// Questão 2

#include <iostream>
using namespace std;

const int MAX_ALUNOS= 1000;

int main(){
    int i, indice_melhor, n;
    int turma=1;

    struct
    {
        int codigo, media;
    } alunos [MAX_ALUNOS];

    FILE *in = fopen("estagio.in", "r");

    if (!in){
        fcloseall();
        cout << "Houve um erro na abertura do arquivo de leitura. Abortando programa" << endl;
        exit(1);
    }

    FILE *out = fopen("estagio.out", "w");

    if (!out) {
        fcloseall();
        cout << "Houve um erro na abertura do arquivo de escrita. Abortando programa" << endl;
        exit(2);
    }

    while (fscanf(in, "%d", &n) && n) // le numero de alunos das turmas
    {
        // le dados dos alunos
        for (int i = 0; i < n; i++)
        {
            fscanf(in, "%d %d", &alunos[i].codigo, &alunos[i].media);
        }

        // procura a maior media
        int maior = 0;
        for (int i = 0; i < n; i++)
        {
            if (alunos[i].media > maior) {
                maior = alunos[i].media;
            }
        }

        // escreve a resposta
        fprintf(out, "Turma %d\n", turma++);
        for (int i = 0; i < n; i++) {
            if (alunos[i].media == maior) {
                fprintf(out, "%d ", alunos[i].codigo);
            }
        }
        fprintf(out, "\n\n");
    }
    
    fcloseall();
    return 0;
}