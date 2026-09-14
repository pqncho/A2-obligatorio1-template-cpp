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
    virtual void push(E elem, P prio) override { assert(false); }
    virtual E top() override { assert(false); }
    virtual E pop() override { assert(false); }
    virtual int size() override { assert(false); }
    virtual bool isEmpty() override { assert(false); }

};