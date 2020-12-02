/*
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 */

/* clang-format off */

/*	alarm3f.c - Implements LIB3F alarm subprogram.  */

#ifndef WINNT
#include <signal.h>
#include "ent3f.h"

//extern void (*signal(int, void (*)(int)))(int);
extern unsigned int alarm(unsigned int);

int ENT3F(ALARM, alarm)(int *time, void (*proc)())
{
  if (*time)
    signal(SIGALRM, proc);
  return alarm(*time);
}
#endif
