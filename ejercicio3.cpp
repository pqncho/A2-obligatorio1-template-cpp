#include <cassert>
//#include <string>
#include <iostream>
//#include <limits>
#include "tads/heap.cpp"
#include "tads/min_heap.cpp"

using namespace std;

void consolidate(heap<long long>* ar){
    if(ar->size() == 1) return;
    long long min1 = ar->top();
    long long min2 = ar->top();
    long long merge = min1 + min2;
    ar->setWeight(ar->getWeight() + merge);
    ar->push(merge);
    consolidate(ar);
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

    consolidate(archivos);
    cout << archivos->getWeight() << endl;
    return 0;
}