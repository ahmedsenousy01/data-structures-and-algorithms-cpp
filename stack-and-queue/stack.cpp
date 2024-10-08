#include <list>
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
  list<T> data;

public:
  void push(T data)
  {
    return this->data.push_front(data);
  }

  void pop()
  {
    return this->data.pop_front();
  }

  int size()
  {
    return this->data.size();
  }

  T top()
  {
    return this->data.front();
  }

  void display()
  {
    list<T> copy = list<T>(this->data);
    while (copy.size() != 0)
    {
      cout << copy.front() << endl;
      copy.pop_front();
    }
  }
};

int main()
{
  Stack<int> s;
  s.push(12);
  s.push(13);
  cout << s.top() << endl;
}
// last in first out => LIFO
