//David Oguns
//Project Euler Problem 02

#include <iostream>
#include <tuple>
#include "fib.h"

using std::cout;
using std::endl;
using std::tuple;
using std::get;

int main(int argc, char **argv)
{
  const int THRESHOLD = 4000000;
  tuple<int, int> prev(1, 2);

  int sum = 0;
  int item = 0;
  while((item = get<0>(prev)) < THRESHOLD) {
    if((get<0>(prev)%2) == 0)
    {
      sum += get<0>(prev);
    }
    prev = Fib::nextFib(prev);
  }

  cout << "Solution: " << sum << endl;
}
