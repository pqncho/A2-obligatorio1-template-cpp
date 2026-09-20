#include <cassert>
#include <string>
#include <iostream>
//#include <limits>
#include "tads/graph.cpp"
#include "tads/adyacency_list.cpp"
#include "tads/priority_queue.cpp"
#include "tads/min_prio_queue.cpp"

using namespace std;

int checkCycles(){

    return 0;
}

void ordenacionTopologica(Graph<long long> *deps, int v, long long *prios){
    int* grEntrada = deps->entryDegree();
    bool* visitados = new bool[v+1]();
    priorityQueue<long long, long long> *compilar = new minPriorityQueue<long long, long long>();
    for (int i = 1; i <= v; i++) {
        if(grEntrada[i] == 0) compilar->push(i, prios[i-1]);
    } //agregamos todos los que no tienen dependencias
    for (int i = 0; i < v; i++) {
        long long ver = compilar->pop();
        cout<< ver << endl;
        //cambiar a iterador adyacentes
    }
}

int main()
{
    int v;
    int a;
    cin >> v >> a;
    Graph<long long> *deps = new adyacencyList<long long>(v+1);
    long long *prios = new long long[v];
    string ans;
    for (int i = 0; i < v; i++) {
        cin >> ans; //desp hay q restar uno porq usamos el cero
        prios[i] = stoll(ans);
    }
    //dependencias
    string ans2;
    for (int i = 0; i < a; i++) {
        cin >> ans;
        cin >> ans2;
        deps->addEdge(stoll(ans), stoll(ans2)); 
    }
    //ordenacionTopologica.
    return 0;
}