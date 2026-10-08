#pragma once

#include "list.cpp"

template <class T> class linkedList : public list<T> {
private:
    struct node{
        T data;
        node *next;

        node(T data){
            this->data = data;
        }
    };

    class linkedListIterator: public Iterator<T> {
    private:
        node* now;
    public:
        linkedListIterator(node* head){
            this->now = head;
        }

        virtual bool hasNext() override {
            return this->now != nullptr;
        }

        virtual T next() override {
            T e = now->data;
            now = now->next;
            return e;
        }
    };

    node* head = nullptr;
    int count = 0;


public:
    linkedList(){}

    virtual Iterator<T>* getIterator() override {
        return new linkedListIterator(this->head);
    }

    virtual void add(T d) override {
        if(this->head == nullptr){
            this->head = new node(d);
        } else {
            node* nd = new node(d);
            nd->next = this->head;
            this->head = nd;
        }
    }
    
    virtual int findPos(T data) override {
        node* nd = this->head;
        bool es = false;
        int ix = 0;
        while((nd != nullptr) && !es){
            if(nd->data == data){
                es = true;
            } else {
                ix++;
            }
            nd = nd->next;
        }
        return ix;
    }

    virtual T getPos(int ix) override {
        if((ix >= this->count) || (ix < 0)) return nullptr;
        node* dato = this->head;
        while(ix > 0){
            dato = dato->next;
            ix--;
        }
        return dato->data;
    }

    virtual void remove(T data) override {
        if(!this->head) return;
        node* nd = this->head;
        if(nd->data == data) this->head = nd->next;
        while(nd->next != nullptr && nd->next->data != data) nd = nd->next;
        if(nd){
            nd->next = nd->next->next;
        }
    }

    virtual int size() override { return this->count; } //cantidad de elems distintos

  
};