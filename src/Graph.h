#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <iostream>
#include <tuple>


class Grafo {
private:
    int numNodos;
    std::vector<std::vector<int> > adjList; 

public:
    Grafo() : numNodos(0) {}

    Grafo(int numConflictos, const std::vector<std::tuple<int, int>>& conflictos);

    void agregarArista(int u, int v);

    bool sonAdyacentes(int u, int v) const;

    void addConflict(int item1, int item2);

    void removeConflict(int item1, int item2);
};

#endif // GRAFO_H
