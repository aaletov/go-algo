package sllist

type SingleLinkedList[T comparable] interface {
	Insert(value T)
}

type List[T comparable] struct {
	Begin *Node[T]
	End *Node[T]
}

func NewList[T comparable](value T) List[T] {
	node := &Node[T] {
		Value: value,
	}
	return List[T] {
		Begin: node,
		End: node,
	}
}

func (l List[T]) Empty() bool {
	return l.Begin == nil
}

// If the function changes state of object,
// it must receive it by pointer
//
// We can't recover from out of memory error, so there is
// no point to consider this scenario
func (l *List[T]) Append(value T) {
	node := NewNode(value)
	if l.Empty() {
		l.Begin = node
	} else {
		l.End.Next = node
	}
	l.End = node
}

// Function doesn't change object's state so
// it should not operate on original object
func (l List[T]) Find(value T) *Node[T] {
	for node := l.Begin; node != nil; node = node.Next {
		if node.Value == value {
			return node
		}
	}
	return nil
}