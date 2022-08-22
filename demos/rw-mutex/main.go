package main

import (
	"sync"
	"time"
	"fmt"
)

const (
	WRITERS = 1
	READERS = 10
	TIMEOUT = 1 * time.Second
	INCS = 10
)

func main() {
	var mutex sync.RWMutex
	var counter int
	var wg sync.WaitGroup
	wg.Add(WRITERS + READERS)

	for i := 0; i < WRITERS; i++ {
		go func() {
			for j := 0; j < INCS; j++ {
				mutex.Lock()
				counter++
				<- time.After(TIMEOUT)
				mutex.Unlock()
			}
			wg.Done()
		}()
	}

	for i := 0; i < READERS; i++ {
		go func(i int) {
			mutex.RLock()
			fmt.Printf("Writer %d, counter is %d\n", i, counter)
			<- time.After(3 * time.Second)
			mutex.RUnlock()
			wg.Done()
		}(i)
		<- time.After(time.Second)
	}

	wg.Wait()
}