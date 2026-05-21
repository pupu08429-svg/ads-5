// Copyright 2025 NNTU-CS
#include <string>
#include <cctype>
#include "tstack.h"

int getPriority(char op) {
  switch (op) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '+':
    case '-':
      return 2;
    case '*':
    case '/':
      return 3;
    default:
      return -1;
  }
}

std::string infx2pstfx(const std::string& infix) {
  TStack<char, 100> operators;
  std::string postfix;
  size_t idx = 0;

  while (idx < infix.length()) {
    char current = infix[idx];

    if (isdigit(current)) {
      while (idx < infix.length() && isdigit(infix[idx])) {
        postfix += infix[idx];
        ++idx;
      }
      postfix += ' ';
      continue;
    }

    int priority = getPriority(current);

    if (priority == 0) {          // Открывающая скобка
      operators.push(current);
    } else if (priority == 1) {   // Закрывающая скобка
      while (!operators.isEmpty() && getPriority(operators.get()) != 0) {
        postfix += operators.get();
        postfix += ' ';
        operators.pop();
      }
      operators.pop();            // Удаляем '('
    } else if (priority > 1) {    // Оператор
      while (!operators.isEmpty() &&
             operators.get() != '(' &&
             getPriority(operators.get()) >= priority) {
        postfix += operators.get();
        postfix += ' ';
        operators.pop();
      }
      operators.push(current);
    }
    ++idx;
  }

  while (!operators.isEmpty()) {
    postfix += operators.get();
    if (operators.getSize() != 1) {
      postfix += ' ';
    }
    operators.pop();
  }

  return postfix;
}

// Вычисление значения постфиксного выражения
int eval(const std::string& postfix) {
  TStack<int, 100> values;
  size_t pos = 0;

  while (pos < postfix.length()) {
    char symbol = postfix[pos];

    // Если встретили цифру - собираем число
    if (isdigit(symbol)) {
      std::string number;
      while (pos < postfix.length() && postfix[pos] != ' ') {
        number += postfix[pos];
        ++pos;
      }
      values.push(std::stoi(number));
      ++pos;                     // Пропускаем пробел
      continue;
    }

    // Обработка операторов
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
      int rightVal = values.get();
      values.pop();
      int leftVal = values.get();
      values.pop();

      int result = 0;
      switch (symbol) {
        case '+':
          result = leftVal + rightVal;
          break;
        case '-':
          result = leftVal - rightVal;
          break;
        case '*':
          result = leftVal * rightVal;
          break;
        case '/':
          result = leftVal / rightVal;
          break;
        default:
          break;
      }
      values.push(result);
      pos += 2;                  // Пропускаем оператор и пробел
    } else {
      ++pos;                     // Пропускаем пробел
    }
  }

  return values.get();
}
