// BacktrackingKP01.h
#ifndef BACKTRACKINGKP01WCG_H
#define BACKTRACKINGKP01WCG_H

#include "Solution.h"
#include "KP01withCGInstance.h"

class BacktrackingKP01wCG {
private:

public:
    BacktrackingKP01wCG();
    Solution solve(const KP01withCGInstance& instance);
};

#endif // BACKTRACKINGKP01_H