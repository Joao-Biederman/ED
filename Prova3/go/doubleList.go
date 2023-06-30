package main

import (
	"fmt"
	"os"
)

type Node struct {
	data       int
	next, prev *Node
}

type doubleList struct {
	first, last *Node
	size        int
}

func (list *doubleList) insertFirst(x int) {
	aux := new(Node)
	aux.data = x
	if list.size == 0 {
		list.last = aux
	} else {
		list.first.prev = aux
	}
	aux.next = list.first
	list.first = aux

	list.size++
}

func (list *doubleList) insertLast(x int) {
	aux := new(Node)
	aux.data = x
	if list.size == 0 {
		list.first = aux
	} else {
		list.last.next = aux
	}
	aux.prev = list.last
	list.last = aux

	list.size++
}

func (list *doubleList) popFirst() int {
	if list.size == 0 {
		fmt.Println("Tentativa de pop em lista vazia. Saindo do programa!")
		os.Exit(1)
	}

	aux := list.first
	if list.size == 1 {
		list.last = nil
	} else {
		aux.next.prev = nil
	}
	list.first = aux.next

	list.size--
	return aux.data
}

func (list *doubleList) popLast() int {
	if list.size == 0 {
		fmt.Println("Tentativa de pop em lista vazia. Saindo do programa!")
		os.Exit(1)
	}

	aux := list.last

	if list.size == 1 {
		list.first = nil
	} else {
		list.last = aux.prev
		list.last.next = nil
	}

	list.size--
	return aux.data
}

func (list *doubleList) printList() {
	aux := list.first
	fmt.Print("[ ")
	for i := 0; i < list.size; i++ {
		fmt.Printf("%d ", aux.data)
		aux = aux.next
	}
	fmt.Print("]\n\n")
}

func (list *doubleList) printReverse() {
	aux := list.last
	fmt.Print("[ ")
	for i := 0; i < list.size; i++ {
		fmt.Printf("%d ", aux.data)
		aux = aux.prev
	}
	fmt.Print("]\n\n")

}

func main() {
	list := new(doubleList)

	list.insertFirst(1)
	list.insertFirst(8)
	list.insertFirst(6)
	list.insertLast(3)
	list.insertLast(2)
	list.insertFirst(3)
	list.insertLast(5)

	list.printList()

	list.popFirst()
	list.printList()

	list.popLast()
	list.printList()

	list.printReverse()
}
