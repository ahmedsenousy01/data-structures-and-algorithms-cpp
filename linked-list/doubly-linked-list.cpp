#pragma once

template <typename T>
class Node
{
private:
  T data;
  Node<T> *next;
  Node<T> *prev;

public:
  Node()
  {
    this->data = 0;
    this->next = nullptr;
    this->prev = nullptr;
  }
  Node(T data)
  {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

template <typename T>
class DoublyLinkedList
{
private:
  Node<T> *head;
  Node<T> *tail;
  int size;

public:
  DoublyLinkedList()
  {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
  }

  bool push_back(T data)
  {
    Node<T> *newNode = new Node<T>(data);
    if (this->tail == nullptr)
    {
      this->head = newNode;
      this->tail = newNode;
    }
    else
    {
      this->tail->next = newNode;
      newNode->prev = this->tail;
      this->tail = newNode;
    }
    this->size++;
    return true;
  }

  bool pop_back()
  {
    if (this->tail == nullptr)
      return false;

    Node<T> *temp = this->tail;
    this->tail = this->tail->prev;
    delete temp;
    this->size--;
    return true;
  }

  bool push_front(T data)
  {
    Node<T> *newNode = new Node<T>(data);
    if (this->head == nullptr)
    {
      this->head = newNode;
      this->tail = newNode;
    }
    else
    {
      this->head->prev = newNode;
      newNode->next = this->head;
      this->head = newNode;
    }
    this->size++;
    return true;
  }

  bool pop_front()
  {
    if (this->head == nullptr)
      return false;

    Node<T> *temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->size--;
    return true;
  }

  bool insert(int index, T data)
  {
    if (index < 0 || index > this->size)
      return false;

    Node<T> *newNode = new Node<T>(data);
    if (index == 0)
      return push_front(data);
    if (index == this->size)
      return push_back(data);

    Node<T> *temp = this->head;
    for (int i = 0; i < index - 1; i++)
      temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    this->size++;
    return true;
  }

  bool remove(int index)
  {
    if (index < 0 || index >= this->size)
      return false;

    if (index == 0)
      return pop_front();
    if (index == this->size - 1)
      return pop_back();

    Node<T> *temp = this->head;
    for (int i = 0; i < index; i++)
      temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    this->size--;
    return true;
  }

  T at(int index)
  {
    if (index < 0 || index >= this->size)
      throw exception();

    Node<T> *temp = this->head;
    for (int i = 0; i < index; i++)
      temp = temp->next;

    return temp->data;
  }

  int find(T value)
  {
    Node<T> *temp = this->head;
    for (int i = 0; i < this->size; i++)
    {
      if (temp->data == value)
        return i;
      temp = temp->next;
    }
    return -1;
  }

  int length()
  {
    return this->size;
  }

  T operator[](int index)
  {
    return at(index);
  }
};
