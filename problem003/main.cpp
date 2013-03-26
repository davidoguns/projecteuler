//David Oguns
//Project Euler Problem 03

#include <iostream>
#include <cmath>
#include "primes.h"

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
  unsigned long long const TO_FACTOR = 600851475143ll;
  unsigned long long number  = TO_FACTOR; //this will change, and be left with the largest prime factor
  unsigned long long terminate = TO_FACTOR/2; //starting point of when to terminate

  for(unsigned long long factor = 2; factor < terminate ; ++factor)
  { //could probably skip a few steps eh?
    if((number%factor)==0)
    {
      while((number%factor)==0)
      {
        number /= factor;
        terminate = static_cast<unsigned long long>(std::ceil(number/static_cast<float>(factor)));
      }
    }
  }

  cout << "Solution: " << number << endl;
}
