#pragma once 

#include <cassert>
#include "heap.cpp"

template <class T> class minHeap : public heap<T> {
    private:
        T* arr;
        int arrLength;
        int ix;
        long long weight;

        void swap(int posA, int posB) {
            T aux = this->arr[posA];
            this->arr[posA] = this->arr[posB];
            this->arr[posB] = aux;
        }

        void siftUp(int pos) {
            if(pos == 1) return;

            //comparo con el padre
            int pPos = pos/2;
            T elem = this->arr[pos];
            T parent = this->arr[pPos];

            if(parent > elem) {
                swap(pos, pPos);
                siftUp(pPos);
            }
        }
    
    public:
        minHeap(int size) {
            this->arr = new T[size + 1];
            this->arrLength = size + 1;
            this->ix;
            this->weight = 0;
        }

        virtual void push(T elem) override { 
            this->ix++;
            this->arr[this->ix] = elem;
            siftUp(this->ix);
         }
        virtual T top() override { assert(false); }
        virtual T pop() override { assert(false); }
        virtual int size() override { assert(false); }
};