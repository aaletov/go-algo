package sllist

type SingleLinkedList[T any] interface {
	Insert(value T)
}

type Node[T any] struct {
	Value T
	Next *Node[T]
}

type List[T any] struct {
	Begin *Node[T]
	End *Node[T]
}

func NewNode[T any](value T) *Node[T] {
	return &Node[T] {
		Value: value,
	}
}

func (n *Node[T]) HasNext() bool {
	return n.Next != nil
}

func NewList[T any](value T) List[T] {
	node := &Node[T] {
		Value: value,
	}
	return List[T] {
		Begin: node,
		End: node,
	}
}

func (l *List[T]) Empty() bool {
	return l.Begin == nil
}

// We can't recover from out of memory error, so there is
// no point to consider this scenario
func (l *List[T]) Insert(value T) {
	node := NewNode(value)
	if l.Empty() {
		l.Begin = node
	} else {
		l.End.Next = node
	}
	l.End = node
}