//David Oguns
//Primes implementation helper library

#include <iostream>
#include <set>
#include <list>
#include <tuple>
#include "primes.h"

using std::cout;
using std::set;
using std::list;
using std::tuple;
using std::make_tuple;

namespace Primes {
  //vector of all previous primes -internal linkage here, the C++ way
  set<unsigned int> prime_set;
  
  void print_primes(char sep)
  {
    for(set<unsigned int>::iterator itr = prime_set.begin(); itr != prime_set.end(); ++itr)
    {
      cout << (*itr) << sep;
    }
  }

  //initializes prime vector set to a certain size
  void init_set(unsigned int size)
  {
    //get started with 2, and 3 as prime factors
    prime_set.insert(2);
    prime_set.insert(3);
    populateUpToSizeLimit(size);
  }

  //checks if a number is prime in a scenario where we know it
  //should have been calculated for already
  bool isPrime(int number) {
    return prime_set.find(number) != prime_set.end();
  }

  //check if this number is the next prime to be added in the set
  bool checkForNextPrime(int number) {
    for(set<unsigned int>::iterator itr = prime_set.begin(); itr != prime_set.end(); ++itr)
    {
      if((number%(*itr)) == 0)
      { //we found a number (prime) that divides into the number, not prime
        return false;
      }
    }
    return true;
  }

  //optimized factorization that'll only use prime numbers
  //returns a list of the factorization of a number.
  //Each item in the list is <base,exponent> so 2 * 2 * 2 * 3 * 5 * 5 would be
  //a list returned of: <2,3>, <3,1>, <5,2>
  list<tuple<unsigned int,unsigned int>> factorize(int number)
  {
    list<tuple<unsigned int,unsigned int>> factors;

    for(set<unsigned int>::iterator itr = prime_set.begin(); itr != prime_set.end(); ++itr)
    {
      if((number%(*itr)) == 0)
      {
        unsigned int exp = 1;
        //this loop will divide out a prime factor however many times it needs to be, for example
        //from 96, it will divide 2 out 5 times (32), and divide 3 out once.  2^5 * 3^1 = 96
        while((number%(*itr)) == 0)  //while still divisible (1 redundant check here)
        {     //divide out the factor
          number /= (*itr);
          exp++;
        }
        factors.push_back(make_tuple(*itr, exp));
      }
    }

    return factors;
  }

  //ensures the prime number set has a number at least as large as what we expect
  void populateUpToNumberLimit(unsigned int limit)
  {
    for(unsigned int number = *prime_set.end(); number < limit; ++number) 
    {
      if(checkForNextPrime(number))
      {
        prime_set.insert(number);
      }
    }
  }

  //ensures the prime set size is populated up to a certain size
  void populateUpToSizeLimit(unsigned int limit)
  {
    unsigned int number = *prime_set.end() + 1;
    while(prime_set.size() < limit)
    {
      if(checkForNextPrime(number))
      {
        prime_set.insert(number);
      }
      ++number;
    }
  }
}

