#pragma once

#include <cassert>
#include "table.cpp"
#include "List.h"

class OpenHashTable: public Table {
    private:
        List<std::string> **arrBuckets = nullptr;
        int cap = 0;
        int elems = 0;

        std::string ordenALfabetico(std::string s) {
            int* letters = new int[26]();
            for (char c : s) {
                letters[c - 'a']++;
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

        int hash(std::string word) {
            word = ordenALfabetico(word);
            int p = 7;
            int m = 1e9 + 9;
            long long hash_value = 0;
            long long pow = 1;

            for (char c : word) {
                hash_value = (hash_value + (c - 'a' + 1)*pow)%m;
                pow = (pow * p)%m;
            }
            
            return hash_value;
        }

        virtual void set2(List<std::string> **arrBuckets, std::string word){
            int h = hash(word)%(this->cap);
            arrBuckets[h]->insert(word);
        }

    public:
        OpenHashTable(int cap) {
        this->arrBuckets = new List<std::string> *[cap];
        this->elems = 0;
        this->cap = cap;
    }
        virtual void set(std::string value) override { set2(this->arrBuckets, value); };
        virtual std::string get(int key) override { assert(false); }
        virtual bool exists(int key) override { assert(false); }
};