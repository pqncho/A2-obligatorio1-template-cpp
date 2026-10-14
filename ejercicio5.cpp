#include <cassert>
#include <cstdint>
#include <string>
#include <iostream>
//#include <limits>
#include "tads/min_prio_queue.cpp"
#include "tads/priority_queue.cpp"
#include "tads/graph.cpp"
#include "tads/adyacency_list.cpp"
#include "tads/disjoint_set.cpp"

using namespace std;

int main()
{
    int v;
    int e;
    cin >> v >> e;
    Graph* g = new adyacencyList(v, false);
    for (int i = 0; i < e; i++) {
        int v1;
        int v2;
        int w;
        cin >> v1 >> v2 >> w;
        g->addWeightedEdge(v1, v2, w);
    }
    //kruskal
    int64_t total = 0;
    priorityQueue<edge, int>* pq = new minPriorityQueue<edge, int>(e);
    Iterator<edge>* it = g->getAllEdges();
    while(it->hasNext()){
        edge e1 = it->next();
        pq->push(e1, e1.weight);
    }
    int count = 0;
    disjointSet* djs = new disjointSet(v);
    while(!pq->isEmpty() && (count < v)){
        edge ed = pq->pop();
        if((ed.from != ed.to) && (djs->find(ed.from) != djs->find(ed.to))){
            djs->unionn(ed.from, ed.to);
            total+= ed.weight;
            count++;
        }
    }
    //comp conexas
    if(djs->sets() > 1){
        cout << "imposible" << endl;
    }else{
        cout << total << endl;
    }

    return 0;
}