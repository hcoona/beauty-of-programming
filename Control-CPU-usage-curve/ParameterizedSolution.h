#pragma once

#include "solutionbase.h"
#include <Windows.h>
#include "FixProcessorHelper.h"

template<int BUSY_PERCENTAGE>
class ParameterizedSolution :
    public SolutionBase
{
private:
    ParameterizedSolution(const ParameterizedSolution &);
    ParameterizedSolution & operator=(const ParameterizedSolution &);
protected:
    static const DWORD IDLE_TIME = 100;
    static const DWORD BUSY_TIME = static_cast<DWORD>(IDLE_TIME
        / (100.0 / BUSY_PERCENTAGE - 1.0)
        + 0.5);
public:
    ParameterizedSolution(void) { }
    virtual ~ParameterizedSolution(void) { }
    virtual void Draw(void) {
        while(true) {
            const DWORD START_TICKS = GetTickCount();
            while(GetTickCount() - START_TICKS <= BUSY_TIME) ;
            Sleep(IDLE_TIME);
        }
    }
};

