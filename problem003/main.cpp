//David Oguns
//Project Euler Problem 03

#include <iostream>
#include "primes.h"

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
  unsigned long long TO_FACTOR = 600851475143;

  Primes::init_set();
  
  Primes::populateUpToSizeLimit(20000);
  Primes::populateUpToNumberLimit(200);
  Primes::print_primes();
}
