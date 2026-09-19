#include <cassert>
#include <string>
#include <iostream>
//#include <limits>
#include "tads/graph.cpp"
#include "tads/adyacency_list.cpp"

using namespace std;

int main()
{
    int v;
    int a;
    cin >> v >> a;
    Graph<int> *deps = new adyacencyList<int>(v+1); //probablemente no sea int
    string ans;
    for (int i = 0; i < v; i++) {
        cin >> ans;
        //aca agregar la prioridad de cada modulo
    }
    return 0;
}