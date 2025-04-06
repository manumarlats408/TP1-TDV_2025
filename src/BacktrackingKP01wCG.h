// BacktrackingKP01.h
#ifndef BACKTRACKINGKP01WCG_H
#define BACKTRACKINGKP01WCG_H

#include "Solution.h"
#include "KP01withCGInstance.h"

class BacktrackingKP01wCG {
private:

public:
    BacktrackingKP01wCG();
    Solution solve(const KP01withCGInstance& instance, Solution solucion_actual, int i);
};

#endif // BACKTRACKINGKP01_H