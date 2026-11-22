#pragma once

template <class E, class P> class priorityQueue {
public:
  virtual void push(E elem, P prio) = 0;
  virtual E top() = 0;
  virtual E pop() = 0;
  virtual int size() = 0;
  virtual bool isEmpty() = 0;
};