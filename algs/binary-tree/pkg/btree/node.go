package btree

import (
	"errors"
	"golang.org/x/exp/constraints"
)

type Node[T constraints.Ordered] struct {
	Value T
	Left *Node[T]
	Right *Node[T]
}

func NewNode[T constraints.Ordered](value T) *Node[T] {
	return &Node[T]{
		Value: value,
	}
}

func (root *Node[T]) Add(value T) error {
	if root == nil {
		panic("Root cannot be nil")
	}

	if value < root.Value {
		if root.Left == nil {
			root.Left = NewNode(value)
		} else {
			root.Left.Add(value)
		}
	} else if value > root.Value {
		if root.Right == nil {
			root.Right = NewNode(value)
		} else {
			root.Right.Add(value)
		}
	} else {
		return errors.New("Dublicate key")
	}
	return nil
}

func (root *Node[t]) Find(value T) *Node[T] {
	if root == nil {
		panic("Root cannot be nil")
	}

	if value < root.Value {
		if root.Left != nil {
			return find(root.Left)
		} else {
			return nil
		}
	} else if value > root.Value {
		if root.Right != nil {
			return find(root.Right)
		} else {
			return nil
		}
	} else if value == root.Value {
		return root
	}
}

func (root *Node[T]) PreOrderTraversal(f func(T)) {
	if root == nil {
		panic("Root cannot be nil")
	}

	f(root.Value)

	if root.Left != nil {
		root.Left.PreOrderTraversal(f)
	} 

	if root.Right != nil {
		root.Right.PreOrderTraversal(f)
	}
}

func (root *Node[T]) InOrderTraversal(f func(T)) {
	if root == nil {
		panic("Root cannot be nil")
	}

	if root.Left != nil {
		root.Left.InOrderTraversal(f)
	}

	f(root.Value)

	if root.Right != nil {
		root.Right.InOrderTraversal(f)
	}
}

func (root *Node[T]) PostOrderTraversal(f func(T)) {
	if root == nil {
		panic("Root cannot be nil")
	}

	if root.Left != nil {
		root.Left.PostOrderTraversal(f)
	}

	if root.Right != nil {
		root.Right.PostOrderTraversal(f)
	}

	f(root.Value)
}