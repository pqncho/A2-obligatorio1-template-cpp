#pragma once

template <class T> class heap {
public:
    virtual void push(T elem) = 0;
    virtual T top() = 0;
    virtual T pop() = 0;
    virtual int size() = 0;
};