#pragma once

#include "../funciones/enteros.cpp"
#include "table.cpp"
#include "hash_func.cpp"
#include "list.cpp"
#include "linked_list.cpp"

template <class K, class V> class OpenHashTable: public table <K, V> {
    private:
        struct funnypair {
            K elem;
            int times;

            funnypair(){}

            funnypair(K elem, int times){
                this->elem = elem;
                this->times = times;
            }

            bool operator==(const funnypair &other) {
                return this->elem == other.elem;
            }
        };

        list<funnypair> **arrBuckets;
        int cap;
        int elems;
        int maxBox;
        int filled;
        hashFunc<K> *h;
       

        virtual void set2(list<funnypair> **arrBuckets, V word){
            int hs = hacerPositivo((this->h->hash(word)))%(this->cap);
        
            funnypair fp = funnypair(word, 1);
            int posLista = this->arrBuckets[hs]->findPos(fp);

            if(posLista == -1) { //nuevo cajon
                this->arrBuckets[hs]->add(fp);
                this->filled++; 
                if(this->maxBox == 0) this->maxBox++; //1er cajon
            } else {
                funnypair actualizar = this->arrBuckets[hs]->getPos(posLista);
                this->arrBuckets[hs]->remove(actualizar);
                actualizar.times++;
                this->arrBuckets[hs]->add(actualizar);
                if (actualizar.times > this->maxBox) {
                    this->maxBox = actualizar.times;
                }
            }
        }

        virtual int get2(list<funnypair> **arrBuckets, V value){
            int hs = hacerPositivo((this->h->hash(value)))%(this->cap);
            funnypair fp = funnypair(value, 1);
            int posLista = this->arrBuckets[hs]->findPos(fp);
            fp = arrBuckets[hs]->getPos(posLista);
            if(fp) return fp.times;
            return 0;
        }

    public:
        OpenHashTable(int cap, hashFunc<K> *h) {
            if(cap < 0) cap = cap*(-1);
            this->cap = (cap*2)/3;
            this->arrBuckets = new list<funnypair>*[(cap*2)/3];
            for(int i=0; i<this->cap;i++){
                this->arrBuckets[i] = new linkedList<funnypair>();
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
