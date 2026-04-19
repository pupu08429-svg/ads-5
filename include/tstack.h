// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <cassert>

template<typename T, int size>
class TStack {
private:
  T data[N];
  int topIndex;
public:
  TStack() : topIndex(-1) {}
  bool isEmpty() const {
    return topIndex == -1;
  }
  bool isFull() const {
    return topIndex == N - 1;
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
  int size() const {
    return topIndex + 1;
  }
};

#endif  // INCLUDE_TSTACK_H_
