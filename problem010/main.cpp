//David Oguns
//Project Euler Problem 07

//not using seive to generate primes since we are searching for
//a specific one with no idea of what numeric range it's in.  Such
//a hint would allow us to leverage, but doesn't feel like the way
//to approach the problem if it was more abstract

#include <iostream>
#include <cmath>
#include <string>
#include <numeric>
#include <tuple>
#include <set>
#include <list>
#include <iomanip>

using namespace std;  //gettin lazy...too much std stuff

bool isPrime(unsigned long long number, const list<unsigned long long> & primes)
{
  for(const unsigned long long &p:primes)
  {
    if(!(number%p)) return false;
    //early termination - don't bother checking primes over half of the number we're checking
    if(p > (number/2)) return true;   //is prime
  }
  return true;
}

int main(int argc, char **argv)
{ 
  //TODO: review C++ 11 uniform initialization
  list<unsigned long long> primes{2ll, 3ll, 5ll};
  const unsigned long long pFind = 10001;   //looking for the 10,0001st prime
  unsigned long long lookingAt = 6;         //
  while(primes.size() < pFind)
  {
    if(isPrime(lookingAt, primes))
    {
      primes.push_back(lookingAt);
    }

    ++lookingAt;
  }

  cout << "Solution: " << *primes.rbegin() << endl;
  return 0;
}


