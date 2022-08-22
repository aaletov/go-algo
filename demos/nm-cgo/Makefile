nm-cgo-enabled:
	go build -o main.out ./main.go
	nm -C main.out | grep " U "
	ldd main.out

nm-cgo-disabled:
	CGO_ENABLED=0 go build -o main.out ./main.go
	nm -C main.out | grep " U " | true
	nm -C main.out | grep "malloc"
	ldd main.out | true
