//David Oguns
//Project Euler Problem 05

#include <iostream>
#include <set>
#include <tuple>
#include <map>
#include <cmath>

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

//definitely could do this better...as in a single pass creates the map and doesn't hold onto the sets
int main(int argc, char **argv)
{
  map<int, int> completeFactors;
  for(int n = 1; n <= 20; ++n)
  { 
    for(const tuple<int, int> &factor:factorize(n))
    {
      auto inMapItr = completeFactors.find(get<0>(factor));
      if(inMapItr == completeFactors.end())
      { //means we don't have this base yet at all, insert into map
        completeFactors[get<0>(factor)] = get<1>(factor);
      }
      else if(inMapItr->second < get<1>(factor)) //in map, but lower power/order of magnitude
      { //means we found something like 3^3 while 3^1 was in the map...replace
        completeFactors[get<0>(factor)] = get<1>(factor);
      }
    }
  }

  int solution = 1;
  for(const pair<int, int> &f:completeFactors)
  {
    cout << std::get<0>(f) << " ^ " << std::get<1>(f) << endl;
    solution *= pow<int>(get<0>(f), get<1>(f));
  }
  cout << "Solution: " << solution << endl;
  
  return 0;
}

