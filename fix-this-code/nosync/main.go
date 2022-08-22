package main

import (
	"fmt"
	"sync"
)

func nosync() {
	const GOROUTINES = 1000
	var counter int
	ch := make(chan bool, 1)
	wait := make(chan bool, 1000)
	for i := 0; i < GOROUTINES; i++ {
		go func() {
			ch <- true
			counter++
			<- ch
			wait <- true
		}()
	}
	for i := 0; i < GOROUTINES; i++ {
		<- wait
	}
	fmt.Println(counter)
}

func fix() {
	var counter int
	var wg sync.WaitGroup
	var mutex sync.Mutex
	wg.Add(1000)
	for i := 0; i < 1000; i++ {
		go func() {
			mutex.Lock()
			defer mutex.Unlock()
			counter++
			wg.Done()
		}()
	}
	wg.Wait()
	fmt.Println(counter)
}

func main() {
	fix()
	nosync()
}