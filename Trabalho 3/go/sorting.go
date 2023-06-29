package main

import (
	"fmt"
	"os"
	"time"
)

type Node struct {
	data        int
	left, right *Node
}

type List struct {
	start, end *Node
	n          int
}

func (lista *List) insert(x int) {
	newNode := new(Node)

	if newNode == nil {
		panic("Não há memória suficiente para alocar um novo nó!")
	}

	newNode.data = x
	newNode.right, newNode.left = nil, nil

	if lista.n == 0 {
		lista.start = newNode
	} else {
		newNode.left = lista.end
		lista.end.right = newNode
	}

	lista.end = newNode
	lista.n++
}

func (lista *List) printList() {
	aux := lista.start
	fmt.Print("{")
	for aux != nil {
		fmt.Printf("%v", aux.data)
		if aux.right != nil {
			fmt.Print(", ")
		}
		aux = aux.right
	}
	fmt.Println("}")
}

func (lista *List) insertionSortE() {
	troca := lista.start
	for troca != nil {
		aux := troca.right
		lista.insertionChangeE(troca)
		troca = aux
	}
}

func (lista *List) insertionSort() {
	troca := lista.start
	for troca != nil {
		aux := troca.right
		lista.insertionChange(troca)
		troca = aux
	}
}

func (lista *List) insertionChange(change *Node) {
	if change.left == nil {
		return
	}
	aux := change.left
	for aux != nil {
		if change.data > aux.data {
			if change.right == nil {
				lista.end = change.left
			} else {
				change.right.left = change.left
			}

			change.left.right = change.right
			aux.right.left = change
			change.right = aux.right
			aux.right = change
			change.left = aux
			return
		}
		aux = aux.left
	}
	if change.right == nil {
		lista.end = change.left
	} else {
		change.right.left = change.left
	}
	change.left.right = change.right
	change.right = lista.start
	change.left = nil
	lista.start.left = change
	lista.start = change
}

func (lista *List) insertionChangeE(change *Node) {
	for change != nil {
		if change.left == nil {
			return
		}
		if change.data < change.left.data {
			change.data, change.left.data = change.left.data, change.data
			change = change.left
		} else {
			return
		}
	}
}

func change() {

}

func main() {
	var (
		lista, lista2 List
		n, x          int
	)

	in1, inError1 := os.Open("../numeros.txt")

	if inError1 != nil {
		fmt.Println("Erro:", inError1)
		in1.Close()
		return
	}

	in2, inError2 := os.Open("../numeros.txt")

	if inError2 != nil {
		fmt.Println("Erro:", inError2)
		in2.Close()
		return
	}

	fmt.Println("Insira a quantidade de elementos da lista: ")
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Fscanf(in1, "%d", &x)
		lista.insert(x)
	}
	in1.Close()

	for i := 0; i < n; i++ {
		fmt.Fscanf(in2, "%d", &x)
		lista2.insert(x)
	}
	in2.Close()

	start1 := time.Now()

	// lista.printList()

	lista.insertionSortE()

	// fmt.Printf("\n\n\n\n")

	// lista.printList()

	duration1 := time.Since(start1)

	start2 := time.Now()
	lista2.insertionSort()
	duration2 := time.Since(start2)

	fmt.Printf("Duração de tempo 1 (troca um a um):")
	fmt.Println(duration1)

	fmt.Printf("Duração de tempo 2 (insiro na posição correta):")
	fmt.Println(duration2)

}
