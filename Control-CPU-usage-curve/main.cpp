#include <Windows.h>
#include <climits>
#define _USE_MATH_DEFINES
#include <cmath>
#include <array>

using namespace std;

int officialSineCurve(void);
int solution1(void);
int solution2(void);
int solution3(double);
int solution4(void);
void cosine(void);

int main(void)
{
    HANDLE hProcess = GetCurrentProcess();
    if(!SetProcessAffinityMask(hProcess, 1)) {
        return 1;
    }

    return solution4();
}

int solution4(void)
{
    const DWORD interval = 300;
    const int spanCount = 36;
    array<DWORD, spanCount> idleSpans, busySpans;
    double x = 0, deltaX = 2 * M_PI / spanCount;
    for(int i = 0; i < spanCount; i++, x += deltaX) {
        double y = (sin(x) + 1.0) / 2;
        idleSpans[i] = static_cast<DWORD>(interval * (1 - y) + 0.5);
        busySpans[i] = static_cast<DWORD>(interval * y + 0.5);
    }

    int counter = 0;
    while(true) {
        const DWORD &busyTime = busySpans[counter];
        
        const DWORD startTicks = GetTickCount();
        while(GetTickCount() - startTicks <= busyTime) ;

        const DWORD &idleTime = idleSpans[counter];
        Sleep(idleTime);

        counter = (counter + 1) % spanCount;
    }
    return 0;
}

int solution3(double busyPercentage)
{
    const DWORD idleTime = 100;
    const DWORD busyTime = 
        static_cast<DWORD>(idleTime / (1.0 / busyPercentage - 1.0) + 0.5);

    while(true) {
        const DWORD startTime = GetTickCount();
        while(GetTickCount() - startTime <= busyTime) ;
        Sleep(idleTime);
    }
    return 0;
}

int solution2(void)
{
    const DWORD idleTime = 100;
    const DWORD busyTime = idleTime;

    while(true) {
        const DWORD startTime = GetTickCount();
        while(GetTickCount() - startTime <= busyTime) ;
        Sleep(idleTime);
    }
    return 0;
}

int solution1(void)
{
    while(true) {
        for(int i = 0; i < INT_MAX / 2; i++);
        Sleep(100);
    }
    return 0;
}