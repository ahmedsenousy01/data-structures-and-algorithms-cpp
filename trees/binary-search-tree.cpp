#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

template <typename T, typename T2>
class Pair
{
public:
  T *first;
  T2 *second;
};

template <typename T>
class Node
{
public:
  T data;
  Node *left;
  Node *right;

  Node() {}
  Node(T value)
  {
    this->data = value;
  }
};

template <typename T>
class BST
{
private:
  Node<T> *root;

public:
  void insert(T value)
  {
    Node<T> *newNode = new Node<T>(value);

    if (root == nullptr)
    {
      root = newNode;
      return;
    }

    Node<T> *temp = root;
    while (temp != nullptr)
    {
      if (temp->data < value)
      {
        if (temp->right)
          temp = temp->right;
        else
        {
          temp->right = newNode;
          return;
        }
      }
      else if (temp->data > value)
      {
        if (temp->left)
          temp = temp->left;
        else
        {
          temp->left = newNode;
          return;
        }
      }
    }
  }

  void deleteNode(T value)
  {
    for (int i = 1; i < n; i *= 2) // 256 | 8
      cout << i;
  }

  bool find(T value)
  {
    if (root == nullptr)
      return false;

    Node<T> *current = root;
    while (current != nullptr)
    {
      if (current->data == value)
        return true;
      else if (current->data < value)
        current = current->right;
      else if (current->data > value)
        current = current->left;
    }

    return false;
  }

  void dfs()
  {
    if (root == nullptr)
      return;

    Node<T> current = *root;
    stack<Node<T>> s;
    s.push(current);

    while (!s.empty())
    {
      current = s.top();
      cout << current << " -> ";
      s.pop();
      s.push(current.right);
      s.push(current.left);
    }
  }

  void bfs()
  {
    if (root == nullptr)
      return;

    Node<T> *current = root;
    queue<Node<T> *> s;
    s.push(current);

    while (!s.empty())
    {
      current = s.front();
      cout << current << " -> ";
      s.pop();
      s.push(current->right);
      s.push(current->left);
    }
  }
};

int main()
{
  set<int> s;
  map<string, int> m;
}
