//David Oguns
//Project Euler Problem 04

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
  unsigned long long terminate = number / 2;
  set<tuple<int, int>> factors;
  for(unsigned long long factor = 2; factor < terminate; ++factor)
  {
    if(!(number%factor))  //miss this form of == 0
    {
      unsigned int count = 0;
      while(!(number%factor))
      {
        ++count;
        number /= factor;
        terminate = number;
      }
      factors.insert(tuple<int, int>(factor, count));
    }
  }

  //don't forget to add terminate as it is the last factor
  unsigned int tcount = 0;
  while(!(number%terminate))
  {
    ++tcount;
    number /= terminate;
  }
  factors.insert(tuple<int, int>(terminate, tcount));

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

