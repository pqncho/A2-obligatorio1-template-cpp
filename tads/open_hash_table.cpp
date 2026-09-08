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
            arrBuckets[hs]->insert(word);
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
        virtual V get(K key) override { assert(false); }
        virtual bool exists(K key) override { assert(false); }
};