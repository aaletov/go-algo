package btree

import (
	"golang.org/x/exp/constraints"
)

type PreOrderIterator[T constraints.Ordered] struct {
	Ptr *Node[T]
}

func (n *Node[T]) PreOrderIterator() PreOrderIterator[T] {
	return PreOrderIterator[T]{n}
}

func (n PreOrderIterator[T]) Get() T {
	return n.Ptr.Value
} 

// func (n PreOrderIterator[T]) Next() PreOrderIterator[T] {
// 	node := n.Ptr

// 	if node == nil {
// 		panic("Idk what to do here")
// 	}

// 	// need stack
// 	if node.Left != nil {
// 		return PreOrderIterator[T]{node.Left}
// 	}

// 	if node.Right != nil {
// 		return PreOrderIterator[T]{node.Right}
// 	}

// 	return PreOrderIterator[T]{n.Ptr.Next}
// }