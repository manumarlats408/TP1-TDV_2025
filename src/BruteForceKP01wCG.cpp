#include "BruteForceKP01wCG.h"


BruteForceKP01wCG::BruteForceKP01wCG() {}

static bool TieneConflicto(const Solution& solucion, const KP01withCGInstance& instance) {
    const Grafo& grafo = instance.getGrafoConflictos();
    const std::vector<int>& items = solucion.returnearItems();

    // Recorremos todos los pares de items incluidos en la solución
    for (size_t i = 0; i < items.size(); ++i) {
        for (size_t j = i + 1; j < items.size(); ++j) {
            if (grafo.sonAdyacentes(items[i], items[j])) {
                return true;  // Existe conflicto
            }
        }
    }

    return false;  // No existe ningún conflicto
}


static Solution mejor_sol(const Solution& solucion1, const Solution& solucion2, const KP01withCGInstance& instance, int i) {
    
if(!TieneConflicto(solucion1,instance)&& !TieneConflicto(solucion2,instance)){
    if ((solucion1.getPesoTotal() <= instance.getCapacity()) && 
        (solucion2.getPesoTotal() > instance.getCapacity())) {
        return solucion1;
    }

    if ((solucion1.getPesoTotal() > instance.getCapacity()) && 
        (solucion2.getPesoTotal() <= instance.getCapacity())) {
        return solucion2;
    }

    if ((solucion1.getPesoTotal() <= instance.getCapacity()) && 
        (solucion2.getPesoTotal() <= instance.getCapacity())) {
        return (solucion1.getBeneficioTotal() > solucion2.getBeneficioTotal()) ? solucion1 : solucion2;
    }
}

if(!TieneConflicto(solucion1,instance)&& TieneConflicto(solucion2,instance)){
    return solucion1; // Devuelve una solución vacía si ninguna es válida
}

if(TieneConflicto(solucion1,instance)&& !TieneConflicto(solucion2,instance)){
    return solucion2; // Devuelve una solución vacía si ninguna es válida
}

else{
    return 0;
}

}



Solution BruteForceKP01wCG::solve(
    const KP01withCGInstance& instance,
    Solution solucion_actual,
    int i
){
    int numItems = instance.getNumItems();

    // Caso base: instancia vacía o ya recorrimos todos los items
    if (numItems == 0 || i == numItems) {
        if (solucion_actual.getPesoTotal() <= instance.getCapacity()) {
            return solucion_actual;
        }
        else {
            return 0; // Devuelve solución vacía (inválida)
        }
    }

    // Explorar SIN incluir el item actual
    Solution solucion_sin_item = solve(instance, solucion_actual, i + 1);

    // Explorar incluyendo el item actual
    Solution solucion_con_item = solucion_actual;
    solucion_con_item.addItem(i);
    solucion_con_item.sumar_peso(instance.getWeight(i));
    solucion_con_item.sumar_beneficio(instance.getProfit(i));
    solucion_con_item = solve(instance, solucion_con_item, i + 1);

    // Retorna la mejor solución entre ambas
    return mejor_sol(solucion_sin_item, solucion_con_item, instance, i);
}