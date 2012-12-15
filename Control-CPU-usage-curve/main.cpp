#include "SolutionBase.h"
#include "OfficialSolution.h"
#include "NaiveSolution.h"
#include "StraightForwardSolution.h"
#include "ParameterizedSolution.h"
#include "SineSolution.h"

int main(void)
{
    SolutionBase & solution = OfficialSolution();
    //SolutionBase & solution = NaiveSolution();
    //SolutionBase & solution = StraightForwardSolution();
    //SolutionBase & solution = ParameterizedSolution<30>();
    //SolutionBase & solution = SineSolution();
    solution.Draw();
}