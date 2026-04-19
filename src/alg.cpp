// Copyright 2025 NNTU-CS
#include "tstack.h"

#include <cctype>
#include <map>
#include <string>

int getPriority(char op) {
  std::map<char, int> priority = {
    {'(', 0}, {')', 1}, {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3}
  };
  return priority[op];
}
std::string infx2pstfx(const std::string& inf) {
  std::string output;
  TStack<char, 100> stack;
  for (size_t i = 0; i < inf.length(); i++) {
    char current = inf[i];
    if (isdigit(current)) {
      while (i < inf.length() && isdigit(inf[i])) {
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
      }
      stack.push(current);
    }
  }
  while (!stack.isEmpty()) {
    output += stack.popAndGet();
    output += ' ';
  }
  if (!output.empty() && output.back() == ' ') {
    output.pop_back();
  }
  return output;
}
int eval(const std::string& post) {
  TStack<int, 100> stack;
  
  for (size_t i = 0; i < post.length(); i++) {
    char current = post[i];
    if (isdigit(current)) {
      int number = 0;
      while (i < post.length() && isdigit(post[i])) {
             number = number * 10 + (post[i] - '0');
        i++;
      }
      stack.push(number);
      i--;
    } else if (current == '+' || current == '-' ||
               current == '*' || current == '/') {
      int b = stack.popAndGet();
      int a = stack.popAndGet();
      int result = 0;
      switch (current) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': result = a / b; break;
      }
      stack.push(result);
    }
  }
  return stack.popAndGet();
}
