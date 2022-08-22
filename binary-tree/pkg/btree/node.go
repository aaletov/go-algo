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

func (root *Node[T]) Find(value T) *Node[T] {
	if root == nil {
		panic("Root cannot be nil")
	}

	if value < root.Value {
		if root.Left != nil {
			return root.Left.Find(value)
		}
	} else if value > root.Value {
		if root.Right != nil {
			return root.Right.Find(value)
		}
	} else if value == root.Value {
		return root
	}

	return nil
}
