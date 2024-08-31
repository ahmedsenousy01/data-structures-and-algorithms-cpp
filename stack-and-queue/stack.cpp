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
};

int main()
{
  Stack<int> s;
  s.push(12);
  s.push(13);
  cout << s.top() << endl;
}
