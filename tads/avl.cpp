#pragma once

#include "bst.cpp"
#include <assert.h>
#include <iostream>

template <class T> class avl : public bst<T> {
private:
    struct node {
        T data;
        node *left = nullptr;
        node *right = nullptr;
        int height = 1;

        //constructor
        node(T data)  { this->data  = data; }
    };

    node *root = nullptr;

     int size(node *n){
        if (n == nullptr) return 0;
        return 1 + (size(n->left) + size(n->right));
    }

    int max(int a, int b) {
        if (a > b) return a;
        return b;
    }

    int height(node *n){
        if (n == nullptr) return 0;
        return n->height;
    }
    
    node *leftRotation(node *n) {

        node *z = n;
        node *y = z->right;
        node *y_l = y->left;
        z->right = y_l;
        y->left = z;

        //height updates
        z->height = 1 + max(height(z->left), height(z->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    node *rightRotation(node *n) {

        node *z = n;
        node *y = z->left;
        node *y_r = y->right;

        z->left = y_r;
        y->right = z;

        //height updates
        z->height = 1 + max(height(z->left), height(z->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    node *rLRotation(node *n) {
        n->right = rightRotation(n->right);
        return leftRotation(n);
    }

    node *lRRotation(node *n) {
        n->left = leftRotation(n->left);
        return rightRotation(n);
    }

    node *balance(node *n) {
        int balf = height(n->left) - height(n->right);
        if(balf == -2){
            // der - ?
            int bfRight = height(n->right->left) - height(n->right->right);
            if (bfRight == -1) {
                n = leftRotation(n);
            } else {
                n = rLRotation(n);
            }
        } else if (balf == 2) {
            // izq - ?
            int bfLeft = height(n->left->left) - height(n->left->right);
            if(bfLeft == -1) {
                n = lRRotation(n);
            } else {
                n = rightRotation(n);
            }
        }
        return n;
    }

    node *add(node *r, T data){
        if (r == nullptr){
            return new node(data);
        }
        if (r->data == data) return r;

        if (data < r->data){
            r->left = add(r->left, data);
        }else{
            r->right = add(r->right, data);
        }

        r->height = 1 + max(height(r->left), height(r->right));
        r = balance(r);

        return r;
    }

    void search(node *n, T data){
        if(n == nullptr){
            std::cout << "no" << std::endl;
            return;
        }
        if(n->data < data) {
            search(n->right);
        } else if (n->data > data){
        search(n->left);
        } else {
            std::cout << "si" << std::endl;
        }
    }
    void range(node *n, T from, T upto) {
        if (n == nullptr) return;
        if((n->data <= upto) && (n->data >= from)) {
            std::cout << n->data << std::endl;
        } else if (n->data > upto){
            range(n->left);
        } else {
            range(n->right);
        }
    }

public:
    avl() {};
    virtual void add(T data) override {
        this->root = add(this->root, data);
    }
    virtual int size() override { assert(false); }
    virtual void remove(T data) override { assert(false); };
    virtual void range(T from, T upto) override { range(this->root, from, upto); };
    virtual void search(T data) override { search(this->root, data); };
};
