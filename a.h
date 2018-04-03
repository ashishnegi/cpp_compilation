#ifndef A_H
#define A_H

void foo(int);

#endif

// g++ optimize away : this file is opened again if have don't have this below.
#ifdef AB

void ab();

#endif