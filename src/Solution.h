#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <iostream>



class Solution {
private:
std::vector<int> Elem;
int peso_total;
int beneficio_total;


public:
    Solution(int numItems);// Constructor to initialize size
    void addItem(int item);
    void removeItem(int item);
    bool contains(int item) const;
    void printSolution() const;
    void sumar_peso(int peso); 
    void sumar_beneficio(int beneficio);
    int getPesoTotal() const;
    int getBeneficioTotal() const;
    
};

#endif // SOLUTION_H

