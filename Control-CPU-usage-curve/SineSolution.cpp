#include "SineSolution.h"

#define _USE_MATH_DEFINES
#include <Windows.h>
#include <stdexcept>
#include <cmath>
#include "FixProcessorHelper.h"

SineSolution::SineSolution(void)
{
    double x = 0, deltaX = 2 * M_PI / SPAN_COUNT;
    for(int i = 0; i < SPAN_COUNT; i++, x += deltaX) {
        double y = (sin(x) + 1.0) / 2;
        idleSpans[i] = static_cast<DWORD>(INTERVAL * (1 - y) + 0.5);
        busySpans[i] = static_cast<DWORD>(INTERVAL * y + 0.5);
    }
}

SineSolution::~SineSolution(void)
{
}

void SineSolution::Draw(void)
{
    int counter = 0;
    while(true) {
        const DWORD & BUSY_TIME = busySpans[counter];
        
        const DWORD START_TICKS = GetTickCount();
        while(GetTickCount() - START_TICKS <= BUSY_TIME) ;

        const DWORD & IDLE_TIME = idleSpans[counter];
        Sleep(IDLE_TIME);

        counter = (counter + 1) % SPAN_COUNT;
    }
}