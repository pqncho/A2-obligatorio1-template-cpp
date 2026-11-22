#pragma once

template <class T> class hashFunc {
public:
    virtual int hash(T t) = 0;
};