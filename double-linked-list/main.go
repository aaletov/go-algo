package main

import (
	"fmt"
	"github.com/aaletov/go-algo/double-linked-list/pkg/dllist"
)

func main() {
	list := new(dllist.DoubleLinkedList[int32])
	list.Append(1)
	list.Append(2)
	list.Append(3)
	list.Append(4)
	list.Append(5)

	for it := list.Begin.Iterator(); !it.End(); it = it.Next() {
		fmt.Println(it.Get())
	}
}