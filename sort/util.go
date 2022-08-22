package sort

import (
	"golang.org/x/exp/constraints"
)

func Min[T constraints.Ordered](lhs, rhs T) T {
	if lhs < rhs {
		return lhs
	}
	return rhs
}

func Swap[T any](lhs, rhs *T) {
	temp := *lhs
	*lhs = *rhs
	*rhs = temp
}

type Pair[T any] struct {
	A, B T
}