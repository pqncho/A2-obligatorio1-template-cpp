#pragma once


template <class K, class V> class table {
public:
    virtual void set(V value) = 0;
    virtual V get(K key) = 0;
    virtual bool exists(K key) = 0;

};