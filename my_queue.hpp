#include <iostream>

const int MAX_SIZE = 100;

template <typename T>
class MyQueue
{
private:
  T arr[MAX_SIZE];
  T *top;
  T *start;

public:
  MyQueue()
  {
    top = arr;
    start = arr;
  }

  bool is_empty()
  {
    return (top == start);
  }

  bool is_full()
  {
    return (start + MAX_SIZE == top);
  }

  void push(T element)
  {
    if (!is_full())
    {
      *top = element;
      top++;
    }
  }

  T pop()
  {
    if (!is_empty())
    {
      T poppedElement = *start;
      start++;
      return poppedElement;
    }
    else
    {
      throw "Oh no!";
    }
  }

  T peek()
  {
    if (!is_empty())
    {
      T poppedElement = *start;
      return poppedElement;
    }
    else
    {
      throw "Oh no!";
    }
  }

  void pp()
  {
    T *temp = start;
    while (temp < top)
    {
      std::cout << *temp << " ";
      temp++;
    }
    std::cout << std::endl;
  }
};
