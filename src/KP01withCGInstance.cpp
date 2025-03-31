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
    // if (!file) {
    //     std::cerr << "Error: No se pudo abrir el archivo " << filename << "\n";
    //     return;
    // }

    // std::cout << "Archivo abierto correctamente: " << filename << std::endl;

    // Leer número de ítems y capacidad
    file >> numItems >> capacidad;
    // std::cout << "Número de ítems: " << numItems << ", Capacidad: " << capacidad << std::endl;

    // Leer pesos
    items_peso.resize(numItems);
    for (int i = 0; i < numItems; i++) {
        file >> items_peso[i];
    }
    std::cout << "Pesos: ";
    for (int w : items_peso) std::cout << w << " ";
    std::cout << std::endl;

    // Leer beneficios
    items_beneficio.resize(numItems);
    for (int i = 0; i < numItems; i++) {
        file >> items_beneficio[i];
    }
    std::cout << "Beneficios: ";
    for (int b : items_beneficio) std::cout << b << " ";
    std::cout << std::endl;

    // Leer cantidad de conflictos
    file >> numConflictos;
    // std::cout << "Número de conflictos: " << numConflictos << std::endl;

    // Leer pares de conflictos
    for (int i = 0; i < numConflictos; i++) {
        int u, v;
        file >> u >> v;
        // std::cout << "Conflicto: " << u << " - " << v << std::endl;
    }

    file.close();
}


//SACAR TODOS LOS COUT!!!!!