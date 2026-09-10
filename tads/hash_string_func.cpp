#pragma once

#include "hash_func.cpp"
#include <iostream>
#include <string>

class stringHash : public hashFunc<std::string> {
public:
    std::string ordenALfabetico(std::string s) {
        int* letters = new int[26]();
        for (int i = 0; i < s.length(); i++) {
            letters[s[i] - 'a']++;
        }
        std::cout << "pasa letters(odena palabra)" << std::endl;

        std::string ordered = "";
        for (int i = 0; i < 26; i++) {
            while(letters[i] > 0) {
                ordered += (char)('a' + i);
                letters[i]--;
            }
        }
        std::cout << "palabra ordenada " << ordered << std::endl;
        return ordered;
    }

    virtual int hash(std::string word) override {
        std::cout << "llega al hash" << std::endl;
        word = ordenALfabetico(word);
        int p = 7;
        int m = 1e9 + 9;
        long long hash_value = 0;
        long long pow = 1;

        for (int i = 0; i < word.length(); i++) {
            hash_value = (hash_value + (word[i] - 'a' + 1)*pow)%m;
            pow = (pow * p)%m;
        }
            
        return (int)hash_value;
    }
};
