//David Oguns
//Project Euler Factorization Utility

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <numeric>
#include <tuple>
#include <set>
#include <list>

using namespace std;  //gettin lazy...too much std stuff

int main(int argc, char **argv)
{
  unsigned int targetSum = 0;
  istringstream(argv[1]) >> targetSum;
  unsigned int a, b, c;
  //cutting target in two for efficiency. a < b < c, if a is already t
  set<tuple<unsigned int, unsigned int, unsigned int>> triplets;
  for(int n = targetSum/2; n > 0; --n) //pick c
  {
    c = n;
    for(b = n -1; b > 0; --b) //pick b
    {
      a = targetSum - (c + b);
      //now verify if we have a pythagorean triplet
      if((a < b) && (a*a) + (b*b) == (c * c))
      {
        triplets.insert({a, b, c});
      }
    }
  }

  for(auto& triplet:triplets)
  {
    cout << "A = " << get<0>(triplet) << ", B = " << get<1>(triplet) << ", C = " << get<2>(triplet) << endl;
    cout << "Product: " << get<0>(triplet) * get<1>(triplet) * get<2>(triplet) << endl;
  }

  return 0;
}
