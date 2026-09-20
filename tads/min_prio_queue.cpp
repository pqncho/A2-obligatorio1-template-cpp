#pragma once

#include <cassert>
#include "priority_queue.cpp"
#include "min_heap.cpp"

template <class E, class P> class minPriorityQueue : public priorityQueue<E,P> {
private:
    struct pair {
    E elem;
    P prio;


    pair() {} //constructor vacio

    pair(E elem, P prio) {
      this->elem = elem;
      this->prio = prio;
    }

    // this < other
    //los elementos (modulos) nunca son iguales
    bool operator<(const pair &other) { 
        if(this->prio == other.prio) return this->elem < other.elem;
        return this->prio < other.prio; }
    bool operator>(const pair &other) { 
        if(this->prio == other.prio) return this->elem > other.elem;
        return this->prio > other.prio; }
    bool operator<=(const pair &other) { 
        if(this->prio == other.prio) return this->elem < other.elem;
        return this->prio <= other.prio; }
    bool operator>=(const pair &other) { 
        if(this->prio == other.prio) return this->elem > other.elem;
        return this->prio >= other.prio; }
    bool operator==(const pair &other) { 
        return this->prio == other.prio; }
    };

    minHeap<pair> *h; 

public:
    virtual void push(E elem, P prio) override { this->h->push(pair(elem, prio)); }
    virtual E top() override { return this->h->top().elem; }
    virtual E pop() override { return this->h->pop().elem; }
    virtual int size() override { return this->h->size(); }
    virtual bool isEmpty() override { return this->h->isEmpty(); }

};