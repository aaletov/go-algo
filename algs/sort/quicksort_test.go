package sort

import (
	"testing"
)

func getSortSlice() (slice []int32, pivotIndex int32) {
	slice = []int32{7, 3, 8, 5, 9}
	pivotIndex = 2
} 

func TestHoarePartition(t *testing.T) {
	slice, pivotIndex := getSortSlice()
	hoarePartition(slice, pivot)

	for i := range slice {
		if (i < pivotIndex) && (slice[i] > slice[pivotIndex]) {
			t.Fatalf("Invalid order for element %v", slice[i])
		}
		if (i )
	}
}