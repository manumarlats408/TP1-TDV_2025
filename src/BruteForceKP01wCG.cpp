#include "BruteForceKP01wCG.h"


BruteForceKP01wCG::BruteForceKP01wCG() {}


Solution BruteForceKP01wCG::solve(const KP01withCGInstance& instance, Solution mejor_solucion, Solution solucion_actual , index = pow(2,instance.getNumItems())) {
    Solution bestSolution(instance.getNumItems());
    

    int numItems = instance.getNumItems();
    int numCombinations = pow(2, numItems); // Hay 2^numItems combinaciones posibles

    //CASO BASE
    if(index == 1){
        if (solucion_actual.getPesoTotal() <= instance.getCapacity()) {
            // Si la solución es válida (peso no excede capacidad), evaluamos su valor
            if (solucion_actual.getBeneficioTotal() > mejor_solucion.getBeneficioTotal()) {
                
                bestSolution = solucion_actual;  // Si la nueva solución es mejor, la actualizamos
            }
        }
    }

    else{
        BruteForceKP01wCG(instance,Lista_de_soluciones,index-1);
        
    }


       
}
