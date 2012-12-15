#include "NaiveSolution.h"
#include <Windows.h>
#include <stdexcept>
#include <climits>
#include "FixProcessorHelper.h"

NaiveSolution::NaiveSolution(void)
{
}

NaiveSolution::~NaiveSolution(void)
{
}

void NaiveSolution::Draw(void)
{
    if(!FixProcessorHelper::FixCurrentProcessToProcessorByMask(1)) {
        throw new std::runtime_error("Fix process affinity failed!");
    }

    while(true) {
        for(int i = 0; i < INT_MAX / 90; i++);
        Sleep(IDLE_TIME);
    }
}