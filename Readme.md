```
$ g++ -c *.cpp
$ ls -l
total 32
-rw-rw-r-- 1 ashish ashish   73 Apr  3 19:16 a.cpp
-rw-rw-r-- 1 ashish ashish   48 Apr  3 19:16 a.h
-rw-rw-r-- 1 ashish ashish 2488 Apr  3 19:18 a.o
-rw-rw-r-- 1 ashish ashish   42 Apr  3 19:16 b.cpp
-rw-rw-r-- 1 ashish ashish   45 Apr  3 19:16 b.h
-rw-rw-r-- 1 ashish ashish 1368 Apr  3 19:18 b.o
-rw-rw-r-- 1 ashish ashish    0 Apr  3 19:18 commands
-rw-rw-r-- 1 ashish ashish   82 Apr  3 19:16 main.cpp
-rw-rw-r-- 1 ashish ashish 1432 Apr  3 19:18 main.o
```

1. why is a.o bigger than b.o and main.o ?
   Because each cpp is compiled separately and because of #include header in a.cpp

```
$ nm a.o
                 U __cxa_atexit
                 U __dso_handle
0000000000000068 t _GLOBAL__sub_I__Z3fooi
0000000000000000 T _Z3fooi
000000000000002a t _Z41__static_initialization_and_destruction_0ii
                 U _ZNSolsEi
                 U _ZNSolsEPFRSoS_E
                 U _ZNSt8ios_base4InitC1Ev
                 U _ZNSt8ios_base4InitD1Ev
                 U _ZSt4cout
                 U _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
0000000000000000 b _ZStL8__ioinit

$ nm b.o
0000000000000000 T _Z3barv
                 U _Z3fooi

$ nm main.o
0000000000000000 T main
                 U _Z3barv
                 U _Z3fooi

```

2. Transitive dependencies : graph is not clear and for preprocessing, files will be opened again.

```
$ strace -f g++ -E main.cpp  2>&1 | rg "open" | rg "a\.h" | wc -l
2
```

For golang :

```
ashish @ 7567 ~/go/src/github.com/ashishnegi/cpp_compilation (master)
└─ $ ▶ strace -f go build -x  2>&1 | rg "open" | rg "/a.go"
[pid 28014] openat(AT_FDCWD, "/home/ashish/go/src/github.com/ashishnegi/cpp_compilation/a/a.go", O_RDONLY|O_CLOEXEC) = 3
```