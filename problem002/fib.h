//David Oguns
//Simple fibonacci helper function for problem 2 of project euler

#pragma once

#include <tuple>

namespace Fib
{
  //Given a tuple representing the last two numbers in the Fibonnaci sequence
  //generate the next two in another tuple.
  std::tuple<int,int> nextFib(const std::tuple<int,int> &prev);

  //Given a fibonnaci sequence pair, return the sum
  int sum(const std::tuple<int,int> &pair);
}
