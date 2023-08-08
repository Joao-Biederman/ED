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
    graph(const graph &A);
    ~graph();

    void insertVertice(string name);

    void setEdge(int v1, int v2, int distance, string name);

    void removeVertice(int v);
    void removeEdge(int v1, int v2);

    void printVertice();
    void printEdges();

    void depthFirstSearch(int start);
    void breadthFirstSearch(int start);
    void dijkstra(int start, int final);
    void fleury(int vertice);

    int goodman();
    int isEulerian();
};

graph::graph()
{
    size = 0;
    for (int i = 0; i < MAX_VERTICE; i++)
    {
        vertice[i] = "\0";
        for (int j = 0; j < MAX_VERTICE; j++)
        {
            edgeName[i][j] = "\0";
            adjacencyDistance[i][j] = 0;
        }
    }
}

graph::graph(const graph &A)
{
    this->size = A.size;
    for (int i = 0; i < MAX_VERTICE; i++)
    {
        this->vertice[i] = A.vertice[i];
        for (int j = 0; j < MAX_VERTICE; j++)
        {
            this->edgeName[i][j] = A.edgeName[i][j];
            this->adjacencyDistance[i][j] = A.adjacencyDistance[i][j];
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
            cout << "Vertice com o nome " << name << " ja inserido" << endl;
            return;
        }
    }

    vertice[size] = name;
    vertice[size] += "\0";
    size++;
    return;
}

void graph::setEdge(int v1, int v2, int distance, string name)
{
    if (v1 == v2)
    {
        cout << "E impossivel inserir uma aresta de um vertice com ele mesmo" << endl;
        return;
    }

    if (v1 >= size || v1 < 0 || v2 < 0 || v2 >= size)
    {
        cout << "Vertices fora de alcance" << endl;
        return;
    }

    edgeName[v1][v2] = name;
    edgeName[v2][v1] = name;
    adjacencyDistance[v2][v1] = distance;
    adjacencyDistance[v1][v2] = distance;
}

void graph::removeVertice(int v)
{
    if (v >= size || v < 0)
    {
        cout << "index fora do tamanho" << endl;
        return;
    }

    for (int i = v; i < size - 1; i++)
    {
        vertice[i] = vertice[i + 1];
        edgeName[i][v] = edgeName[i + 1][v];
        edgeName[v][i] = edgeName[v][i + 1];
        adjacencyDistance[v][i] = adjacencyDistance[v][i + 1];
        adjacencyDistance[i][v] = adjacencyDistance[i + 1][adjacencyDistance[v][i]];
    }

    vertice[size - 1] = "\0";
    for (int i = 0; i < size; i++)
    {
        edgeName[i][size - 1] = "\0";
        edgeName[size - 1][i] = "\0";
        adjacencyDistance[size - 1][i] = 0;
        adjacencyDistance[i][size - 1] = 0;
    }
}

void graph::removeEdge(int v1, int v2)
{
    if (v1 >= size || v1 < 0 || v2 >= size || v2 < 0)
    {
        cout << "index fora do tamanho" << endl;
        return;
    }

    edgeName[v1][v2] = "\0";
    edgeName[v2][v1] = "\0";

    adjacencyDistance[v1][v2] = 0;
    adjacencyDistance[v2][v1] = 0;
}

void graph::printVertice()
{
    cout << "|";
    for (int i = 0; i < size; i++)
    {
        if (vertice[i].compare("\0"))
            cout << " " << vertice[i] << " |";
    }
    cout << endl;
}

void graph::printEdges()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (adjacencyDistance[i][j])
                cout << " " << vertice[i] << " -> " << edgeName[i][j] << " " << adjacencyDistance[i][j] << " -> " << vertice[j] << "" << endl;
        }
    }
}

void graph::depthFirstSearch(int start = 0)
{
    if (!this->goodman())
    {
        cout << "O grafo e desconexo" << endl;
        return;
    }

    int path[MAX_VERTICE], cont = 1, newPath, pointer = 0;
    path[0] = start;
    while (cont != size)
    {
        for (int i = 0; i < size; i++)
        {
            newPath = 1;
            if (adjacencyDistance[i][path[pointer]])
            {
                for (int j = 0; j < cont; j++)
                    if (i == path[j])
                        newPath = 0;
                if (newPath)
                {
                    path[cont] = i;
                    cont++;
                    pointer = cont;
                    i = 0;
                    break;
                }
            }
        }
        pointer--;
    }

    cout << "DFS:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << " -> " << vertice[path[i]];
    }

    cout << endl;
}

void graph::breadthFirstSearch(int start = 0)
{
    if (!this->goodman())
    {
        cout << "O grafo e desconexo" << endl;
        return;
    }

    int path[MAX_VERTICE], cont = 1, newPath, pointer = 0;
    path[0] = start;
    while (cont != size)
    {
        for (int i = 0; i < size; i++)
        {
            newPath = 1;
            if (adjacencyDistance[i][path[pointer]])
            {
                for (int j = 0; j < cont; j++)
                    if (i == path[j])
                        newPath = 0;
                if (newPath)
                {
                    path[cont] = i;
                    cont++;
                    i = 0;
                }
            }
        }
        pointer++;
    }

    cout << "BFS:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << " -> " << vertice[path[i]];
    }

    cout << endl;
}

void graph::dijkstra(int start, int final)
{
}

void graph::fleury(int vertice)
{
    if (vertice >= size || vertice < 0)
    {
        cout << "index fora do tamanho" << endl;
        return;
    }

    if (!this->isEulerian())
    {
        cout << "nao e possivel fazer esta operacao" << endl;
        return;
    }

    int end = 0, i = 0;
    cout << "Eulerian cycle" << endl;
    cout << this->vertice[vertice];

    while (!end)
    {
        for (i = 0; i < size; i++)
        {
            if (adjacencyDistance[vertice][i])
            {
                adjacencyDistance[vertice][i] = 0;
                adjacencyDistance[i][vertice] = 0;
                vertice = i;
                cout << " -> " << this->vertice[vertice];
                break;
            }
        }
        if (i == size)
            end = 1;
    }
    cout << endl;
}

int graph::goodman()
{
    int cont = 0;
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (adjacencyDistance[i][j])
                cont++;

    if (cont >= size)
        return 1;
    return 0;
}

int graph::isEulerian()
{
    for (int i = 0; i < size; i++)
    {
        int cont = 0;
        for (int j = 0; j < size; j++)
        {
            if (adjacencyDistance[i][j])
                cont++;
        }
        if (cont % 2)
            return 0;
    }

    return 1;
}

int main()
{
    graph grafo;

    grafo.insertVertice("A");
    grafo.insertVertice("B");
    grafo.insertVertice("C");
    grafo.insertVertice("D");
    grafo.insertVertice("E");
    grafo.insertVertice("F");
    grafo.insertVertice("G");
    grafo.insertVertice("H");
    grafo.insertVertice("I");
    grafo.insertVertice("J");

    grafo.setEdge(0, 1, 6, "A-B");
    grafo.setEdge(0, 3, 5, "A-C");
    grafo.setEdge(1, 2, 4, "B-C");
    grafo.setEdge(1, 4, 6, "B-E");
    grafo.setEdge(2, 3, 7, "C-D");
    grafo.setEdge(2, 8, 9, "C-I");
    grafo.setEdge(3, 6, 4, "D-G");
    grafo.setEdge(3, 9, 4, "D-J");
    grafo.setEdge(4, 5, 7, "E-F");
    grafo.setEdge(4, 8, 8, "E-I");
    grafo.setEdge(5, 8, 2, "F-I");
    grafo.setEdge(6, 7, 3, "G-H");
    grafo.setEdge(6, 8, 9, "G-I");
    grafo.setEdge(7, 8, 1, "H-I");

    grafo.printEdges();

    graph copyOfGrafo(grafo);
    copyOfGrafo.fleury(2);

    cout << grafo.goodman() << endl;

    grafo.breadthFirstSearch();

    grafo.depthFirstSearch();

    grafo.removeVertice(9);

    grafo.printEdges();

    grafo.breadthFirstSearch();

    grafo.depthFirstSearch();
}