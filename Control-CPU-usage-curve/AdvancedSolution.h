#pragma once

#include <Windows.h>
#include "SineSolution.h"

class AdvancedSolution : public SineSolution
{
private:
    AdvancedSolution(const AdvancedSolution &);
    AdvancedSolution & operator=(const AdvancedSolution &);
public:
    AdvancedSolution(void);
    virtual ~AdvancedSolution(void);
    virtual void Draw(void);
};