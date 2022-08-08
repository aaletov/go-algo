package main

import (
	"fmt"
)

type A struct {}
type B struct {}

type Printer struct {
	A
	B
}

func (A) Print() {
	fmt.Println("I am A type Print")
}

func (B) Print() {
	fmt.Println("I am B type Print")
}

// Will not be compiled: 
// double-embedding/main.go:29:10: ambiguous selector printer.Print
func main() {
	var a A = A{}
	var b B = B{}
	var printer Printer = Printer{a, b}
	printer.Print()
}