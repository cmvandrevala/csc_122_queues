#include <iostream>

#include "my_queue.hpp"

using namespace std;

istream &my_getline(istream &input_stream, MyQueue<char> &queue, char terminating_character)
{
  char character;
  while (input_stream.get(character) && character != terminating_character)
  {
    queue.push(character);
  }
  return input_stream;
}

istream &my_getline(istream &input_stream, MyQueue<char> &queue)
{
  return my_getline(input_stream, queue, '\n');
}

int main()
{
  MyQueue<char> queue;

  cout << "Enter some text!" << endl;
  my_getline(cin, queue);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "Printing the text!" << endl;
  while (!queue.is_empty())
  {
    cout << queue.pop();
  }
  cout << endl;
}
