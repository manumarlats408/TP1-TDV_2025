// DynamicProgrammingKP01.cpp
#include "DynamicProgrammingKP01.h"
#include <vector>
#include <algorithm>

DynamicProgrammingKP01::DynamicProgrammingKP01() {}

int max(int a, int b) {
    return (a > b) ? a : b;
}


Solution DynamicProgrammingKP01::solve(const KP01withCGInstance& instance) {
    int C = instance.getCapacity(); //O(1)
    int n = instance.getNumItems(); //O(1)

    Solution b(instance.getNumItems()); //O(n)

    std::vector<std::vector<int>> m(n+1,std::vector<int>(C+1)); //O(n*C)

    for(int i=0;i<=n;i++){
        m[i][0]=0;
    }
    for(int c=0;c<=C;c++){
        m[0][c]=0;
    }

    for(int k=1;k<=n;k++){
        for(int c=1;c<=C;c++){
            if(instance.getWeight(k-1)>c){
                m[k][c]=m[k-1][c];
            }else{
                m[k][c]=max(m[k-1][c],instance.getProfit(k-1)+m[k-1][c-instance.getWeight(k-1)]);
                if(m[k][c]!=m[k-1][c]){
                }
            }
        }
    }

    int c = C;
    for (int k = n; k >= 1; --k) {
        if (m[k][c] != m[k - 1][c]) {
            int idx = k - 1;  // índice real del ítem
            b.addItem(idx);
            b.sumar_peso(instance.getWeight(idx));
            b.sumar_beneficio(instance.getProfit(idx));
            c -= instance.getWeight(idx);
        }
        // Si no se incluye, no hacemos nada
    }
    

    return b;
}
