#pragma once

#include "solutionbase.h"
#include <Windows.h>

class StraightForwardSolution :
    public SolutionBase
{
private:
    StraightForwardSolution(const StraightForwardSolution &);
    StraightForwardSolution & operator=(const StraightForwardSolution &);
protected:    
    static const DWORD IDLE_TIME = 100;
    static const DWORD BUSY_TIME = IDLE_TIME;
public:
    StraightForwardSolution(void);
    virtual ~StraightForwardSolution(void);
    virtual void Draw(void);
};