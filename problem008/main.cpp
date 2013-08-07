//David Oguns
//Project Euler Problem 08

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <numeric>

using namespace std;  //gettin lazy...too much std stuff

//this method actually only gets called once in a slightly optimized solution(?)
unsigned long window_product(const string &longNumber, unsigned int begin, unsigned int window_size)
{
  unsigned long product = 1;
  for(unsigned int idx = 0; idx < window_size; ++idx)
  {
    product *= atoi(longNumber.substr(begin+idx, 1).c_str());
  }
  return product;
}

int main(int argc, char **argv)
{ 
  ifstream fin(argv[1]);
  if(!fin)
  {
    cerr << "Can't read input file for number." << endl;
    return 1;
  }
  stringstream sstream; //used like Java stringbuffer/stringbuilder
  string line;
  while(fin >> line)
  {
    sstream << line;
  }
  fin.close();
  string longNumber;
  sstream >> longNumber;  //read out entire long number

  cout << "Number: ["<<longNumber<<"]" << endl;
  unsigned long largestProduct = 0;
  const unsigned int window_size = 5;   //also the number of consecutive digits we're looking at

  /*  We're going to move a sliding window across the number
   *
   */
  unsigned int previousProduct = window_product(longNumber, 0, window_size);
  unsigned int numberOut = atoi(longNumber.substr(0, 1).c_str());   //this is the number we are NO LONGER including in our product
  //TODO: don't like having this logic in there twice
  if(previousProduct > largestProduct)
  {
    previousProduct = largestProduct;
  }
  for(unsigned int beginIndex = 1; beginIndex+window_size < longNumber.size(); ++beginIndex)
  {
    unsigned int numberIn = atoi(longNumber.substr(beginIndex+(window_size-1), 1).c_str());  //? - off by one?

    //grand idea - doesn't work with digits == 0
    //previousProduct *= numberIn;
    //previousProduct /= numberOut;
    previousProduct = window_product(longNumber, beginIndex, window_size);
  
    if(previousProduct > largestProduct)
    {
      largestProduct = previousProduct;
    }
    numberOut = atoi(longNumber.substr(beginIndex,1).c_str());
  }

  cout << "Solution: " << largestProduct << endl;
  return 0;
}


