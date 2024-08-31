#include <list>
#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
  list<T> data;

public:
  void push(T data)
  {
    return this->data.push_back(data);
  }

  void pop()
  {
    return this->data.pop_front();
  }

  int size()
  {
    return this->data.size();
  }

  T front()
  {
    return this->data.front();
  }

  T back()
  {
    return this->data.back();
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
  Queue<int> q;
  q.push(12);
  q.push(13);
  cout << q.back() << endl;
  cout << q.front() << endl;
}
