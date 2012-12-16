#include "AdvancedSolution.h"
#include <Windows.h>
#include "FixProcessorHelper.h"

static int spanCount;
static DWORD *pIdleSpans;
static DWORD *pBusySpans;

AdvancedSolution::AdvancedSolution(void)
{
    spanCount = SineSolution::SPAN_COUNT;
    pIdleSpans = new DWORD[spanCount];
    pBusySpans = new DWORD[spanCount];

    for(int i = 0; i < spanCount / 2; i++) {
        pIdleSpans[i] = pBusySpans[i] = SineSolution::INTERVAL / 2;
    }
    for(int i = spanCount / 2; i < spanCount; i++) {
        pIdleSpans[i] = SineSolution::INTERVAL;
        pBusySpans[i] = 0;
    }
}

AdvancedSolution::~AdvancedSolution(void)
{
    delete[] pIdleSpans;
    delete[] pBusySpans;
}

static DWORD WINAPI DrawLeft(LPVOID lpParam) {
    if(!FixProcessorHelper::FixCurrentThreadToProcessorByMask(1)) {
        return 1;
    }
    
    SineSolution sine;
    sine.Draw();
    
    return 0;
}

DWORD WINAPI DrawRight(LPVOID lpParam) {
    if(!FixProcessorHelper::FixCurrentThreadToProcessorByMask(2)) {
        return 1;
    }
    
    int counter = 0;
    while(true) {
        const DWORD & BUSY_TIME = pBusySpans[counter];
        
        const DWORD START_TICKS = GetTickCount();
        while(GetTickCount() - START_TICKS <= BUSY_TIME) ;

        const DWORD & IDLE_TIME = pIdleSpans[counter];
        Sleep(IDLE_TIME);

        counter = (counter + 1) % spanCount;
    }
    
    return 0;
}

void AdvancedSolution::Draw(void)
{
    HANDLE threads[] = {
        CreateThread(NULL, 0, DrawLeft, 0, 0, 0),
        CreateThread(NULL, 0, DrawRight, 0, 0, 0)
    };
    WaitForMultipleObjects(2, threads, TRUE, INFINITE);
}