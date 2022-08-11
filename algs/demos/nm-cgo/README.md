# Go linkage agains libc

By default, go uses flag CGO_ENABLED=1, which results in dynamic linkage against libc when using 
`net` or `os/user`. It is impossible to run such code on a system, that doesn't have libc (alpine).

Demo app built with CGO_ENABLE=1 produces executable with undefined symbols, which reference libc
functions.

```
go build -o main.out ./main.go
nm -C main.out | grep " U "
                U abort
                U __errno_location
                U fprintf
                U fputc
                U free
                U freeaddrinfo
                U fwrite
                U gai_strerror
                U getaddrinfo
                U malloc
                U mmap
                U munmap
                U nanosleep
                U pthread_attr_destroy
                U pthread_attr_getstacksize
                U pthread_attr_init
                U pthread_cond_broadcast
                U pthread_cond_wait
                U pthread_create
                U pthread_detach
                U pthread_mutex_lock
                U pthread_mutex_unlock
                U pthread_sigmask
                U setenv
                U sigaction
                U sigaddset
                U sigemptyset
                U sigfillset
                U sigismember
                U stderr
                U strerror
                U unsetenv
                U vfprintf
ldd main.out
        linux-vdso.so.1 (0x00007ffd6fb7a000)
        libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007f3d91a5b000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f3d91869000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f3d91a89000)
```

On the other hand, CGO_ENABLED=0 produces executable with no undefined symbols, replacing them with
Go implementation.

```
CGO_ENABLED=0 go build -o main.out ./main.go
nm -C main.out | grep " U " | true
nm -C main.out | grep "malloc"
000000000040b7c0 T runtime.mallocgc
000000000040aae0 T runtime.mallocinit
ldd main.out | true
        not a dynamic executable
```