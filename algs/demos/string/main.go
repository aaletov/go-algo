package main

import "fmt"

const keys = "abcdef"

func main() {
	// %c	is the character represented by the corresponding Unicode code point
	for i, r := range keys {
		fmt.Printf("Rune is %c, pos is %d\n", r, i + 1)
	}
}