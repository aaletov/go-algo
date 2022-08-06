package sllist

type Node[T any] struct {
	Value T
	Next *Node[T]
}

func NewNode[T any](value T) *Node[T] {
	return &Node[T] {
		Value: value,
	}
}

type NodeIterator[T any] struct {
	Ptr *Node[T]
}

func (n *Node[T]) Iterator() NodeIterator[T] {
	return NodeIterator[T]{ n }
}

func (n NodeIterator[T]) Get() T {
	return n.Ptr.Value
}

func (n NodeIterator[T]) Next() NodeIterator[T] {
	return NodeIterator[T]{ n.Ptr.Next }
}

func (n NodeIterator[T]) End() bool {
	return n.Ptr == nil
}
