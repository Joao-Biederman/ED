package main

import (
	"fmt"
	"os"
)

type Node struct {
	data int
	next *Node
}

type simpleList struct {
	first, last *Node
	size        int
}

func (list *simpleList) insert(x int) {
	aux := new(Node)
	aux.data = x
	if list.first == nil {
		list.first = aux
	} else {
		list.last.next = aux
	}
	list.last = aux

	list.size++
}

func (list *simpleList) popFirst() int {
	if list.size == 0 {
		fmt.Println("Tentativa de pop em lista vazia. Saindo do programa!")
		os.Exit(1)
	}

	aux := list.first
	if list.size == 1 {
		list.last = nil
	}
	list.first = aux.next

	list.size--
	return aux.data
}

func (list *simpleList) popLast() int {
	if list.size == 0 {
		fmt.Println("Tentativa de pop em lista vazia. Saindo do programa!")
		os.Exit(1)
	}

	aux1 := list.last

	if list.size == 1 {
		list.first = nil
		list.last = nil
	} else {
		aux2 := list.first
		for aux2.next != aux1 {
			aux2 = aux2.next
		}
		list.last = aux2
	}

	list.size--
	return aux1.data
}

func (list *simpleList) printList() {
	aux := list.first
	fmt.Print("[ ")
	for i := 0; i < list.size; i++ {
		fmt.Printf("%d ", aux.data)
		aux = aux.next
	}
	fmt.Print("]\n\n")
}

func main() {
	list := new(simpleList)

	list.insert(1)
	list.insert(8)
	list.insert(6)
	list.insert(3)
	list.insert(2)
	list.insert(3)
	list.insert(5)

	list.printList()

	list.popFirst()
	list.printList()

	list.popLast()
	list.printList()
}
