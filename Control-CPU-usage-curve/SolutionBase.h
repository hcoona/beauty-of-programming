#pragma once

class SolutionBase
{
private:
    SolutionBase(const SolutionBase &);
    SolutionBase & operator=(const SolutionBase &);
public:
    SolutionBase(void);
    virtual ~SolutionBase(void);
    virtual void Draw(void) = 0;
};