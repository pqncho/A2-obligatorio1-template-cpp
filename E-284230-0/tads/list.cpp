#pragma once

#include "iterator/iterator.cpp"

template <class T> class list: public iterable<T> {
public:
    virtual void add(T data) = 0;
    virtual int findPos(T data) = 0; //-1 si no esta
    virtual T getPos(int ix) = 0;
    virtual void remove(T data) = 0; //implementar.
    virtual int size() = 0;
   
    
};