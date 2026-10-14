#include <cassert>
//#include <string>
#include <iostream>
//#include <limits>
#include "tads/graph.cpp"
#include "tads/adyacency_list.cpp"
#include "tads/priority_queue.cpp"
#include "tads/min_prio_queue.cpp"

using namespace std;

void ordenacionTopologica(Graph *deps, int v, int *prios){
    int* grEntrada = deps->entryDegree();
    int* ordenCompilacion = new int[v+1]();
    int icom = 1; //index del orden de compilacion 
    priorityQueue<int, int> *compilar = new minPriorityQueue<int, int>(v+1);
    for (int i = 1; i <= v; i++) {
        if(grEntrada[i] == 0) compilar->push(i, prios[i]);
    } //agregamos todos los que no tienen dependencias
    while(!compilar->isEmpty()) {
        //usamos el icom para chequear  que esten todos los vertices contados
        int v = compilar->pop();
        ordenCompilacion[icom] = v; //agregamos en el orden q da el heap
        icom++;
        Iterator<edge> *vecinos = deps->getNeighbors(v);
        while(vecinos->hasNext()) {
            int ady = vecinos->next().to;
            grEntrada[ady]--;
            if(grEntrada[ady] == 0) compilar->push(ady, prios[ady]); //chequear indicies lpm
        }
    }
    if(icom <= v) {
        cout << "imposible" << endl;
        //delete [] ordenCompilacion;
    } else {
        for (int i = 1; i < icom; i++) {
            cout << ordenCompilacion[i] << endl;
        }
    }
}

int main()
{
    int v;
    int a;
    cin >> v >> a;
    Graph *deps = new adyacencyList(v, true);
    int *prios = new int[v+1]();
    int ans;
    for (int i = 1; i <= v; i++) {
        cin >> ans;
        prios[i] = ans;
    }
    //dependencias
    int ans2;
    for (int i = 0; i < a; i++) {
        cin >> ans;
        cin >> ans2;
        //hacer getedge, si da bien no agregarlo
        deps->addEdge(ans, ans2); 
    }
    ordenacionTopologica(deps, v, prios);
    return 0;
}