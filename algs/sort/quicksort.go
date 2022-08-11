package sort

import (
	"golang.org/x/exp/constraints"
)

func QuickSort[T constraints.Ordered](slice []T) {
	if len(slice) < 2 {
		// min := Min(slice[0], slice[1])
		// if min != slice[0] {
		// 	Swap(&slice[0], &slice[1])
		// }
		return
	}

	//pivot := slice[0]
	
}

func hoarePartition[T constraints.Ordered](slice []T, pivot T, l, r int) {
	bounds := Pair[int]{l, r}

	for {
		for slice[bounds.A] < pivot {
			bounds.A++
		}
		for slice[bounds.B] > pivot {
			bounds.B--
		}
		if bounds.A >= bounds.B {
			// if (bounds.A - bounds.B == 2) || (bounds.A == bounds.B) {
			// 	bounds.A--
			// }
			swapEqual(slice, pivot, l, r)
			return
		}
		Swap(&slice[bounds.A], &slice[bounds.B])
	}
}

func swapEqual[T constraints.Ordered](slice []T, pivot T, l, r int, bounds Pair[int]) {
	for i := l; i < bound; i++ {
		if (slice[i] == pivot) {
			if i != l {
				
			}
		}
	}
}