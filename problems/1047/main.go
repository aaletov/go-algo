package main

import "fmt"

const (
	A float64 = -1
	B float64 = 2
	C float64 = -1
)

type row struct {
	A float64
	F float64
	Alpha float64
	Beta float64
}

func readInitials() (n int, a0 float64, an1 float64, err error) {
	_, err = fmt.Scanf("%d\n%g\n%g\n", &n, &a0, &an1)

	return
}

func forwardStep(current *row, next *row) {
	next.Alpha = -C / (A * current.Alpha + B)
	next.Beta = (current.F - A * current.Beta) / (A * current.Alpha + B)

	return 
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

	var rows []row = make([]row, n + 2)
	rows[0].A = a0
	rows[n + 1].A = an1

	var c1 float64
	_, err = fmt.Scanf("%g\n", &c1)

	for i := 2; i < n; i++ {
		_, err = fmt.Scanf("%g\n", &rows[i].F)
		rows[i].F *= -2
		if err != nil {
			fmt.Errorf("%v", err.Error())
		}
	}

	var cn float64
	fmt.Scanf("%g\n", &cn)

	rows[1].F = -2 * c1 + rows[0].A
	rows[n].F = -2 * cn + rows[n + 1].A

	for i := 1; i < n; i++ {
		rows[i + 1].Alpha = -C / (A * rows[i].Alpha + B)
		rows[i + 1].Beta = (rows[i].F - A * rows[i].Beta) / (A * rows[i].Alpha + B)
  }

	rows[n + 1].Alpha = 0
	rows[n + 1].Beta = ((rows[n].F - A * rows[n].Beta) / (A * rows[n].Alpha + B))  

	for i := n; i > 0; i-- {
		rows[i].A = rows[i + 1].Alpha * rows[i + 1].A + rows[i + 1].Beta
	}

	fmt.Printf("%.2f\n", rows[1].A)
}
