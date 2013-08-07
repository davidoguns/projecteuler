//David Oguns
//Project Euler Problem 06

#include <iostream>
#include <cmath>
#include <string>
#include <numeric>
#include <tuple>
#include <set>
#include <list>
#include <iomanip>

using namespace std;  //gettin lazy...too much std stuff

int main(int argc, char **argv)
{
  unsigned long long sum = 0ll;
  unsigned long long sqSum = 0ll;

  for(unsigned long long i = 1; i <= 100; ++i)
  {
    sum += i;
    sqSum += pow<unsigned long long>(i, 2);
  }

  cout << "Solution: " << fixed << setw(20) << (pow<unsigned long long>(sum, 2) - sqSum) << endl;
  return 0;
}

