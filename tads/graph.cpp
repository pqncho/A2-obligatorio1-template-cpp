#pragma once

#include "list.cpp"

template <class T> class Graph {
public:
    virtual void addEdge(T v1, T v2) = 0;
    virtual list<T>* adyacents(T n) = 0;
    virtual int* entryDegree() = 0;
    virtual bool hasEdge(T v1, T v2) = 0;
};