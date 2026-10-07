#pragma once

#include "list.cpp"

template <class T> class linkedList : public list<T> {
private:
    struct node{
        T data;
        int times;
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
            this->head->next = nullptr;
            count++;
        } else {
            node* aux = this->head;
            while(aux->next && aux->data != d){
                aux = aux->next;
            }
            if(aux->data == d) {
                aux->times++; 
            } else {
                aux->next = new node(d);
                count++;
            }
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
        if(!this->head)  return;
        
    }

    virtual int size() override { return this->count; } //cantidad de elems distintos

  
};