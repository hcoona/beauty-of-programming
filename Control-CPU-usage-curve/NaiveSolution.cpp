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
    while(true) {
        for(int i = 0; i < INT_MAX / 90; i++);
        Sleep(IDLE_TIME);
    }
}