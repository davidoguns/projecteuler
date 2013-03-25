//David Oguns
//Simple fibonacci helper function for problem 2 of project euler

#include "fib.h"
#include <tuple>

using std::tuple;
using std::get;
using std::make_tuple;

namespace Fib
{
  //Given a tuple representing the last two numbers in the Fibonnaci sequence
  //generate the next two in another tuple.  C++ 11 move semantics desired here
  tuple<int,int> nextFib(const tuple<int,int> &prev) 
  {
    return make_tuple(get<1>(prev), sum(prev)); 
  }

  //Given a fibonnaci sequence pair, return the sum
  int sum(const std::tuple<int,int> &pair)
  {
    return get<0>(pair)+get<1>(pair);
  }
}

