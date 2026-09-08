#pragma once

#include "hash_func.cpp"
#include <string>

class stringHash : public hashFunc<std::string> {
public:
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

    virtual int hash(std::string word) override {
        word = ordenALfabetico(word);
        int p = 7;
        int m = 1e9 + 9;
        long long hash_value = 0;
        long long pow = 1;

        for (char c : word) {
            hash_value = (hash_value + (c - 'a' + 1)*pow)%m;
            pow = (pow * p)%m;
        }
            
        return (int)hash_value;
    }
};
