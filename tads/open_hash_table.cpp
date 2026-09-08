#pragma once

#include <cassert>
#include "table.cpp"
#include "hash_func.cpp"
#include "List.h"

template <class K, class V> class OpenHashTable: public table <K, V> {
    private:
        List<V> **arrBuckets = nullptr;
        int cap;
        int elems;
        int maxBox;
        int filled;
        hashFunc<K> *h;
        float fc;
    

        virtual void set2(List<V> **arrBuckets, V word){
            int hs = this->h->hash(word)%(this->cap);
            if(arrBuckets[hs]->isEmpty()) this->filled++;
            arrBuckets[hs]->insert(word);
            if(arrBuckets[hs]->getSize() > this->maxBox) this->maxBox = arrBuckets[hs]->getSize();
        }

        virtual int get2(List<V> **arrBuckets, V value){
            int hs = this->h->hash(value)%(this->cap);
            return arrBuckets[hs]->getSize();
        }

    public:
        OpenHashTable(int cap, hashFunc<K> *h) {
        this->arrBuckets = new List<V> *[cap * (3/2)];
        this->elems = 0;
        this->cap = cap * (3/2);
        this->fc = 0.0;
        this->maxBox = 0;
        this->filled = 0;
    }
        virtual void set(V value) override { set2(this->arrBuckets, value); };
        virtual int get(V value) override { return get2(this->arrBuckets, value); }
        virtual int getMaxBox() override { return this->maxBox; }
        virtual int getFilledBoxes() override { return this->filled; }
};