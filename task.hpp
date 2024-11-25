#include <iostream>

class Task
{
private:
  std::string message;

public:
  Task()
  {
    message = "";
  }

  Task(std::string msg) : message(msg) {}

  void execute()
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << message << std::endl;
  }

  std::string get_message() const
  {
    return message;
  }

  friend std::ostream &operator<<(std::ostream &os, const Task &t)
  {
    // Uncomment the following line if you want to see the text of the messages
    // os << "[STREAM] A task with a message of " << t.get_message();
    return os;
  }
};
