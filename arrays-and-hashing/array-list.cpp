#pragma once
#include <exception>

template <typename T>
class ArrayList
{
private:
  T *data;
  int size, capacity;

  void resize(int newCapacity = capacity * 2)
  {
    T *newArray = new T[newCapacity];
    for (int i = 0; i < size; i++)
    {
      newArray[i] = data[i];
    }
    delete[] data;
    data = newArray;
    capacity = newCapacity;
  }

public:
  ArrayList()
  {
    this->size = 0;
    this->capacity = 10;
    this->data = new T[capacity];
  }

  ArrayList(int capacity)
  {
    this->size = 0;
    this->capacity = capacity;
    this->data = new T[capacity];
  }

  bool push_back(T value)
  {
    if (size == capacity)
      resize();

    data[size] = value;
    size++;
    return true;
  }

  bool pop_back()
  {
    if (size == 0)
      return false;

    size--;
    return true;
  }

  bool push_front(T value)
  {
    if (size == capacity)
      resize();

    size++;
    for (int i = size; i > 0; i--)
    {
      data[i] = data[i - 1];
    }
    data[0] = value;
    return true;
  }

  bool pop_front()
  {
    if (size == 0)
      return false;

    for (int i = 0; i < size; i++)
    {
      data[i] = data[i + 1];
    }

    size--;
    return true;
  }

  bool insert(int index, T value)
  {
    if (size == capacity)
      resize();

    size++;
    for (int i = size; i > index; i--)
    {
      data[i] = data[i - 1];
    }
    data[index] = value;
    return true;
  }

  bool remove(int index)
  {
    if (size == 0)
      return false;

    for (int i = index; i < size - 1; i++)
    {
      data[i] = data[i + 1];
    }

    size--;
    return true;
  }

  int find(T value)
  {
    for (int i = 0; i < size; i++)
    {
      if (data[i] == value)
        return i;
    }
    return -1;
  }

  T at(int index)
  {
    if (index < 0 || index >= size)
      throw exception();

    return data[index];
  }

  int length()
  {
    return size;
  }

  T operator[](int index)
  {
    return at(index);
  }
};
