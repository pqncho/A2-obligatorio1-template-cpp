#pragma once

class disjointSet {
private:
    int* arr;
    int* size;
    int n;

public:
    disjointSet(int n){
        this->arr = new int[n+1];
        this->size = new int[n+1];
        for (int i= 0; i <= n; i++) {
            arr[i] = i;
            size[i] = 1;
        }
        this->n = n;
    }
    int find(int v){
        if(v == this->arr[v]) return v;
        this->arr[v] = find(this->arr[v]);
        return arr[v];
    }
    void unionn(int v, int w){
        int a = find(v);
        int b = find(w);
        if(a != b){
            if(this->size[a] < this->size[b]){
                int aux = a;
                a = b;
                b = aux;
            }
            this->arr[b] = a;
            this->size[a] += this->size[b];
        }
    }
    int sets(){
        int s = 0;
        for(int i=1; i <= this->n; i++){
            if(arr[i] == i) s++;
        }
        return s;
    }
};