#pragma once

#include "../funciones/enteros.cpp"
#include "table.cpp"
#include "hash_func.cpp"
#include "list.cpp"
#include "linked_list.cpp"

template <class K, class V> class OpenHashTable: public table <K, V> {
    private:
        list<V> **arrBuckets;
        int cap;
        int elems;
        int maxBox;
        int filled;
        hashFunc<K> *h;
       

        virtual void set2(list<V> **arrBuckets, V word){
            int hs = hacerPositivo((this->h->hash(word)))%(this->cap);
        
            int b4 = arrBuckets[hs]->size();
            arrBuckets[hs]->add(word);
            if (arrBuckets[hs]->size() > b4) this->filled++;
            if (arrBuckets[hs]->getTimesBy(word) > this->maxBox) this->maxBox++;
            //creo q solo con el ++ andaria porq lo chequeamos cada vez q se agrega una palabra, 
            //entonces solo deberia crecer en uno. De ultima el cambio es una boludez.
        }

        virtual int get2(list<V> **arrBuckets, V value){
            int hs = hacerPositivo((this->h->hash(value)))%(this->cap);
            return arrBuckets[hs]->getTimesBy(value);
        }

    public:
        OpenHashTable(int cap, hashFunc<K> *h) {
        this->cap = cap*2;
        this->arrBuckets = new list<V> *[cap*2];
        if(this->cap <=0) this->cap=1;
        for(int i=0; i<this->cap;i++){
            this->arrBuckets[i] = new linkedList<V>();
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
