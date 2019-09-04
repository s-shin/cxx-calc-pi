#include <cstdlib>
#include <iostream>

#include "gmpxx.h"

#include "./pi.h"

int main(int argc, char **argv) {
  int num_digits = 10;
  if (argc > 1) {
    num_digits = std::atoi(argv[1]);
  }

  using State = pi::State<mpz_class>;
  State s;
  for (int i = 0; i <= num_digits; ++i) {
    auto r = pi::GetNext(s);
    std::cout << r.value;
    s = r.state;
    if (i == 0) {
      std::cout << ".";
    }
  }
  std::cout << std::endl;
  return 0;
}
