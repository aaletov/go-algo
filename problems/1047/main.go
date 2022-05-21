package main

import "fmt"

func readInitials() (n int, a0 float64, an1 float64, err error) {
	_, err = fmt.Scanf("%d\n%g\n%g\n", &n, &a0, &an1)

	if err != nil {
		return n, a0, an1, err
	}


	return n, a0, an1, nil
}

func main() {
	var (
		n int
		a0 float64
		an1 float64
		err error
	)

	n, a0, an1, err = readInitials()

	if err != nil {
		fmt.Errorf("%v", err.Error())
	}

	if n == 1 {
		var c1 float64
		fmt.Scanf("%g\n", &c1)
		fmt.Printf("%g\n", (a0 + an1) / 2 - c1)
		return
	}

	var a []float64 = make([]float64, n + 2)

	a[0] = a0
	a[n + 1] = an1

	var c []float64 = make([]float64, n + 1)

	for i := 1; i < n + 1; i++ {
		_, err = fmt.Scanf("%g\n", &c[i])
		if err != nil {
			fmt.Errorf("%v", err.Error())
		}
	}

	var alpha []float64 = make([]float64, n + 2)
	var beta []float64 = make([]float64, n + 2)

	var A float64 = -1
	var B float64 = 2
	var C float64 = -1

	alpha[2] = -C / B;
	beta[2] = ((-2 * c[1] + a[0]) / B)

	alpha[n + 1] = 0
	beta[n + 1] = (((-2 * c[n] + a[n + 1]) - A * beta[n]) / (A * alpha[n] + B))

	for i := 2; i < n + 1; i++ {
    alpha[i + 1] = -C / (A * alpha[i] + B)
    beta[i + 1] = (-2 * c[i] - A * beta[i]) / (A * alpha[i] + B)
  }

	for i := n; i > 0; i-- {
		a[i] = alpha[i + 1] * a[i + 1] + beta[i + 1]
	}

	fmt.Printf("%.2f\n", a[1])
}
