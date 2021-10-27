
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
