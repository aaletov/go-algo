package dllist

type DoubleLinkedList[T comparable] struct {
	Begin *Node[T]
	End *Node[T]
}

func NewList[T comparable](value T) DoubleLinkedList[T] {
	node := NewNode(value)
	return DoubleLinkedList[T] {node, node}
}

func (l DoubleLinkedList[T]) Empty() bool {
	return l.Begin == nil
}

func (l *DoubleLinkedList[T]) Append(value T) {
	node := NewNode(value)
	if l.Empty() {
		l.Begin = node
	} else {
		l.End.Next = node
	}
	node.Prev = l.End
	l.End = node
}

func (l DoubleLinkedList[T]) Find(value T) *Node[T] {
	for node := l.Begin; node != nil; node = node.Next {
		if node.Value == value {
			return node
		}
	}
	return nil
}