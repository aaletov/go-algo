package main

import "fmt"

type Node struct {
	Value any
	Next *Node
}

func (n *Node) Add(value any) {
	if n == nil {
		panic("nil node")
	}

	n.Next = &Node{Value: value}
}

func main() {
	node := Node{5, nil}
	var value int = node.Value.(int)
	fmt.Println(value)

	var array []any = []any{1, 2, 3}
	value = array[0].(int)
	fmt.Println(value)

	node.Add(6)
	fmt.Println(node.Next.Value)
}