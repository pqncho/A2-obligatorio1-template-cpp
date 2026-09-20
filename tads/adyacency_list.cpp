#pragma once

#include "graph.cpp"
#include "list.cpp"
#include "linked_list.cpp"

template <class T> class adyacencyList : public Graph<T> {
private:
    list<T>** arrAdy;
    int cap;

public:
    adyacencyList(int vs){
        this->cap = vs;
        this->arrAdy = new list<T> *[vs];
        for (int i = 0; i < this->cap; i++) {
            this->arrAdy[i] = new linkedList<T>();
        }
    }
    
    virtual void addEdge(T v1, T v2) override { // v1 -> v2
        this->arrAdy[v2]->add(v1);
    }

    virtual list<T>* adyacents(T n) override { 
        if(n >= this->cap || n < 1) return nullptr;
        //devolver directamente el iterador?
        return this->arrAdy[n]; } //copyList(this->arrAdy[n]) si le hacemos algun cambio
    
        virtual int* entryDegree() override {
        int* degs = new int[this->cap];
        for (int i = 1; i < this->cap; i++) {
            degs[i] = this->arrAdy[i]->size();
        }
        return degs;
    }

    virtual bool hasEdge(T v1, T v2) override {
        if(v1 >= this->cap || v2 >= this->cap) return false;
        return this->arrAdy[(int)v1]->getTimesBy(v2) != 0;
    } 
};
