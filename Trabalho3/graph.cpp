#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#define MAX_VERTICE 30

class graph
{
private:
    string vertice[MAX_VERTICE];
    string edgeName[MAX_VERTICE][MAX_VERTICE];
    int adjacencyDistance[MAX_VERTICE][MAX_VERTICE];

    int size;

public:
    graph();
    ~graph();

    void insertVertice(string name);

    void setEdge(int v1, int v2, int distance, string name);

    void removeVertice(string name);
    void removeEdge(int v1, int v2);

    void printVertice();
    void printEdges();
};

graph::graph()
{
    for (int i = 0; i < MAX_VERTICE; i++)
    {
        vertice[i] = "\n";
        for (int j = 0; j < MAX_VERTICE; j++)
        {
            edgeName[i][j] = "/0";
            adjacencyDistance[i][j] = 0;
        }   
    }   
}

graph::~graph()
{
}

void graph::insertVertice(string name)
{
    if (size >= MAX_VERTICE)
    {
        cout << "Tamanho máximo de grafo atingido" << endl;
        return;   
    }

    for (int i = 0; i < size; i++)
    {
        if (!name.compare(vertice[i]))
        {
            cout << "Vertice com o nome "<< name <<" já inserido" << endl;
            return;
        }
    }

    vertice[size] = name;
    size++;
    return;
}

void graph::setEdge(int v1, int v2, int distance, string name)
{
    if (v1 > size || v1 < 0 || v2 < 0 || v2 > size)
    {
        cout << "Vertices fora de alcance" << endl;
    }
    
    edgeName[v1][v2] = name;
    adjacencyDistance[v1][v2] = distance;
}

void graph::printVertice()
{
    for (int i = 0; i < size; i++)
    {
        cout << vertice[i] << endl;
    }
}

void graph::printEdges()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            cout << vertice[i] << "  ->"  << edgeName[i][j] << " " << adjacencyDistance[i][j] << " ->" << vertice[j] << endl;
        }
    }
    
}

int main(){
    graph grafo;

    grafo.insertVertice("nome0");
    grafo.insertVertice("nome1");
    grafo.insertVertice("nome2");
    grafo.insertVertice("nome2");
    grafo.insertVertice("nome3");

    grafo.setEdge(0, 1, 3, "josé");

    grafo.printVertice();
}