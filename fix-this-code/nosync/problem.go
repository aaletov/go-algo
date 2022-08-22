package main

// 1) Fix the code
// 2) Solve same problem without Mutex / WaitGroup
func pseudomain() {
	var counter int
	for i := 0; i < 1000; i++ {
		go func() {
				counter++
		}()
	}
}