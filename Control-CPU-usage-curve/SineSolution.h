#pragma once

#include "solutionbase.h"
#include <Windows.h>

class SineSolution :
    public SolutionBase
{
private:
    SineSolution(const SineSolution &);
    SineSolution & operator=(const SineSolution &);
protected:
    static const DWORD INTERVAL = 300;
    static const int SPAN_COUNT = 36 * 2;
    DWORD idleSpans[SPAN_COUNT];
    DWORD busySpans[SPAN_COUNT];
public:
    SineSolution(void);
    virtual ~SineSolution(void);
    virtual void Draw(void);
};

