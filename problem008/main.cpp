//David Oguns
//Project Euler Problem 08

#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;  //gettin lazy...too much std stuff

//due to zeroes existing in the sliding window, the most effective way to handle this
//problem is to allow zeroes in the queue, and take the product of the queue

template <typename T>
T queue_product(queue<T> & queue) //rotates the queue in place
{
  T queue_product = 1;
  for(size_t i = size_t(0); i < queue.size(); ++i)
  {
    T queue_item = queue.front();
    queue.pop();
    queue.push(queue_item);
    queue_product *= queue_item;
  }
  return queue_product;
}

int main(int argc, char **argv)
{ 
  unsigned int window_size = 0;
  istringstream(argv[1]) >> window_size; //cmd line arg is window size
  unsigned long long largest_product = 0;
  queue<unsigned long long> digit_queue;
  string line;

  while(cin >> line)
  {
    for(char input:line)
    {
      if(input < '0' || input > '9') continue; //skip non digits
      unsigned long long digit = input - '0';
      digit_queue.push(digit);
      if(digit_queue.size() > size_t(window_size))
      {
        digit_queue.pop();
      }
      const unsigned long long product = queue_product(digit_queue);
      if(product > largest_product)
      {
        largest_product = product;
      }
    }
  }

  cout << largest_product;
  return 0;
}

