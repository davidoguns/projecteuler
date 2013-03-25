//David Oguns
//Helper library for generating prime numbers

#include <set>

namespace Primes {

  //initializes prime vector set to a certain size
  void init_set(unsigned int size = 10);
  
  void print_primes(char sep = '\n');

  //ensures the prime number set has a number at least as large as what we expect
  void populateUpToNumberLimit(unsigned int limit);

  //ensures the prime set size is populated up to a certain size
  void populateUpToSizeLimit(unsigned int limit);

}
