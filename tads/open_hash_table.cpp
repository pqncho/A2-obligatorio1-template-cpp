#pragma once

#include "../funciones/enteros.cpp"
#include <cassert>
#include "table.cpp"
#include "hash_func.cpp"
#include "List.h"
#include "ListImp.cpp"
#include <string>

template <class K, class V> class OpenHashTable: public table <K, V> {
    private:
        List<V> **arrBuckets;
        int cap;
        int elems;
        int maxBox;
        int filled;
        hashFunc<K> *h;
       
        std::string ordenALfabetico(std::string s) {
            int* letters = new int[26]();
            for (int i = 0; i < s.length(); i++) {
                letters[s[i] - 'a']++;
            }

            std::string ordered = "";
            for (int i = 0; i < 26; i++) {
                while(letters[i] > 0) {
                    ordered += (char)('a' + i);
                    letters[i]--;
                }
            }
            return ordered;
        }

        virtual void set2(List<V> **arrBuckets, V word){
            word = ordenALfabetico(word);
            int hs = hacerPositivo((this->h->hash(word)))%(this->cap);
            if (arrBuckets[hs]->isEmpty()) {
                this->filled++;
            }
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
        this->cap = cap*2;
        this->arrBuckets = new List<V> *[cap*2];
        if(this->cap <=0) this->cap=1;
        for(int i=0; i<this->cap;i++){
            this->arrBuckets[i] = new ListImp<V>();
        }
        this->elems = 0;
        this->maxBox = 0;
        this->filled = 0;
        this->h = h;
    }
        virtual void set(V value) override { set2(this->arrBuckets, value); };
        virtual int get(V value) override { return get2(this->arrBuckets, value); };
        virtual int getMaxBox() override { return this->maxBox; };
        virtual int getFilledBoxes() override { return this->filled; };
};
