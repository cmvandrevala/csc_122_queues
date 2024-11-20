#include <iostream>

#include "my_queue.hpp"

int main()
{
  MyQueue<int> queue;

  queue.push(1);
  queue.pp();
  queue.push(2);
  queue.pp();
  queue.push(3);
  queue.pp();
  queue.push(4);
  queue.pp();
  queue.push(5);
  queue.pp();

  queue.pop();
  queue.pp();
  queue.pop();
  queue.pp();
  queue.pop();
  queue.pp();
  queue.pop();
  queue.pp();
  queue.pop();
  queue.pp();
}
