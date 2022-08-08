package main

import (
	"fmt"
	"github.com/aaletov/go-algo/single-linked-list/pkg/sllist"
)

func main() {
	var list *sllist.List[int32] = new(sllist.List[int32])
	list.Append(1)
	list.Append(2)
	list.Append(3)
	list.Append(4)
	list.Append(5)

	for node := list.Begin; node != nil; node = node.Next {
		fmt.Println(node.Value)
	} 

	node := list.Find(3)
	if node != nil {
		fmt.Printf("Found value: %d in node: %d\n", node.Value, node)
	}
}