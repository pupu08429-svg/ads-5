// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

#include <iostream>
template<typename T, int SSize>
class TStack {
 private:
  T arr[SSize];
  int top;

 public:
  TStack() : top(-1) {}
  int getSize() const { return top+1; }
  bool isEmpty() const { return top == -1; }
  void push(const T& item) {
    if (top < SSize - 1)
      arr[++top] = item;
    else
      throw "Full stack";
  }
  T get() const {
    if (top >= 0)
      return arr[top];
    else
      throw "Empty stack";
  }
  void pop() {
    if (top >= 0)
      top--;
    else
      throw "Empty stack";
  }
};

#endif  // INCLUDE_TSTACK_H_

