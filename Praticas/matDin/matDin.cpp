#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class matDin
{
private:
    int rows;
    int cols;

    T **mat;
public:
    matDin();
    matDin(int r, int c);
    matDin(const matDin<T> &A);
    ~matDin();

    void fill(T value);
    void set(int i, int j, T value);
    T get(int i, int j);

};

template <class T>
matDin<T>::matDin()
{
    rows = 1;
    cols = 1;

    mat = new T*[rows];
    for (int i = 0; i < rows; i++)
        mat[i] = new T[cols];
}

template <class T>
matDin<T>::matDin(int r, int c)
{
    if (c == 0)
        c = r;

    rows = r;
    cols = c;

    mat = new T*[rows];
    for (int i = 0; i < rows; i++)
        mat[i] = new T[cols];
}

template <class T>
matDin<T>::matDin(const matDin<T> &A)
{
    this->cols = A.cols;
    this->rows = A.rows;

    for (int i = 0; i < this->rows; i++)
        this->mat[i] = new T[this->cols];
    
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            this->set(i, j, A.mat[i][j]);
}

template <class T>
matDin<T>::~matDin()
{
    cout << "\nDestruindo matriz...\n";

    delete[] mat;
    
}

template <class T>
void matDin<T>::fill(T value) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat[i][j] = value;
}

template <class T>
void matDin<T>::set(int i, int j, T value){
    this->mat[i][j] = value;
}

template <class T>
T matDin<T>::get(int i, int j){
    return mat[i][j];
}

int main() {
    matDin <int> matriz(5, 5);

    matriz.fill(73);
    cout << "Conteudo da matriz 1 na posição [3][4] " << matriz.get(3,4) << endl;

    cout << "Criando matriz de copia nomeada matriz 2, a partir da matriz 1..." << endl;

    matDin <int> matriz2(matriz);

    cout << "Copia criada." << endl;

    cout << "Modificando conteudo da matriz 1" << endl;
    matriz.set(3, 4, 5);

    cout << "Conteudo da matriz 2, copia da matriz 1, na posição [3][4] " << matriz2.get(3, 4) << endl;
    cout << "Conteudo da matriz 2, copia da matriz 1, na posição [3][1] " << matriz2.get(3, 1) << endl;

    cout << "Conteudo da matriz 1 na posição [3][4] " << matriz.get(3, 4) << endl;
}