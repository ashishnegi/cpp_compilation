ashish @ 7567 ~/work/gitrepos/cpp_compilation (master)
└─ $ ▶ g++ -c *.cpp
ashish @ 7567 ~/work/gitrepos/cpp_compilation (master)
└─ $ ▶ ls -l
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
ashish @ 7567 ~/work/gitrepos/cpp_compilation (master)
└─ $ ▶

1. why is a.o bigger than b.o and main.o ?
   Because each cpp is compiled separately and because of #include header in a.cpp

ashish @ 7567 ~/work/gitrepos/cpp_compilation (master)
└─ $ ▶ nm a.o
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
ashish @ 7567 ~/work/gitrepos/cpp_compilation (master)
└─ $ ▶ nm b.o
0000000000000000 T _Z3barv
                 U _Z3fooi
ashish @ 7567 ~/work/gitrepos/cpp_compilation (master)
└─ $ ▶ nm main.o
0000000000000000 T main
                 U _Z3barv
                 U _Z3fooi
ashish @ 7567 ~/work/gitrepos/cpp_compilation (master)
└─ $ ▶

