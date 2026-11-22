#pragma once

template <class T> class bst {
public:
    virtual void add(T data) = 0; //es abstracto
    virtual void remove(T data) = 0; 
    virtual int size() = 0;
    virtual void range(T from, T upto) = 0;
    virtual void search(T data) = 0;
};