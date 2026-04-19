// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

#include <cassert>

#include <iostream>

template<typename T, int Nsize>
class TStack {
private:
  T data[Nsize];
  int topIndex;

public:
  TStack() : topIndex(-1) {}
  bool isEmpty() const {
    return topIndex == -1;
  }
  bool isFull() const {
    return topIndex == Nsize - 1;
  }
  void push(const T& value) {
    assert(!isFull() && "Stack overflow!");
    data[++topIndex] = value;
  }
  void pop() {
    assert(!isEmpty() && "Stack underflow!");
    --topIndex;
  }
  T top() const {
    assert(!isEmpty() && "Stack is empty!");
    return data[topIndex];
  }
  T popAndGet() {
    assert(!isEmpty() && "Stack underflow!");
    return data[topIndex--];
  }
  void clear() {
    topIndex = -1;
  }
  int getsize() const {
    return topIndex + 1;
  }
};

#endif  // INCLUDE_TSTACK_H_
