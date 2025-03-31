#include "Solution.h"

Solution::Solution(int numItems): peso_total(0), beneficio_total(0){
    Elem.reserve(numItems);
}

void Solution::addItem(int item) {
    Elem.push_back(item);
}

void Solution::removeItem(int item) {
    Elem.erase(std::remove(Elem.begin(), Elem.end(), item), Elem.end());
}

bool Solution::contains(int item) const {
    return std::find(Elem.begin(), Elem.end(), item) != Elem.end();
}

void Solution::printSolution() const {
    std::cout << "Elementos: ";
    for (int elem : Elem) {
        std::cout << elem << " ";
    }
    std::cout << "\nPeso total: " << peso_total << "\n";
    std::cout << "Beneficio total: " << beneficio_total << "\n";
}


void Solution::sumar_peso(int peso) {
    peso_total += peso;
}

void Solution::sumar_beneficio(int beneficio) {
    beneficio_total += beneficio;
}

int Solution::getBeneficioTotal() const {
    return beneficio_total;
}

int Solution::getPesoTotal() const {
    return peso_total;
}

