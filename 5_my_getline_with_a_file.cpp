#include <iostream>
#include <fstream>

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

  cout << "Let's read the data from sample.txt!" << endl;

  ifstream ifs("../sample.txt");

  my_getline(ifs, queue);

  cout << "Printing the text!" << endl;
  while (!queue.is_empty())
  {
    cout << queue.pop();
  }
  cout << endl;
}
