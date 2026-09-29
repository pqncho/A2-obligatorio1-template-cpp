#pragma once

#include "graph.cpp"
#include "list.cpp"
#include "linked_list.cpp"
#include <cassert>

class adyacencyList : public Graph {
private:
    list<edge>** arrAdy;
    int verts;
    bool isDirected;

public:
    adyacencyList(int vs){
        this->verts = vs;
        this->arrAdy = new list<edge> *[vs];
        for (int i = 0; i < this->verts; i++) {
            this->arrAdy[i] = new linkedList<edge>(); // a chequear
        }
    }
    
    virtual void addEdge(int v1, int v2) override { // v1 -> v2
        //cambiar
        addWeightedEdge(v1, v2, 1);
    }

    virtual void addWeightedEdge(int v1, int v2, int weight) override {
        assert(v1 > 0);
        assert(v1 <= this->verts);
        assert(v2 > 0);
        assert(v2 <= this->verts);
        assert(weight > 0);

        edge newEdge = edge(v1, v2, weight);
        arrAdy[v1]->remove(newEdge);
        arrAdy[v1]->add(newEdge);
    }

    virtual void removeEdge(int v, int w) override {
        assert(v > 0);
        assert(v <= this->verts);
        assert(w > 0);
        assert(w <= this->verts);

        edge ne = edge(v, w, 1);
        this->arrAdy[v]->remove(ne);
    }

    virtual int* entryDegree() override {
        int* degs = new int[this->verts];
        for (int i = 1; i < this->verts; i++) {
            degs[i] = this->arrAdy[i]->size();
        }
        return degs;
    }

    virtual bool hasEdge(int v1, int v2) override {
        if(v1 >= this->verts || v2 >= this->verts) return false;
        edge ne = edge(v1, v2, 1);
        return true;//this->arrAdy[v1]->getTimesBy(ne) != 0;
    } 

    virtual edge getEdge(int v, int w) override {
        assert(v > 0);
        assert(v <= this->verts);
        assert(w > 0);
        edge ne = edge(v, w, 1);
        return this->arrAdy[v]->get(ne); //hay q hacerlos
    }
    virtual Iterator<edge> *getAllEdges() override {
        list<edge> *collection = new linkedList<edge>();

        for (int i = 1; i < this->verts; i++) {
            Iterator<edge> *it = this->arrAdy[i]->getIterator();
            while (it->hasNext()) {
                collection->add(it->next());
            }
        }

        return collection->getIterator();
    }

    virtual Iterator<edge> *getNeighbors(int n) override { 
        return this->arrAdy[n]->getIterator(); 
    }

    virtual int **adjMatrix() override {
        int **mat = new int *[this->verts + 1];

        for (int i = 1; i <= this->verts; i++) {
            mat[i] = new int[this->verts + 1];
        }

        Iterator<edge> *it = getAllEdges();
        while (it->hasNext()) {
            edge e = it->next();
            mat[e.from][e.to] = e.weight;
        }

        return mat;
    }
    
    virtual int V() override {
        return this->verts;
    }

};
