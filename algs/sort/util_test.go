package sort

import (
	"testing"
)

type minTestCase struct {
	A, B int32
	FirstMin bool
}

func getMinTestCases() []minTestCase {
	testCases := make([]minTestCase, 0)
	testCases = append(testCases, minTestCase{1, 2, true})
	testCases = append(testCases, minTestCase{2, 1, false})
	testCases = append(testCases, minTestCase{2, 2, true})
	return testCases
}

func TestMin(t *testing.T) {
	testCases := getMinTestCases()

	for i := range testCases {
		tCase := testCases[i]
		min := Min(tCase.A, tCase.B)

		if (min == tCase.A) != tCase.FirstMin {
			t.Fatalf("Incorrect output %v for values %v, %v", min, tCase.A, tCase.B)
		}
	}
}

func TestSwap(t *testing.T) {
	slice := []int32{1, 2}
	Swap(&slice[0], &slice[1])

	if !((slice[0] == 2) && (slice[1] == 1)) {
		t.Fatalf("Incorrect output for values %v, %v", 1, 2)
	}
}