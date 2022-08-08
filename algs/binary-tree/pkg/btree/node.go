package btree

type Node[T any] struct {
	Value T
	Left *Node[T]
	Right *Node[T]
}

func NewNode[T any](value T) *Node[T] {
	return &Node{
		Value: value,
	}
}

type NodeIterator[T any] struct {
	Ptr *Node[T]
}

func (n *Node[T]) Iterator() NodeIterator[T] {
	return NodeIterator[T]{n}
}