#pragma once

#include "hash_func.cpp"
#include <string>

class stringHash : public hashFunc<std::string> {
public:

    virtual int hash(std::string word) override {
        int p = 31;
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
