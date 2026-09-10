#pragma once

#include "../funciones/enteros.cpp"
#include <cassert>
#include <iostream>
#include "table.cpp"
#include "hash_func.cpp"
#include "List.h"

template <class K, class V> class OpenHashTable: public table <K, V> {
    private:
        List<V> **arrBuckets;
        int cap;
        int elems;
        int maxBox;
        int filled;
        hashFunc<K> *h;
       
    

        virtual void set2(List<V> **arrBuckets, V word){
            int hs = hacerPositivo((this->h->hash(word)))%(this->cap);
            std::cout << "hs es: " << hs << std::endl;
            std::cout << "el cap es: " << this->cap << std::endl;
            if (arrBuckets[hs]->isEmpty()) this->filled++;
            arrBuckets[hs]->insert(word);
            if (arrBuckets[hs]->getSize() > this->maxBox) {
                this->maxBox = arrBuckets[hs]->getSize();
            }
        }

        virtual int get2(List<V> **arrBuckets, V value){
            int hs = hacerPositivo((this->h->hash(value)))%(this->cap);
            return arrBuckets[hs]->getSize();
        }

    public:
        OpenHashTable(int cap, hashFunc<K> *h) {
        this->arrBuckets = new List<V> *[(cap * 3)/2]();
        this->elems = 0;
        this->cap = (cap * 3)/2;
        this->maxBox = 0;
        this->filled = 0;
        this->h = h;
    }
        virtual void set(V value) override { set2(this->arrBuckets, value); };
        virtual int get(V value) override { return get2(this->arrBuckets, value); };
        virtual int getMaxBox() override { return this->maxBox; };
        virtual int getFilledBoxes() override { return this->filled; };
};