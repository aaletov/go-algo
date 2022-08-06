package main

import (
	"fmt"
	"github.com/aaletov/go-algo/single-linked-list/sllist"
)

func main() {
	var list *sllist.List[int32] = new(sllist.List[int32])
	list.Insert(1)
	list.Insert(2)
	list.Insert(3)
	list.Insert(4)
	list.Insert(5)

	for node := list.Begin; node != nil; node = node.Next {
		fmt.Println(node.Value)
	} 
}