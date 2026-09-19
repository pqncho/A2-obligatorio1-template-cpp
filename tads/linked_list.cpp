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
            this->times = 1;
        }
    };

    class linkedListIterator: public iterator<T> {
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

    int getTimes(node* h, T d){
        if(h == nullptr) return 0;
        if(h->data == d) return h->times;
        return getTimes(h->next, d);
    }

public:
    linkedList(){}

    virtual iterator<T>* getIterator() override {
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

    virtual int size() override { return this->count; }

    virtual int getTimesBy(T data) override { return getTimes(this->head, data);}
};