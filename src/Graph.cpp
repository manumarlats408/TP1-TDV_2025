#include "Graph.h"



Grafo::Grafo(int numConflictos, const std::vector<std::tuple<int, int>>& conflictos) {
    numNodos = 0;
    
    for (const auto& [u, v] : conflictos) {
        numNodos = std::max({numNodos, u, v});
    }
    numNodos++; 

    adjList.resize(numNodos);

    for (const auto& [u, v] : conflictos) {
        agregarArista(u, v);
    }
}

void Grafo:: agregarArista(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

bool Grafo:: sonAdyacentes(int u, int v) const {
    for (int vecino : adjList[u]) {
        if (vecino == v) return true;
    }
    return false;
}

void Grafo::addConflict(int item1, int item2) {
    if (!sonAdyacentes(item1, item2)) {
        agregarArista(item1, item2);
    }
}


void Grafo::removeConflict(int item1, int item2) {
    auto& adjacents1 = adjList[item1];
    auto& adjacents2 = adjList[item2];

    adjacents1.erase(std::remove(adjacents1.begin(), adjacents1.end(), item2), adjacents1.end());
    adjacents2.erase(std::remove(adjacents2.begin(), adjacents2.end(), item1), adjacents2.end());
}


