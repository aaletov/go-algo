package main

import (
	"fmt"
	"os"
)

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

func solveOneRowProblem(n int, a0 float64, an1 float64) (err error) {
	var c1 float64
	_, err = fmt.Scanf("%g\n", &c1)

	if err != nil {
		return
	}

	_, err = fmt.Printf("%g\n", (a0 + an1) / 2 - c1)

	return
}

func readInitials() (n int, a0 float64, an1 float64, err error) {
	_, err = fmt.Scanf("%d\n%g\n%g\n", &n, &a0, &an1)

	return
}

func readConstants(n int, a0 float64, an1 float64, rows []row) (err error) {
	var c1 float64
	_, err = fmt.Scanf("%g\n", &c1)

	if err != nil {
		return
	}

	for i := 2; i < n; i++ {
		_, err = fmt.Scanf("%g\n", &rows[i].F)

		if err != nil {
			return
		}

		rows[i].F *= -2
	}

	var cn float64
	_, err = fmt.Scanf("%g\n", &cn)

	if err != nil {
		return
	}

	rows[1].F = -2 * c1 + a0
	rows[n].F = -2 * cn + an1

	return 
}

func forwardStep(current *row, next *row, A float64, B float64, C float64) {
	next.Alpha = -C / (A * current.Alpha + B)
	next.Beta = (current.F - A * current.Beta) / (A * current.Alpha + B)

	return
}

func forwardSweep(n int, rows []row) {
	forwardStep(&rows[1], &rows[2], 0, B, C)
	for i := 2; i < n; i++ {
		forwardStep(&rows[i], &rows[i + 1], A, B, C)
	}
	forwardStep(&rows[n], &rows[n + 1], A, B, 0)

	return
}

func backwardStep(current *row, next *row) {
	current.A = next.Alpha * next.A + next.Beta

	return
}

func backwardSweep(n int, rows []row) {
	for i := n; i > 0; i-- {
		backwardStep(&rows[i], &rows[i + 1])
	}

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
		os.Exit(1)
	}

	if n == 1 {
		err = solveOneRowProblem(n, a0, an1)

		if err != nil {
			fmt.Errorf("%v", err.Error())
			os.Exit(1)
		}

		os.Exit(0)
	}

	var rows []row = make([]row, n + 2)

	err = readConstants(n, a0, an1, rows)

	if err != nil {
		fmt.Errorf("%v", err.Error())
		os.Exit(1)
	}

	forwardSweep(n, rows)
	backwardSweep(n, rows)

	fmt.Printf("%.2f\n", rows[1].A)
}
