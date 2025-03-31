// BruteForceKP01wCG.h
#ifndef BRUTEFORCEKP01WCG_H
#define BRUTEFORCEKP01WCG_H

#include "Solution.h"
#include "KP01withCGInstance.h"

class BruteForceKP01wCG {
private:

public:
    BruteForceKP01wCG();
    Solution solve(const KP01withCGInstance& instance, Solution solucion_actual, int i );
};

#endif // BRUTEFORCEKP01WCG_H