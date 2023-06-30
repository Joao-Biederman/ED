// João Vitor Biederman
// Questão 4

package main

import (
	"fmt"
	"os"
)

func main() {
	in, inError := os.Open("./par.in")

	if inError != nil {
		fmt.Println("Erro:", inError)
		in.Close()
		return
	}

	out, outError := os.Create("./par.out")

	if outError != nil {
		fmt.Println("Erro:", outError)
		in.Close()
		out.Close()
		return
	}
	var nome1, nome2 string
	count := 0
	for {
		n := 0
		p1, p2 := 0, 0
		fmt.Fscanf(in, "%d", &n)

		if n == 0 {
			in.Close()
			out.Close()
			return
		}

		count++
		fmt.Fprintf(out, "Teste %d\n", count)

		fmt.Fscanln(in, &nome1)
		fmt.Fscanln(in, &nome2)

		for i := 0; i < n; i++ {
			fmt.Fscanf(in, "%d %d", &p1, &p2)
			if (p1+p2)%2 == 0 {
				fmt.Fprintln(out, nome1)
			} else {
				fmt.Fprintln(out, nome2)
			}
		}
		fmt.Fprintf(out, "\n")
	}
}
