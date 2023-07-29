// /***********************************************************
//  * BTree.go: Implementação de uma árvore-B (B-Tree) em Go *
//  ***********************************************************/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

// package main

// import (
// 	"fmt"
// 	"strings"
// )

// const t = 2 // Grau (ou ordem) da árvore B
//             // No. mínimo de chaves/nó = t - 1
//             // No. máximo de chaves/nó = 2*t - 1

// type DataType uint16

// /******************************
//  * Declaração da classe BTree *
//  ******************************/
 
class schedule
{
private:
    char name[30];
    char adress[50];
    char number[15];
    int trash = 0;
public:
    string getName();
    string getAdress();
    string getNumber();

    int inTrash();

    void move2Trash();
    void removeFromTrash();

    void setName();
    void setAdress();
    void setNumber();

};

// /*******************
//  * Estrutura do nó *
//  *******************/ 
// type BTreeNode struct {
// 	leaf     bool           // identifica se um nó é folha (true) ou não (false)
// 	keys     []DataType     // vetor de chaves em cada nó
// 	children []*BTreeNode   // vetor de ponteiros em cada nó
// }

class node
{
private:
    bool leaf;
    schedule *keys[3];
    node *children[4];

public:
    node(/* args */);
    ~node() ;
};

node::node(/* args */)
{
}

node::~node()
{
}



class agenda
{
private:

public:
};
// /*********************************************************
//  * InitNode(leaf): Criação de um novo nó da árvore B *
//  * leaf indica se o novo nó será uma folha ou não        *
//  *********************************************************/  
// func InitNode(leaf bool) *BTreeNode {
// 	return &BTreeNode{
// 		leaf:     leaf,
// 		keys:     []DataType{},
// 		children: []*BTreeNode{},
// 	}
// }

// /**************************************
//  * Definição da estrutura da Árvore B *
//  **************************************/
// type BTree struct {
// 	root *BTreeNode
// }

// /*************************************
//  * Init(): Inicialização da árvore-B *
//  *************************************/
// func Init() *BTree {
// 	return &BTree{
// 		root: InitNode(true),
// 	}
// }

// /*********************************************************
//  * Impressão da árvore B em forma de árvore de diretório *
//  *********************************************************/
// func (node *BTreeNode) Print(indent string, last bool) {
// 	fmt.Print(indent)
// 	if last {
// 		fmt.Print("└─ ")
// 		indent += "    "
// 	} else {
// 		fmt.Print("├─ ")
// 		indent += "|   "
// 	}
// 	keys := make([]string, len(node.keys))
// 	fmt.Print("[")
// 	for i, key := range node.keys {
// 		keys[i] = fmt.Sprintf("%v", key)
// 	}
// 	fmt.Println(strings.Join(keys, "|"), "]")
// 	childCount := len(node.children)
// 	for i, child := range node.children {
// 		child.Print(indent, i == childCount-1)
// 	}
// }

// /*********************************************************
//  * splitChild(i): implementa a Divisão de um filho cheio *
//  * i é o ponto onde o nó será dividido                   *
//  *********************************************************/
// func (node *BTreeNode) splitChild(i int16) {
// 	child := node.children[i]
// 	newChild := InitNode(child.leaf)

// 	// Move as chaves e os filhos para o novo filho
// 	newChild.keys = append(newChild.keys, child.keys[t:]...)
// 	child.keys = child.keys[:t]
// 	if !child.leaf { // divide o nó em dois
// 		newChild.children = append(newChild.children, child.children[t:]...)
// 		child.children = child.children[:t]
// 	}

// 	// Insere o novo filho no nó
// 	node.children = append(node.children, nil)
// 	copy(node.children[i+2:], node.children[i+1:])
// 	node.children[i+1] = newChild

// 	// Move a chave correspondente para cima
// 	node.keys = append(node.keys, 0)
// 	copy(node.keys[i+1:], node.keys[i:])
// 	node.keys[i] = child.keys[t-1]
// 	child.keys = child.keys[:t-1]
// }

// /***********************************************************
//  * Insert(key): Inserção de uma chave em um nó da árvore B *
//  * key é a chave que será inserida                        *
//  ***********************************************************/
// func (node *BTreeNode) Insert(key DataType) {
// 	if !node.leaf {
// 		// Encontra o filho apropriado para inserir a chave
// 		i := len(node.keys) - 1
// 		for i >= 0 && key < node.keys[i] {
// 			i--
// 		}

// 		// Insere a chave no filho apropriado
// 		if len(node.children[i+1].keys) == 2*t-1 {
// 			node.splitChild(int16(i) + 1)
// 			if key > node.keys[i+1] {
// 				i++
// 			}
// 		}
// 		node.children[i+1].Insert(key)
// 	} else {
// 		// Insere a chave no nó folha
// 		i := len(node.keys) - 1
// 		node.keys = append(node.keys, 0)
// 		for i >= 0 && key < node.keys[i] {
// 			node.keys[i+1] = node.keys[i]
// 			i--
// 		}
// 		node.keys[i+1] = key
// 	}
// }

// /******************************************************
//  * Insert(key): Inserção de uma chave na árvore B     *
//  * Esta é a função que deve ser chamada para realizar *
//  * a inserção. key é a chave a ser inserida.          *
//  ******************************************************/
// func (tree *BTree) Insert(key DataType) {
// 	root := tree.root
// 	if len(root.keys) == 2*t-1 {
// 		newRoot := InitNode(false)
// 		newRoot.children = append(newRoot.children, root)
// 		newRoot.splitChild(0)
// 		tree.root = newRoot
// 	}
// 	tree.root.Insert(key)
// }


// // Busca de uma chave na árvore B
// func (node *BTreeNode) Search(key DataType) *DataType {
// 	i := 0
// 	for i < len(node.keys) && key > node.keys[i] {
// 		i++
// 	}

// 	if i < len(node.keys) && key == node.keys[i] {
// 		return &node.keys[i]
// 	} else if node.leaf {
// 		return nil
// 	} else {
// 		return node.children[i].Search(key)
// 	}
// }

// // Busca de uma chave na árvore B
// func (tree *BTree) Search(key DataType) *DataType {
// 	return tree.root.Search(key)
// }

// /**************************************
//  * Clear(): Função para limpar a tela *
//  **************************************/
// func Clear(){
//    fmt.Print("\033[H\033[2J") // escape codes para limpar a tela (Unix)
// }

// /****************************
//  * main(): Função principal *
//  ****************************/
// func main() {
//    // Declaração de variáveis
//    var (
//       op DataType
//       tree *BTree
//       x DataType
//    )
	
//    for {
//       Clear() // Limpa a tela
//       fmt.Println("ÁRVORES-B (B-Trees)")
//       fmt.Println("\t Menu Principal")
//       fmt.Println("[ 0] Sair")
//       fmt.Println("[ 1] Criar árvore")
//       fmt.Println("[ 2] Imprimir árvore")
//       fmt.Println("[ 3] Inserir elemento")
//       fmt.Println("[ 4] Remover elemento")
//       fmt.Println("[ 5] Procurar elemento")
      
//       fmt.Print("\nQual a sua opção? >> ")
//       fmt.Scan(&op)
//       switch op {
//       case 0: {
//          Clear()
//          fmt.Println("Programa Encerrado!\nTecle [ENTER]")
//          fmt.Scanln(&op)
//          return
//       }
// 	   case 1: {
//          Clear()
//          fmt.Println("Criando árvore...")
//          tree = Init()
//          fmt.Println("Árvore criada!\n Tecle [ENTER]")
//          fmt.Scanln()
//       }
//       case 2: {
//          Clear()
//          fmt.Println("Árvore armazenada:")
//          tree.root.Print("", true)
//          fmt.Println("\nTecle [ENTER]")
//          fmt.Scanln()
//       }
//       case 3: {
//          Clear()
//          fmt.Println("Inserindo elemento")
//          fmt.Print("Número a inserir >> ")
//          fmt.Scanln(&x)
//          tree.Insert(x)
//          fmt.Println("Elemento inserido. Tecle [ENTER]")
//          fmt.Scanln()
//       }
//    /*case 4: {
//          Clear()
//          fmt.Println("Removendo elemento\n")
//          fmt.Print("Número a remover >> ")
//          fmt.Scanln(&x)
//          tree.Remove(x)
//          fmt.Println("Elemento Removido. Tecle [ENTER]")
//          fmt.Scanln()
//       }
//       case 5: {
//          Clear()
//          fmt.Println("Procurar elemento\n")
//          fmt.Print("Número a procurar >> ")
//          fmt.Scanln(&x)
//          a := binTree.Find(x)
//          if a == nil {
//             fmt.Println("Elemento não encontrado. Tecle [ENTER]")
//             fmt.Scanln()
//          } else {
//             fmt.Println(x, "está na árvore:", a)
//             fmt.Scanln()
//          } 
//       }
// */	 default: {
// 	    fmt.Println("Opção Inválida!\nTecle [ENTER]")
// 	    fmt.Scanln(&op)
// 	 }
//     }
//    }
// }
