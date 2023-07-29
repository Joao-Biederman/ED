//   /*****************************************************************
//  * Graph.go: Exemplo de implementação de grafos em Go utilizando *   -> traduzir para C++
//  * matriz de adjacência                                          *
//  *****************************************************************/
// package main

// import(
//    "fmt"
// )

// const INFINITY = -1
// /*******************************************************************
//  * Definição da estrtura de dados Graph como matriz de adjacências *
//  * E = [eij] | eij = { 1 se e somente se existe (vi, vj) em E       *
//  *                   { 0 caso contrário
//  *******************************************************************/
// type Graph struct {
//    E[][]int // Matriz de adjacência do grafo para MAX_V vértices
//    nV int // número de vértices utilizados
//    nE int //Número de arestas utilizadas
// }

// /**********************************************
//  * Função para criar um grafo com nv vértices *
//  **********************************************/
// func (G *Graph) CreateGraph(nv int) {

//    G.E = make([][]int, nv)       // Aloca amatriz de adjacências
//                         // atualiza o número de vértices
//    for i := 0; i < nv; i++ {
//       G.E[i] = make([]int, nv)   // Aloca espaço para arestas
//    }
//    G.nV = nv
//    // Inicializa o grafo com infinitos
//    for i := 0; i < nv; i++ {
//       for j := 0; j < nv; j++ {
//          G.E[i][j] = 0
//       }
// //      G.E[i][i] = 0 // Custo zero para (v, v)
//    }
// }

// /************************************************
//  * Função para imprimir a matriz de adjacências *
//  ************************************************/
// func (G *Graph) Print() {
//    for i := 0; i < G.nV; i++ {
//       fmt.Println(G.E[i])
//    }
// }

// /**********************************
//  * Função para inserir uma aresta *
//  **********************************/
// func (G *Graph) InsertEdge(v, w, p int) {
//    if (v < 0 || v > G.nV) || (w < 0 || w > G.nV) {
//       fmt.Println("Erro: número de vértice incorreto!")
//    } else {
//       G.E[v][w] = p
//       G.E[w][v] = p
//       G.nE++
//       fmt.Println("Aresta inserida")
//    }
// }

// /*********************************************
//  * Função para calcular o grau de um vértice *
//  *********************************************/
//  func (G *Graph) Degree(v int) (k int) {
//    for i := 0; i < G.nV; i++ {
//       if G.E[v][i] > 0 {
//          k += G.E[v][i]
//       }
//    }
//    return k
// }

// /***********************************
//  * Verifica se o grafo é Euleriano *
//  ***********************************/
//  func (G *Graph) IsEulerian() (k bool) {
//    k = true;
//    for i := 0; i < G.nV; i++ {
//       if G.Degree(i)%2 == 1 {
//          k = false
//          break;
//       }
//    }
//    return k
// }

// /********************
//  * Função principal *
//  ********************/
// func main(){
//    var G Graph

//    fmt.Println("Criando um grafo com 1 vértice...")
//    G.CreateGraph(4)  // cria um grafo com 4  vértices
//    G.Print()         // imprime a matriz de adjacências
//    fmt.Println("Inserindo arestas (0, 1)")
//    G.InsertEdge(0, 1, 1)
//    fmt.Println("Inserindo aresta (0, 2)")
//    G.InsertEdge(0, 2, 1)
// //   fmt.Println("Inserindo aresta (0, 3)")
// //   G.InsertEdge(0, 3, 1)
//    fmt.Println("Inserindo aresta (1, 3)")
//    G.InsertEdge(1, 3, 1)
//    fmt.Println("Inserindo aresta (2, 3)")
//    G.InsertEdge(2, 3, 1)
// //   fmt.Println("Inserindo aresta (2, 1)")
// //   G.InsertEdge(2, 1, 1)
//    fmt.Println("Calculando os graus dos vértices")
//    for i := 0; i < G.nV; i++ {
//       fmt.Println("Grau do vértice", i, "=", G.Degree(i))
//    }
//    fmt.Println("É euleriano?")
//    fmt.Println(G.IsEulerian())
//    G.Print()
// }
