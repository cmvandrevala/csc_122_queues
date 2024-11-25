#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

#include "my_queue.hpp"
#include "task.hpp"

void add_task_to_queue(MyQueue<Task> *queue, std::string message)
{
  std::cout << "Pushing a task onto the queue..." << std::endl;
  Task task(message);
  queue->push(task);
}

void process_task_on_queue(MyQueue<Task> *queue)
{
  std::cout << "Processing the next task..." << std::endl;
  queue->pop().execute();
}

int main()
{
  MyQueue<Task> queue;

  for (int i = 0; i < 10; i++)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    add_task_to_queue(&queue, "This is a task!\n");
  }

  while (!queue.is_empty())
  {
    process_task_on_queue(&queue);
    queue.pp();
  }
}
