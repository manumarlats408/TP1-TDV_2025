// DynamicProgrammingKP01.h
#ifndef DYNAMICPROGRAMMINGKP01_H
#define DYNAMICPROGRAMMINGKP01_H

#include "Solution.h"
#include "KP01withCGInstance.h"

class DynamicProgrammingKP01 {
public:
    DynamicProgrammingKP01();
    Solution solve(const KP01withCGInstance& instance);
};

#endif // DYNAMICPROGRAMMINGKP01_H