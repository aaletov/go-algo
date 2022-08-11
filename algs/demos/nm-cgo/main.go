package main

import (
	"net"
	"fmt"
)

func main() {
	lis, err := net.Listen("tcp", fmt.Sprintf(":%d", 22))
	if err != nil {
		fmt.Println("Failed to listen: %v", err)
		return
	}
	fmt.Printf("Server listening at %v", lis.Addr())
}