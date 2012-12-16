#include <stdexcept>
#include "FixProcessorHelper.h"
#include "SolutionBase.h"
#include "OfficialSolution.h"
#include "NaiveSolution.h"
#include "StraightForwardSolution.h"
#include "ParameterizedSolution.h"
#include "SineSolution.h"
#include "AdvancedSolution.h"

int main(void)
{
    AdvancedSolution solution;
    solution.Draw();

    //SolutionBase & solution = OfficialSolution();
    ////SolutionBase & solution = NaiveSolution();
    ////SolutionBase & solution = StraightForwardSolution();
    ////SolutionBase & solution = ParameterizedSolution<30>();
    ////SolutionBase & solution = SineSolution();

    //if(!FixProcessorHelper::FixCurrentProcessToProcessorByMask(1)) {
    //    throw new std::runtime_error("Fix process affinity failed!");
    //}

    //solution.Draw();
}