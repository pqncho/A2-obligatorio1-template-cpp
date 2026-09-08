#pragma once


template <class K, class V> class table {
public:
    virtual void set(V value) = 0;
    virtual int get(V value) = 0;
    virtual int getMaxBox() = 0;
    virtual int getFilledBoxes() = 0;

};