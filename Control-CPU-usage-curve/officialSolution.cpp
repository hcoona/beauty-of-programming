#include <Windows.h>
#define _USE_MATH_DEFINES
#include <cmath>

static const double SPLIT = 0.01;
static const int COUNT = 200;
static const int INTERVAL = 300;

int officialSineCurve(void)
{
    DWORD busySpan[COUNT];
    DWORD idleSpan[COUNT];
    const int HALF = INTERVAL / 2;
    double radian = 0.0;
    for(int i = 0; i < COUNT; i++) {
        busySpan[i] = (DWORD)(HALF + (sin(M_PI * radian) * HALF));
        idleSpan[i] = INTERVAL - busySpan[i];
        radian += SPLIT;
    }

    DWORD startTime = 0;
    int j = 0;
    while(true) {
        j = j % COUNT;
        startTime = GetTickCount();
        while((GetTickCount() - startTime) <= busySpan[j]) ;
        Sleep(idleSpan[j]);
        j++;
    }
    return 0;
}