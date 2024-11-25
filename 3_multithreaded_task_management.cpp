#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

#include "my_queue.hpp"
#include "task.hpp"

void add_task_to_queue(MyQueue<Task> *queue, std::string message)
{
  std::cout << "Pushing a task onto the queue..." << std::endl;
  Task t(message);
  queue->push(t);
}

void process_task_on_queue(MyQueue<Task> *queue)
{
  std::cout << "Processing the next task..." << std::endl;
  queue->pop().execute();
}

int main()
{
  MyQueue<Task> queue;

  std::thread t0(add_task_to_queue, &queue, "Task 0\n");
  std::thread t1(add_task_to_queue, &queue, "Task 1\n");
  std::thread t2(add_task_to_queue, &queue, "Task 2\n");
  std::thread t3(add_task_to_queue, &queue, "Task 3\n");
  std::thread t4(add_task_to_queue, &queue, "Task 4\n");
  std::thread t5(add_task_to_queue, &queue, "Task 5\n");
  std::thread t6(add_task_to_queue, &queue, "Task 6\n");
  std::thread t7(add_task_to_queue, &queue, "Task 7\n");
  std::thread t8(add_task_to_queue, &queue, "Task 8\n");
  std::thread t9(add_task_to_queue, &queue, "Task 9\n");

  while (!queue.is_empty())
  {
    process_task_on_queue(&queue);
    queue.pp();
  }

  t9.join();
  t8.join();
  t7.join();
  t6.join();
  t5.join();
  t4.join();
  t3.join();
  t2.join();
  t1.join();
  t0.join();

  std::cout << "The queue is now empty!" << std::endl;

  return 0;
}
