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

bool isPalindrome(unsigned int n)
{
  //all palindromes appear to be divisible by 11...so check for it
  if(n%11) return false;
  string number = std::to_string(n);

  for(int i = 0; i < (number.size()/2); ++i)
  {
    if(number[i] != number[number.size()-(i+1)]) return false;
  }
  return true;
}

int main(int argc, char **argv)
{
  unsigned int max_factor = 999;
  unsigned int num = 0;
  for(unsigned int f1 = max_factor; f1 > 100; --f1)
  {
    for(unsigned int f2 = max_factor; f2 >= f1; --f2)
    {
      if(isPalindrome(f1*f2) && (f1*f2) > num)
      {
        num = f1 * f2;
      }
    }
  }
  cout << "Solution: " << num << endl;
  return 0;
}

