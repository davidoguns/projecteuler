//David Oguns
//Project Euler Factorization Utility

#include <iostream>
#include <cmath>
#include <string>
#include <numeric>
#include <tuple>
#include <set>
#include <list>

using namespace std;  //gettin lazy...too much std stuff

//brute force implementation, doesn't even try to use only primes or a sieve list
// -- one of these days, i'll actually use this function
set<tuple<int,int>> factorize(unsigned long long number)
{
  unsigned long long terminate = number;
  set<tuple<int, int>> factors;
  unsigned long long factor = 2;
  for(; factor < terminate; ++factor)
  {
    if(!(number%factor))  //miss this form of == 0
    {
      unsigned int count = 0;
      while(!(number%factor))
      {
        ++count;
        number /= factor;
      }
      factors.insert(tuple<int, int>(factor, count));
    }
  }
  
  if(number != 1)
  {
    factors.insert(tuple<int, int>(number, 1)); //what we're left with is to the first
  }

  return std::move(factors);
}

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    cerr << "Must specify a positive integer to factorize!!!" << endl;
    return 1;
  }

  set<tuple<int, int>> factors = factorize(std::atoi(argv[1]));

  for(tuple<int, int> f:factors)
  {
    cout << std::get<0>(f) << " ^ " << std::get<1>(f) << endl;
  }

  return 0;
}

