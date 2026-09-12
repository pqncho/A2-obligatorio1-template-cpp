#pragma once 
#include <iostream>
#include <cassert>
#include "heap.cpp"

template <class T> class minHeap : public heap<T> {
    private:
        T* arr;
        int arrLength;
        int ix;
        T weight;

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

        void siftDown(int pos) {
            if(pos == this->ix || pos == this->arrLength) return;
            if((2*pos)+1 >= this->arrLength) return;
            T leftSon = this->arr[2*pos];
            T rightSon = this->arr[2*pos + 1];
            T parent = this->arr[pos];
        
            if(parent > leftSon || parent > rightSon || (2*pos)+1>this->ix){

                if(leftSon <= rightSon || (2*pos)+1>this->ix) {
                    swap(pos, 2*pos);
                   
                    siftDown(2*pos);
                } else {
                    swap(pos, 2*pos + 1);
                    
                    siftDown(2*pos + 1);
                    
                }
            }
        }

        T remove() {
            T data = this->arr[1];
            swap(1, this->ix);
            this->ix--;
            siftDown(1);
            
            return data;
        }

        void consolidatee(){
            if(this->ix == 1) return;
            for(int i=1 ; i<= this->ix ; i++){
                std::cout << this->arr[i] << std::endl;
            }
            T min1 = remove();
            T min2 = remove();
            std::cout << min1 << " este es min1" << std::endl;
            std::cout << min2 << " este es min2" << std::endl;
            T merge = min1 + min2;
            weight+= merge;
            std::cout << weight << " este es weigth broder" << std::endl;
            std::cout << merge << " este es merge bro" << std::endl;
            push(merge);
            consolidatee();
        }

    
    public:
        minHeap(int size) {
            this->arr = new T[size + 1]();
            this->arrLength = size + 1;
            this->ix = 0;
            this->weight = 0;
        }

        virtual void push(T elem) override
        { 
             this->ix++;
             this->arr[this->ix] = elem;
             siftUp(this->ix);
             
             }
        
        virtual T top() override { assert(false); }
        virtual T pop() override { assert(false); }
        virtual void consolidate() override { consolidatee(); }
        virtual int size() override { return this->ix; }
        virtual T getWeight() override {return this->weight; }
};