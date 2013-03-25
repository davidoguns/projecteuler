//David Oguns
//Project Euler Problem 01

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
  unsigned int SUM_BELOW = 1000; 
  unsigned int sum = 0;

  for(unsigned int index = 0; index < SUM_BELOW; ++index)
  {
    if((index%3) == 0 || (index%5)== 0)
      sum += index;
  }

  cout << "Solution: " << sum << endl;
}
