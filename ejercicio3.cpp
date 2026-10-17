#include <cassert>
//#include <string>
#include <iostream>
//#include <limits>
#include "tads/heap.cpp"
#include "tads/min_heap.cpp"
#include <cstdint>

using namespace std;

int64_t consolidate(heap<int64_t>* ar){
    int64_t weight = 0;

    while(ar->size() > 1){
        int64_t min1 = ar->pop();   
        int64_t min2 = ar->pop();
        int64_t merge = min1 + min2;
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
    heap<int64_t> *archivos = new minHeap<int64_t>(n);
    for (int i = 0; i < n; i++) {
        int64_t ans;
        cin >> ans;
        archivos->push(ans);
    }

    
    cout << consolidate(archivos) << endl;
    return 0;
}