#pragma once

#include <Windows.h>

class FixProcessorHelper final
{
private:
    FixProcessorHelper(void);
    ~FixProcessorHelper(void);
public:
    static BOOL FixProcessToProcessorByMask(HANDLE hProcess, DWORD_PTR dwProcessAffinityMask) {
        return SetProcessAffinityMask(hProcess, dwProcessAffinityMask);
    }
    static BOOL FixCurrentProcessToProcessorByMask(DWORD_PTR dwProcessAffinityMask) {
        HANDLE hProcess = GetCurrentProcess();
        return FixProcessToProcessorByMask(hProcess, dwProcessAffinityMask);
    }
    static BOOL FixThreadToProcessorByMask(HANDLE hThread, DWORD_PTR dwThreadAffinityMask) {
        return SetThreadAffinityMask(hThread, dwThreadAffinityMask);
    }
    static BOOL FixCurrentThreadToProcessorByMask(DWORD_PTR dwThreadAffinityMask) {
        HANDLE hThread = GetCurrentThread();
        return FixThreadToProcessorByMask(hThread, dwThreadAffinityMask);
    }
};