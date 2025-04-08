#include "BruteForceKP01wCG.h"


BruteForceKP01wCG::BruteForceKP01wCG() {}

static bool TieneConflicto(const Solution& solucion, const KP01withCGInstance& instance) {
    const Grafo& grafo = instance.getGrafoConflictos(); //O(1)
    const std::vector<int>& items = solucion.returnearItems(); //O(1)

    for (size_t i = 0; i < items.size(); ++i) { //O(n)
        for (size_t j = i + 1; j < items.size(); ++j) { //O(n)
            if (grafo.sonAdyacentes(items[i], items[j])) { //O(1)
                return true; //O(1)
            }
        }
    }
    return false;//O(1)
}

//O(1)+ O(n) * O(n) + O(1)
//O(n²)


static Solution mejor_sol(const Solution& solucion1, const Solution& solucion2, const KP01withCGInstance& instance, int i) {
    
if(!TieneConflicto(solucion1,instance)&& !TieneConflicto(solucion2,instance)){ //O(n² + n²)
    if ((solucion1.getPesoTotal() <= instance.getCapacity()) && //O(1)
        (solucion2.getPesoTotal() > instance.getCapacity())) { //O(1)
        return solucion1; //O(1)
    }

    if ((solucion1.getPesoTotal() > instance.getCapacity()) && //O(1)
        (solucion2.getPesoTotal() <= instance.getCapacity())) { //O(1)
        return solucion2; //O(1)
    }

    if ((solucion1.getPesoTotal() <= instance.getCapacity()) && //O(1)
        (solucion2.getPesoTotal() <= instance.getCapacity())) { //O(1)
        return (solucion1.getBeneficioTotal() > solucion2.getBeneficioTotal()) ? solucion1 : solucion2; //O(1)
    }
}

if(!TieneConflicto(solucion1,instance)&& TieneConflicto(solucion2,instance)){ //O(n² + n²)
    return solucion1; //O(1)
}

if(TieneConflicto(solucion1,instance)&& !TieneConflicto(solucion2,instance)){ //O(n² + n²)
    return solucion2; //O(1)
}

else{
    return 0; //O(1)
}

}

//O(n² + n²) + O(n² + n²) + O(n)
    //O(n²)



Solution BruteForceKP01wCG::solve(const KP01withCGInstance& instance, Solution solucion_actual, int i){
    
    int numItems = instance.getNumItems(); //O(1)

    // Caso base: instancia vacía o ya recorrimos todos los items
    if (numItems == 0 || i == numItems) { //O(1)
        if (solucion_actual.getPesoTotal() <= instance.getCapacity()) { //O(1)
            return solucion_actual; //O(1)
        }
        else {
            return 0; //O(1)
        }
    }

    // Explorar SIN incluir el item actual
    Solution solucion_sin_item = solve(instance, solucion_actual, i + 1); // llamada recursiva. O(2^n), n siendo numero de items

    // Explorar incluyendo el item actual
    Solution solucion_con_item = solucion_actual; //O(n)
    solucion_con_item.addItem(i); // O(1)
    solucion_con_item.sumar_peso(instance.getWeight(i)); // O(1)
    solucion_con_item.sumar_beneficio(instance.getProfit(i)); // O(1)
    solucion_con_item = solve(instance, solucion_con_item, i + 1); // llamada recursiva.  O(2^n), n siendo numero de items

    // Retorna la mejor solución entre ambas
    return mejor_sol(solucion_sin_item, solucion_con_item, instance, i); // O(n²)
}

//O(1) + O(1) + O(1) + O(1) + O(1) + O(n) + O(1) + O(1) + O(1) + O(1) + O(2ⁿ) + O(2ⁿ) * O(n²)
// O(1 + n) + O(2ⁿ) * O(n²)
// O(n) + O(2ⁿ) * O(n²)
//O(2ⁿ * n²).

//complejidad en fuerza bruta:
// cant de ramas/iteraciones 2^ramas + operaciones en hijos