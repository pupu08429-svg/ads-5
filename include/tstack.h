#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

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
      if (!isFull()) {
        data[++topIndex] = value;
      }
    }

    void pop() {
      if (!isEmpty()) {
        --topIndex;
      }
    }

    T top() const {
      return data[topIndex];
    }

    T popAndGet() {
      return data[topIndex--];
    }

    int getSize() const {
      return topIndex + 1;
    }
};

#endif
