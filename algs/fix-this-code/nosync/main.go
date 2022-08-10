package main

import (
	"fmt"
	"sync"
)

func main() {
	var counter int
	var wg sync.WaitGroup
	wg.Add(1000)
	channel := make(chan int)
	for i := 0; i < 1000; i++ {
		go func() {
			channel <- 5
			counter++
			<- channel
			wg.Done()
		}()
	}
	wg.Wait()
	fmt.Println(counter)
}