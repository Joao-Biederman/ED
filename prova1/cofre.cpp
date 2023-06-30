// João Vitor Biederman
// Questão 1

#include <iostream>
#include <cstdio>
using namespace std;

class cofre
{
private:
    int saldo;
public:
    cofre();
    ~cofre();
    void atualizarSaldo(int x);
    void setSaldo(int x);
    int getSaldo();
};

cofre::cofre()
{
    saldo = 0;
}

cofre::~cofre(){

}

void cofre::atualizarSaldo(int x) {
    this->saldo += x;
}

void cofre::setSaldo(int x) {
    this->saldo = x;
}

int cofre::getSaldo() {
    return this->saldo;
}

int main(){
    FILE *in = fopen("cofre.in", "r");

    if (!in){
        cout << "Houve um erro na abertura do arquivo de leitura. Abortando programa" << endl;
        exit(1);
    }

    FILE *out = fopen("cofre.out", "w");

    if (!out) {
        cout << "Houve um erro na abertura do arquivo de escrita. Abortando programa" << endl;
        exit(2);
    }

    int n, count = 0;
    cofre joaozinho, zezinho;
    
    while (fscanf(in, "%d", &n) && n)
    {
        fprintf(out, "Teste %d\n", ++count);

        joaozinho.setSaldo(0);
        zezinho.setSaldo(0);

        for (int i = 0; i < n; i++)
        {
            int j, z;
            fscanf(in, "%d %d", &j, &z);
            joaozinho.atualizarSaldo(j);
            zezinho.atualizarSaldo(z);
            fprintf(out, "%d\n", joaozinho.getSaldo()-zezinho.getSaldo());
        }
        
        fprintf(out, "\n");
    }
        
    fcloseall();
    return 0;
}