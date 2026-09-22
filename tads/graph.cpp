#pragma once

#include "iterator/iterator.cpp"

struct edge {
    int from, to, weight;

    edge(int from, int to, int weight){
        this->from = from;
        this->to = to;
        this->weight = weight;
    }

    bool operator==(const edge &other) {
        return this->from == other.from && this->to == other.to;
    }
};

class Graph {
public:
    virtual void addEdge(int v1, int v2) = 0;
    virtual void addWeightedEdge(int v1, int v2, int weight) = 0;
    virtual void removeEdge(int v, int w) = 0;
    virtual int* entryDegree() = 0;
    virtual bool hasEdge(int v1, int v2) = 0;
    virtual edge getEdge(int v, int w) = 0;
    virtual Iterator<edge> *getAllEdges() = 0;
    virtual Iterator<edge> *getNeighbors(int v) = 0;
    virtual int **adjMatrix() = 0;
    //cant vertices
    virtual int V() = 0;
};