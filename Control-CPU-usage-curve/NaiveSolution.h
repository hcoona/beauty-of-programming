#pragma once

#include "solutionbase.h"
#include <Windows.h>

class NaiveSolution :
    public SolutionBase
{
private:
    NaiveSolution(const NaiveSolution &);
    NaiveSolution & operator=(const NaiveSolution &);
protected:
    static const DWORD IDLE_TIME = 100;
public:
    NaiveSolution(void);
    virtual ~NaiveSolution(void);
    virtual void Draw(void);
};