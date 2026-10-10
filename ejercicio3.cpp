#include <cassert>
//#include <string>
#include <iostream>
//#include <limits>
#include "tads/heap.cpp"
#include "tads/min_heap.cpp"

using namespace std;

long long consolidate(heap<long long>* ar){
    long long weight = 0;

    while(ar->size() > 1){
        long long min1 = ar->pop();   
        long long min2 = ar->pop();
        long long merge = min1 + min2;
        weight += merge;
        ar->push(merge);
    }
    return weight;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    heap<long long> *archivos = new minHeap<long long>(n);
    for (int i = 0; i < n; i++) {
        long long ans;
        cin >> ans;
        archivos->push(ans);
    }

    
    cout << consolidate(archivos) << endl;
    return 0;
}