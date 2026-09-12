#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/heap.cpp"
#include "tads/min_heap.cpp"

using namespace std;

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
    archivos->consolidate();
    cout << archivos->getWeight() << endl;
    return 0;
}