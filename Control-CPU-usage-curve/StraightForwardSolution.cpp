#include "StraightForwardSolution.h"
#include <Windows.h>
#include <stdexcept>
#include "FixProcessorHelper.h"

StraightForwardSolution::StraightForwardSolution(void)
{
}


StraightForwardSolution::~StraightForwardSolution(void)
{
}

void StraightForwardSolution::Draw(void)
{
    while(true) {
        const DWORD START_TICKS = GetTickCount();
        while(GetTickCount() - START_TICKS <= BUSY_TIME) ;
        Sleep(IDLE_TIME);
    }
}