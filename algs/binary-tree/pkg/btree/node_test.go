package btree

import (
	"testing"
)

func getRawTree() *Node[int32] {
	node := NewNode[int32](9)
	node.Add(11)
	node.Add(7)
	node.Add(8)
	node.Add(13)
	node.Add(6)

	return node
}

func getPrinter(t *testing.T) func(int32) {
	return func(v int32) {
		t.Log(v)
	}
}

func TestNodePreOrderTraversal(t *testing.T) {
	printer := getPrinter(t)
	node := getRawTree()
	node.PreOrderTraversal(printer)
}

func TestNodeInOrderTraversal(t *testing.T) {
	printer := getPrinter(t)
	node := getRawTree()
	node.InOrderTraversal(printer)
}

func TestNodePostOrderTraversal(t *testing.T) {
	printer := getPrinter(t)
	node := getRawTree()
	node. PostOrderTraversal(printer)
}