// Copyright 2025 NNTU-CS
#include "alg.h"
#include <map>
#include "tstack.h"

#include <string>


int getPriority(char op) {
  std::map<char, int> priority = {
    {'(', 0},
    {')', 1},
    {'+', 2},
    {'-', 2},
    {'*', 3},
    {'/', 3}
  };
  return priority[op];
}
std::string infx2pstfx(const std::string inf) {
  std::string output;
  TStack<char, 100> stack;
  for (size_t i = 0; i < inf.length(); i++) {
    char current = inf[i];
    if (current >= '0' && current <= '9') {
      while (i < inf.length() && inf[i] >= '0' && inf[i] <= '9') {
        output += inf[i];
        i++;
      }
      output += ' ';
      i--;
    } else if (current == '(') {
      stack.push(current);
    } else if (current == ')') {
      while (!stack.isEmpty() && stack.top() != '(') {
        output += stack.popAndGet();
        output += ' ';
        stack.pop();
      }
      if (!stack.isEmpty() && stack.top() == '(') {
        stack.pop();
      }
    } else if (current == '+' || current == '-' ||
               current == '*' || current == '/') {
      while (!stack.isEmpty() && stack.top() != '(' &&
             getPriority(stack.top()) >= getPriority(current)) {
        output += stack.popAndGet();
        output += ' ';
        stack.pop();
      }
      stack.push(current);
    }
  }
  while (!stack.isEmpty()) {
    output += stack.pop();
    if (stack.getSize() != 1) {
      output += ' ';
    }
    stack.pop();
  }
  return output;
}
int eval(const std::string post) {
  TStack<int, 100> stack;
  for (size_t i = 0; i < post.length(); i++) {
    char current = post[i];
    if (current >= '0' && current <= '9') {
      int number = 0;
      while (i < post.length() && post[i] >= '0' && post[i] <= '9') {
             number = number * 10 + (post[i] - '0');
        i++;
      }
      stack.push(number);
      i--;
    } else if (current == '+' || current == '-' ||
               current == '*' || current == '/') {
      int b = stack.pop();
      stack.pop();
      int a = stack.pop();
      stack.pop();
      int result = 0;
      if (current == '+') result = a + b;
        else if '+': result = a + b; break;
        else if '-': result = a - b; break;
        else if '*': result = a * b; break;
        else if '/': result = a / b; break;
      }
      stack.push(result);
    }
  }
  return stack.pop();
}
