#pragma once

template <class T> class iterator{
public:
    virtual bool hasNext() = 0; //dice si puedo segur llamando next() sin q se rompa
    virtual T next() = 0; //devuelve el siguiente elemento y avanza el iterador
};

template <class T> class iterable{
public:
    virtual iterator<T> *getIterator() = 0;
};