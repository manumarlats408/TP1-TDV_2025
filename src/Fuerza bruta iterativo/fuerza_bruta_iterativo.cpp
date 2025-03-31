#include "BruteForceKP01wCG.h"
#include <iostream>  // Necesario para los prints

BruteForceKP01wCG::BruteForceKP01wCG() {}


Solution BruteForceKP01wCG::solve(const KP01withCGInstance& instance) {
    Solution bestSolution(instance.getNumItems());
    

    int numItems = instance.getNumItems();
    int numCombinations = pow(2, numItems); // Hay 2^numItems combinaciones posibles

    
    for (int i = 0; i < numCombinations; ++i) {
        // Crear una nueva solución vacía para la combinación actual
        Solution currentSolution(0);  // Pasar 0 porque no sabemos cuántos ítems se van a agregar

        // Reiniciar los valores de peso y beneficio en cada iteración
        int pesoTotal = 0;
        int beneficioTotal = 0;


        // Generar una combinación de elementos (usando bits)
        for (int j = 0; j < numItems; ++j) {
            if ((i >> j) & 1) { // Si el j-ésimo bit está a 1, tomamos el ítem j
                currentSolution.addItem(j);  // Agregar el ítem
                // Sumar peso y beneficio del item al total
                int peso = instance.getWeight(j);
                int beneficio = instance.getProfit(j);
                pesoTotal += peso; // Sumar peso del ítem
                beneficioTotal += beneficio; // Sumar beneficio del ítem
            }
        }

        // Establecer los valores de peso y beneficio total en la solución
        currentSolution.sumar_peso(pesoTotal);
        currentSolution.sumar_beneficio(beneficioTotal);
        
        if (currentSolution.getPesoTotal() <= instance.getCapacity()) {
            // Si la solución es válida (peso no excede capacidad), evaluamos su valor
            if (currentSolution.getBeneficioTotal() > bestSolution.getBeneficioTotal()) {
                
                bestSolution = currentSolution;  // Si la nueva solución es mejor, la actualizamos
            }
        }
    }

    return bestSolution;
}
