#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

template <typename T>
class Node
{
public:
  T data;
  vector<Node<T> *> children;
};

template <typename T>
class Tree
{
public:
  Node<T> *root;

  Node<T> *dfs(T data)
  {
    Node<T> *temp = root;
    stack<Node<T> *> s;
    s.push(temp);
    while (s.size() != 0)
    {
      Node<T> *top = s.top();
      if (top->data == data)
      {
        return top;
      }
      s.pop();
      for (int i = top->children.size() - 1; i >= 0; i--)
      {
        s.push(top->children[i]);
      }
    }
    return nullptr;
  }

  Node<T> *bfs(T data)
  {
    Node<T> *temp = root;
    queue<Node<T> *> q;
    q.push(temp);
    while (q.size() != 0)
    {
      Node<T> *front = q.front();
      if (front->data == data)
      {
        return front;
      }
      q.pop();
      for (int i = 0; i < front->children.size(); i++)
      {
        q.push(front->children[i]);
      }
    }
    return nullptr;
  }
};
