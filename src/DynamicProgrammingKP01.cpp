// DynamicProgrammingKP01.cpp
#include "DynamicProgrammingKP01.h"
#include <vector>
#include <algorithm>

DynamicProgrammingKP01::DynamicProgrammingKP01() {}

int max(int a, int b) {
    return (a > b) ? a : b; //O(1)
}
//O(1)


Solution DynamicProgrammingKP01::solve(const KP01withCGInstance& instance) {
    int C = instance.getCapacity(); //O(1)
    int n = instance.getNumItems(); //O(1)

    Solution b(instance.getNumItems()); //O(n)

    std::vector<std::vector<int>> m(n+1,std::vector<int>(C+1)); //O(n*C)

    for(int i=0;i<=n;i++){ //O(n)
        m[i][0]=0; //O(1)
    }
    for(int c=0;c<=C;c++){ //O(C)
        m[0][c]=0; //O(1)
    }

    for(int k=1;k<=n;k++){ //O(n)
        for(int c=1;c<=C;c++){ //O(C)
            if(instance.getWeight(k-1)>c){ //O(1)
                m[k][c]=m[k-1][c]; //O(1)
            }else{
                m[k][c]=max(m[k-1][c],instance.getProfit(k-1)+m[k-1][c-instance.getWeight(k-1)]); //O(1)
                if(m[k][c]!=m[k-1][c]){ //O(1)
                }
            }
        }
    }

    int c = C; //O(1)
    for (int k = n; k >= 1; --k) { //O(n)
        if (m[k][c] != m[k - 1][c]) { //O(1)
            int l = k - 1;  //O(1)
            b.addItem(l); //O(1)
            b.sumar_peso(instance.getWeight(l)); //O(1)
            b.sumar_beneficio(instance.getProfit(l)); //O(1)
            c -= instance.getWeight(l); //O(1)
        }
        
    }
    

    return b; //O(1)
}

// O(1) + O(1) + O(n) + O(n*C) + O(n) + O(C) + O(n*C) + O(1) + O(n)
// O(1 + n + n*C + C)
//O(n*C)
// n siendo Número de ítems
// c siendo Capacidad total de la mochila
