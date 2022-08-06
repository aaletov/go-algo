package iterator

type Iterator[T any] interface {
	Get() T
	Next() Iterator[T]
	End() bool
}