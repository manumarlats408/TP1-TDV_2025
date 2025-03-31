// KP01withCGInstance.h
#ifndef KP01WITHCGINSTANCE_H
#define KP01WITHCGINSTANCE_H

#include "Graph.h"
#include <iostream>
#include <vector>
#include <tuple>

class KP01withCGInstance {
private:
    // Definir estructura interna.
    int numItems;
    int capacidad;
    std::vector<int>items_peso;
    std::vector<int>items_beneficio;
    // Agregar el grafo de conflictos.
    int numConflictos;
    Grafo conflictos;

public:
    KP01withCGInstance(int n, int cap);
    void setWeight(int index, int weight);
    void setProfit(int index, int profit);
    int getWeight(int index) const;
    int getProfit(int index) const;
    int getNumItems() const;
    int getCapacity() const;
    void addConflict(int item1, int item2);
    void removeConflict(int item1, int item2);
    void readInstanceFromFile(const std::string& filename);
    // Agregar los metodos que consideren necesarios, en particular para obtener los conflictos.
};

#endif // KP01WITHCGINSTANCE_H