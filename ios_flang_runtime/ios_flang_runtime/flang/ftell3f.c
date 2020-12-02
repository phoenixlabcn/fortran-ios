/*
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 */

/* clang-format off */

/** \file
 * \brief Implements LIB3F ftell subroutine.  */

/* must include ent3f.h AFTER io3f.h */
#include "io3f.h"
#include "ent3f.h"

extern FILE *__getfile3f();

int ENT3F(FTELL, ftell)(lu) int *lu;
{
  FILE *f;

  /* DON'T issue any error messages */

  f = __getfile3f(*lu);
  if (f) {
    seekoff_t i;

    __io_set_errno(0);
    i = __io_ftell(f);
    if (i == -1 && __io_errno())
      return -__io_errno();
    return i;
  }

  return 0;
}
