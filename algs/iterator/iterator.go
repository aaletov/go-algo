package iterator

type ForwardIterator[T any] interface {
	Get() T
	Next() ForwardIterator[T]
	End() bool
}

type BidirectionalIterator[T any] interface {
	ForwardIterator[T]
	Prev() BidirectionalIterator[T]
}