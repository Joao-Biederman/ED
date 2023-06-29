// João Vitor Biederman
// Questão 5

package main

import (
	"fmt"
	"os"
)

func makeMatriz(m, n, x, y int, in, out *os.File) {
	if m <= 0 || n <= 0 {
		return
	}

	matriz := make([][]int, m)
	for i := range matriz {
		matriz[i] = make([]int, n)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			fmt.Fscanf(in, "%d", &matriz[i][j])
		}
	}

	// matriz = ajustScreen(matriz, m, n, x, y)

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			fmt.Fprintf(out, "%d ", matriz[i][j])
		}
		fmt.Fprintf(out, "\n")
	}
}

func ajustScreen(matriz [][]int, m, n, x, y int) [][]int {

	return matriz
}

func main() {
	in, inError := os.Open("./tv.in")

	if inError != nil {
		fmt.Println("Erro:", inError)
		in.Close()
		return
	}

	out, outError := os.Create("./tv.out")

	if outError != nil {
		fmt.Println("Erro:", outError)
		in.Close()
		out.Close()
		return
	}

	var m, n, x, y, count int

	for {
		fmt.Fscanf(in, "%d %d", &m, &n)
		fmt.Fscanf(in, "%d %d", &x, &y)

		if x == 0 && y == 0 && m == 0 && n == 0 {
			in.Close()
			out.Close()
			return
		}

		if m > 0 && n > 0 {
			count++
			fmt.Fprintf(out, "Teste %d\n", count)
			makeMatriz(m, n, x, y, in, out)
			fmt.Fprintln(out, "")
		}
	}
}
