package main

import "fmt"

func readInitials() (n int, a0 float32, an1 float32, err error) {
	_, err = fmt.Scanf("%d\n%g\n%g\n", &n, &a0, &an1)

	if err != nil {
		return n, a0, an1, err
	}


	return n, a0, an1, nil
}

func forwardStep() {

}

func backwardStep() {

}

func main() {
	var (
		n int
		a0 float32
		an1 float32
		err error
	)

	n, a0, an1, err = readInitials()

	if err != nil {
		fmt.Errorf("%v", err.Error())
	}

	var a []float32 = make([]float32, n + 2)

	a[0] = a0
	a[n + 1] = an1

	var c []float32 = make([]float32, n + 1)

	for i := 1; i < n + 1; i++ {
		_, err = fmt.Scanf("%g\n", &c[i])
		if err != nil {
			fmt.Errorf("%v", err.Error())
		}
	}

	var alpha []float32 = make([]float32, n + 2)
	var beta []float32 = make([]float32, n + 2)

	var A float32 = -1
	var B float32 = 2
	var C float32 = -1

	alpha[2] = -C / B;
	beta[2] = ((2 * c[1] + a[0]) / B)

	alpha[n + 1] = 0
	beta[n + 1] = (((2 * c[n] + a[n + 1]) - A * beta[n]) / (A * alpha[n] + B))

	fmt.Printf("---\n")
	fmt.Printf("%g\n", alpha[2])
	fmt.Printf("%g\n", alpha[3])
	fmt.Printf("%g\n", beta[2])
	fmt.Printf("%g\n", beta[3])

	for i := n; i > 0; i-- {
		a[i] = alpha[i + 1] * a[i + 1] + beta[i + 1]
	}

	fmt.Printf("%d\n", n)

	for i := 0; i < n + 2; i++ {
		fmt.Printf("%g\n", a[i])
	}

	for i := 1; i < n + 1; i++ {
		fmt.Printf("%g\n", c[i])
	}
}