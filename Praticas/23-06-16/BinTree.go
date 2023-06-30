package main

import "fmt"

const CLEAR string = "\033[H\033[2J"

type DataType uint8

type BinTreeNode struct {
	data        DataType     // dado armazenado no nó
	left, right *BinTreeNode // ponteiros para os filhos esquerdo e direito
}

type Node struct {
	data *BinTreeNode
	next *Node
}

type ListaSE struct {
	len   int8  // Número de elementos na lista
	left  *Node // ponteiro para o inicio da lista
	right *Node // ponteiro para o final da lista
}

func (l *ListaSE) IsEmpty() bool {
	return l.len == 0
}

func (l *ListaSE) Find(x *BinTreeNode) *Node {
	aux := l.left
	for (aux != nil) && aux.data == x {
		aux = aux.next
	}
	return aux
}

func (l *ListaSE) Length() int8 {
	return l.len
}

func (l *ListaSE) Print() {
	p := l.left
	fmt.Print("{")
	for p != nil {
		fmt.Printf("%v", p.data)
		if p.next != nil {
			fmt.Print(", ")
		}
		p = p.next
	}
	fmt.Println("}")
}

func (list *ListaSE) InsertLeft(x *BinTreeNode) {
	newNode := new(Node)
	if newNode == nil {
		panic("Não há memória suficiente para alocar um novo nó!")
	}
	newNode.data = x

	// Se a lista estiver vazia, o novo nó será o primeiro e o último nó.
	if list.left == nil {
		newNode.next = nil
		list.left = newNode
		list.right = newNode
	} else {
		// Se a lista não estiver vazia, adicione o novo nó ao início da lista.
		newNode.next = list.left
		list.left = newNode
	}
	// incrementar o contador de elementos na lista
	list.len++
}

func (list *ListaSE) InsertRight(x *BinTreeNode) {
	newNode := new(Node) // alocar memória para um novo nó

	if newNode == nil { // verifica se ocorreu erro de memória insuficiente
		panic("Não há memória suficiente para alocar um novo nó!")
	}
	// inicializar o valor e o próximo ponteiro do novo nó
	newNode.data = x
	newNode.next = nil

	// se a lista está vazia, o novo nó será a cabeça e a cauda da lista
	if list.left == nil {
		list.left = newNode
		list.right = newNode
	} else {
		// se a lista não está vazia, adicionar o novo nó no final da lista
		list.right.next = newNode
		list.right = newNode
	}
	// incrementar o contador de elementos na lista
	list.len++
}

func (l *ListaSE) RemoveLeft() *BinTreeNode {
	if l.left == nil {
		return nil
	}
	r := l.left.data
	l.left = l.left.next
	if l.left == nil {
		l.right = nil
	}
	l.len--
	return r
}

func (l *ListaSE) RemoveRight() *BinTreeNode {
	if l.right == nil {
		return nil
	}
	r := l.right.data
	if l.left == l.right {
		l.left = nil
		l.right = nil
	} else {
		aux := l.left
		for aux.next != l.right {
			aux = aux.next
		}
		aux.next = nil
		l.right = aux
	}
	l.len--
	return r
}

func (btn *BinTreeNode) Init(l *BinTreeNode, d DataType, r *BinTreeNode) {
	btn.data = d
	btn.left = l
	btn.right = r
}

func (btn *BinTreeNode) GetData() (data DataType) {
	return btn.data
}

func (btn *BinTreeNode) SetData(d DataType) {
	btn.data = d
}

func (btn *BinTreeNode) GetLeft() (l *BinTreeNode) {
	return btn.left
}

func (btn *BinTreeNode) GetRight() (r *BinTreeNode) {
	return btn.right
}

func (btn *BinTreeNode) SetLeft(l *BinTreeNode) {
	btn.left = l
}

func (btn *BinTreeNode) SetRight(r *BinTreeNode) {
	btn.right = r
}

func (btn *BinTreeNode) Print() {
	fmt.Print(btn.data)
}

type BinTree struct {
	root        *BinTreeNode
	numElements int8
}

func (bt *BinTree) Init() {
	bt.root = nil
	bt.numElements = 0
}

func (bt *BinTree) Print(r *BinTreeNode, level int8) {
	if r == nil {
		return
	} else {
		bt.Print(r.GetRight(), level+1)
		for i := int8(0); i < level; i++ {
			fmt.Print("------|")
		}
		r.Print() // imprime o nó
		fmt.Print("\n")
		bt.Print(r.GetLeft(), level+1)
	}
}

func (bt *BinTree) InsertNode(x DataType, root *BinTreeNode) *BinTreeNode {
	if root == nil { // nó nulo, tenta alocar um novo nó
		root = new(BinTreeNode)
		if root == nil {
			panic("Erro: Memória insuficiente!\n")
		} else {
			root.Init(nil, x, nil) // novo nó inserido
			bt.numElements++       // incrementa número de elementos
			return root            // retorna o novo nó
		}
	} else { // nó não é nulo, verifica se tem que descer à esquerda ou à direita
		if x < root.GetData() {
			root.SetLeft(bt.InsertNode(x, root.GetLeft()))
		} else {
			root.SetRight(bt.InsertNode(x, root.GetRight()))
		}
		return root
	}
}

func (bt *BinTree) Insert(x DataType) {
	bt.root = bt.InsertNode(x, bt.root)
}

func (bt *BinTree) remNode(x DataType, r *BinTreeNode) *BinTreeNode {
	var (
		p1, p2 *BinTreeNode
	)

	if r == nil { // raiz é nula. Elemento não está na árvore
		return nil // Nada a fazer.
	}
	if r.GetData() == x { // apaga a raiz
		if r.GetLeft() == r.GetRight() { // não tem filhos (ambos são nulos)
			r = nil          // remove o nó r
			bt.numElements-- // decrementa o número de elementos
			return nil       // retorna nó nulo
		} else { // algum filho é nulo
			if r.GetLeft() == nil { // esquerda nula
				p1 = r.GetRight()
				r = nil
				bt.numElements--
				return p1
			} else {
				if r.GetRight() == nil { // Direita nula
					p1 = r.GetLeft()
					r = nil
					bt.numElements--
					return p1
				} else { // os dois filhos estão presentes
					p1 = r.GetRight()
					p2 = r.GetRight()
					for p1.GetLeft() != nil { // Acha o nó mais a esquerda do filho direito
						p1 = p1.GetLeft()
					}
					p1.SetLeft(r.GetLeft()) // Coloca a sub-árvore do filho esquerdo como
					r = nil                 // filho do elemento mais a esquerda do filho direito
					bt.numElements--
					return p2
				}
			}
		}
	}
	if x < r.GetData() {
		r.SetLeft(bt.remNode(x, r.GetLeft()))
	} else {
		r.SetRight(bt.remNode(x, r.GetRight()))
	}
	return r
}

func (bt *BinTree) Delete(x DataType) {
	bt.root = bt.remNode(x, bt.root)
}

func (bt *BinTree) Find(x DataType) *BinTreeNode {
	r := bt.root
	achou := false

	for (!achou) && (r != nil) {
		if r == nil {
			return nil
		} else {
			if r.GetData() == x { //achou
				achou = true
			} else {
				if r.GetData() > x { // busca na esquerda
					r = r.GetLeft()
				} else {
					r = r.GetRight()
				}
			}
		}
	}
	return r
}

func (bt *BinTree) Visit(r *BinTreeNode) {
	// Implemente aqui o processo de visita ao nó.
	// Neste exemplo, a visita apenas imprime o conteúdo armazenado no nó.
	fmt.Print(r.GetData(), " ")
}

func (bt *BinTree) BreadthFirst() {
	var (
		r    *BinTreeNode = bt.root
		fila ListaSE
	)

	if r != nil {
		fila.InsertRight(r)
		fmt.Print("{ ")
		for !fila.IsEmpty() {
			r = fila.RemoveLeft()
			bt.Visit(r)
			if r.GetLeft() != nil {
				fila.InsertRight(r.GetLeft())
			}
			if r.GetRight() != nil {
				fila.InsertRight(r.GetRight())
			}
		}
		fmt.Print("}")
	}
	return
}

func (bt *BinTree) ItPreOrder() {
	var (
		r     *BinTreeNode = bt.root
		pilha ListaSE
	)

	if r != nil {
		pilha.InsertLeft(r)
		fmt.Print("{ ")
		for !pilha.IsEmpty() {
			r = pilha.RemoveLeft()
			bt.Visit(r)
			if r.GetRight() != nil {
				pilha.InsertLeft(r.GetRight())
			}
			if r.GetLeft() != nil {
				pilha.InsertLeft(r.GetLeft())
			}
		}
		fmt.Print("}")
	}
	return
}

func (bt *BinTree) ItInOrder() {
	var (
		r     *BinTreeNode = bt.root
		pilha ListaSE
	)
	fmt.Print("{ ")
	for r != nil {
		for r != nil {
			if r.GetRight() != nil {
				pilha.InsertLeft(r.GetRight())
			}
			pilha.InsertLeft(r)
			r = r.GetLeft()
		}
		r = pilha.RemoveLeft()
		for !pilha.IsEmpty() && (r.GetRight() == nil) {
			bt.Visit(r)
			r = pilha.RemoveLeft()
		}
		bt.Visit(r)
		if !pilha.IsEmpty() {
			r = pilha.RemoveLeft()
		} else {
			r = nil
		}
	}
	fmt.Print("}")
	return
}

func (bt *BinTree) ItPostOrder() {
	var (
		pilha ListaSE
		r     *BinTreeNode = bt.root
		rAux  *BinTreeNode = bt.root
	)

	fmt.Print("{ ")
	for r != nil {
		for r.GetLeft() != nil {
			pilha.InsertLeft(r)
			r = r.GetLeft()
		}
		for (r != nil) && ((r.GetRight() == nil) || (r.GetRight() == rAux)) {
			bt.Visit(r)
			rAux = r
			if pilha.IsEmpty() {
				fmt.Print("}")
				return
			}
			r = pilha.RemoveLeft()
		}
		pilha.InsertLeft(r)
		r = r.GetRight()
	}
}

func Clear() {
	fmt.Print(CLEAR) // escape codes para limpar a tela (Unix)
}

func main() {
	// Declaração de variáveis
	var (
		op      DataType
		x       DataType
		binTree BinTree
	)

	for {
		Clear() // Limpa a tela
		fmt.Println("ÁRVORES BINÁRIAS DE BUSCA")
		fmt.Println("\t Menu Principal")
		fmt.Println("[ 0] Sair")
		fmt.Println("[ 1] Criar árvore")
		fmt.Println("[ 2] Imprimir árvore")
		fmt.Println("[ 3] Inserir elemento")
		fmt.Println("[ 4] Remover elemento")
		fmt.Println("[ 5] Procurar elemento")
		fmt.Println("[ 6] Percurso em largura iterativo")
		fmt.Println("[ 7] Percurso em profundidade pré-ordem iterativo")
		fmt.Println("[ 8] Percurso em profundidade em-ordem iterativo")
		fmt.Println("[ 9] Percurso em profundidade Pós-ordem iterativo")
		fmt.Println("[10] Percurso em profundidade Pré-ordem recursivo")
		fmt.Println("[11] Percurso em profundidade em-ordem recursivo")
		fmt.Println("[12] Percurso em profundidade Pós-ordem recursivo")
		fmt.Println("\nQual a sua opção? >> ")
		fmt.Scan(&op)
		switch op {
		case 0:
			{
				Clear()
				fmt.Println("Programa Encerrado!\nTecle [ENTER]")
				fmt.Scanln(&op)
				return
			}
		case 1:
			{
				Clear()
				fmt.Println("Criando árvore...")
				binTree.Init()
				fmt.Println("Árvore criada!\n Tecle [ENTER]")
				fmt.Scanln()
			}
		case 2:
			{
				Clear()
				fmt.Println("Árvore armazenada:")
				binTree.Print(binTree.root, 0)
				fmt.Println("\nNúmero de elementos na árvore: ", binTree.numElements)
				fmt.Println("\nTecle [ENTER]")
				fmt.Scanln()
			}
		case 3:
			{
				Clear()
				fmt.Println("Inserindo elemento")
				fmt.Print("Número a inserir >> ")
				fmt.Scanln(&x)
				binTree.Insert(x)
				fmt.Println("Elemento inserido. Tecle [ENTER]")
				fmt.Scanln()
			}
		case 4:
			{
				Clear()
				fmt.Println("Removendo elemento")
				fmt.Print("Número a remover >> ")
				fmt.Scanln(&x)
				binTree.Delete(x)
				fmt.Println("Elemento Removido. Tecle [ENTER]")
				fmt.Scanln()
			}
		case 5:
			{
				Clear()
				fmt.Println("Procurar elemento")
				fmt.Print("Número a procurar >> ")
				fmt.Scanln(&x)
				a := binTree.Find(x)
				if a == nil {
					fmt.Println("Elemento não encontrado. Tecle [ENTER]")
					fmt.Scanln()
				} else {
					fmt.Println(x, "está na árvore:", a)
					fmt.Scanln()
				}
			}
		case 6:
			{
				Clear()
				fmt.Println("Percurso em largura iterativo")
				binTree.BreadthFirst()
				fmt.Println("\nTecle [ENTER]")
				fmt.Scanln()
			}
		case 7:
			{
				Clear()
				fmt.Println("Percurso em profundidade Pré-Ordem iterativo")
				binTree.ItPreOrder()
				fmt.Println("\nTecle [ENTER]")
				fmt.Scanln()
			}
		case 8:
			{
				Clear()
				fmt.Println("Percurso em profundidade Em-Ordem iterativo")
				binTree.ItInOrder()
				fmt.Println("\nTecle [ENTER]")
				fmt.Scanln()
			}
		case 9:
			{
				Clear()
				fmt.Println("Percurso em profundidade Pós-Ordem iterativo")
				binTree.ItPostOrder()
				fmt.Println("\nTecle [ENTER]")
				fmt.Scanln()
			}
		default:
			{
				fmt.Println("Opção inválida!\nTecle [ENTER]")
				fmt.Scanln(&op)
			}
		}
	}
}
