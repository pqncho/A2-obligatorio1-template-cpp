#pragma once

#include "list.cpp"

template <class T> class Graph {
public:
    virtual list<T> adyacents(T n) = 0;
    virtual T* entryDegree() = 0;
    
};