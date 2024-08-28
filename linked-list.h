#pragma once
#include <exception>

template <typename T>
class Node
{
private:
  T data;
  Node<T> *next;

public:
  Node() {}
  Node(T data)
  {
    this->data = data;
  }
};

template <typename T>
class LinkedList
{
private:
  Node<T> *head;
  int size = 0;

public:
  LinkedList()
  {
    this->head = nullptr;
  }

  bool push_back(T data) // O(n)
  {
    if (this->head == nullptr)
      this->head = new Node<T>(data);

    Node<T> *temp = head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    temp->next = new Node<T>(data);
    this->size++;
    return true;
  }

  bool pop_back() // O(n)
  {
    if (this->head == nullptr)
      return false;

    Node<T> *temp = head;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    delete temp;
    this->size--;
    return true;
  }

  bool push_front(T data) // O(1)
  {
    if (this->head == nullptr)
      this->head = new Node<T>(data);

    Node<T> *newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
    this->size++;
    return true;
  }

  bool pop_front()
  {
    if (this->head == nullptr)
      return false;

    Node<T> *toBeDeleted = head;
    head = head->next;
    delete toBeDeleted;
    this->size--;
    return true;
  }

  bool insert(int index, T data)
  {
    if (index < 0 || index >= size)
      return false;

    if (index == 0)
      return push_front(data);

    Node<T> *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
      temp = temp->next;
    }

    Node<T> *toBeInserted = new Node<T>(data);
    toBeInserted->next = temp->next;
    temp->next = toBeInserted;
    this->size++;
    return true;
  }

  bool remove(int index)
  {
    if (index < 0 || index >= size)
      return false;

    if (index == 0)
      return pop_front();

    Node<T> *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
      temp = temp->next;
    }

    Node<T> *toBeDeleted = temp->next;
    temp->next = toBeDeleted->next;
    delete toBeDeleted;
    this->size--;
    return true;
  }

  T at(int index)
  {
    if (index < 0 || index >= size)
      throw exception();

    Node<T> temp = head;
    for (int i = 0; i < index; i++)
    {
      temp = temp->next;
    }

    return temp;
  }

  int find(T data)
  {
    Node<T> temp = head;
    for (int i = 0; temp->next != nullptr; i++)
    {
      if (temp->data == data)
        return i;
      temp = temp->next;
    }

    return -1;
  }

  T operator[](int index)
  {
    return at(index);
  }
};
