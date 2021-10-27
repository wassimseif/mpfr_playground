/* This is the example given and commented on the MPFR web site:
 *   https://www.mpfr.org/sample.html
 */

/*
Copyright 1999-2004, 2006-2020 Free Software Foundation, Inc.
Contributed by the AriC and Caramba projects, INRIA.

This file is part of the GNU MPFR Library.

The GNU MPFR Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

The GNU MPFR Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MPFR Library; see the file COPYING.LESSER.  If not, see
https://www.gnu.org/licenses/ or write to the Free Software Foundation, Inc.,
51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#include <mpfr.h>

#include <cstdio>

#include "iostream"
#include "vector"

void evaluate_precision(int const &value) {
  unsigned int i;
  mpfr_t s, t, u;
  std::cout << std::endl << "Precision " << value << std::endl;

  mpfr_init2(t, value);
  mpfr_set_d(t, 2.15, MPFR_RNDD); // mpfr set double
  printf("t is ");
  mpfr_out_str(stdout, 10, 0, t, MPFR_RNDD);
  printf("\n");

  mpfr_init2(s, value);
  mpfr_set_d(s, 2.0, MPFR_RNDD);
  printf("s is ");
  mpfr_out_str(stdout, 10, 0, s, MPFR_RNDD);
  printf("\n");

  mpfr_init2(u, value);
  mpfr_add(u, s, t, MPFR_RNDD);

  printf("Sum is ");
  mpfr_out_str(stdout, 10, 0, u, MPFR_RNDD);

  mpfr_clear(s);
  mpfr_clear(t);
  mpfr_clear(u);
  mpfr_free_cache();
}
int main() {

  std::vector<int> precisions;
  for (int i = 1; i <= 40; ++i)
    precisions.push_back(i * 5);

  std::for_each(std::begin(precisions), std::end(precisions),
                evaluate_precision);

  return 0;
}
