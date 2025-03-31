#include "KP01withCGInstance.h"
#include <fstream>
#include <iostream>

KP01withCGInstance::KP01withCGInstance(int n, int cap) {}

void KP01withCGInstance::setWeight(int index, int weight) {
   items_peso[index] = weight;
}

void KP01withCGInstance::setProfit(int index, int profit) {
    items_beneficio[index] = profit;
}

int KP01withCGInstance::getWeight(int index) const {
    return items_peso[index];
}

int KP01withCGInstance::getProfit(int index) const {
    return items_beneficio[index];
}

int KP01withCGInstance::getNumItems() const {
    return numItems;
}

int KP01withCGInstance::getCapacity() const {
    return capacidad;
}

void KP01withCGInstance::addConflict(int item1, int item2) {
    conflictos.addConflict(item1, item2);
}

void KP01withCGInstance::removeConflict(int item1, int item2) {
    conflictos.removeConflict(item1, item2);
}

void KP01withCGInstance::readInstanceFromFile(const std::string& filename) {
    std::ifstream file(filename);
    file >> numItems >> capacidad;

    items_peso.resize(numItems);
    items_beneficio.resize(numItems);

    for (int i = 0; i < numItems; i++) {
        file >> items_peso[i];
    }

    for (int i = 0; i < numItems; i++) {
        file >> items_beneficio[i];
    }

    file >> numConflictos;

    std::vector<std::tuple<int, int>> conflictos_lista;
    for (int i = 0; i < numConflictos; i++) {
        int u, v;
        file >> u >> v;
        conflictos_lista.emplace_back(u, v);
    }

    conflictos = Grafo(numConflictos, conflictos_lista);

    file.close();
}

int KP01withCGInstance::getNumConflictos() const{
    return numConflictos;
}

Grafo KP01withCGInstance::getGrafoConflictos() const{
    return conflictos;
}

//SACAR TODOS LOS COUT!!!!!