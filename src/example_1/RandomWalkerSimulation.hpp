#ifndef HOTPLATE_RANDOM_WALKER_SIMULATION_HPP
#define HOTPLATE_RANDOM_WALKER_SIMULATION_HPP

#include "Parameters.hpp"

// Initially, the intent is to just have this class manage the execution of
// a single strategy--we'll iterate through each discrete point in the domain
// and generate N walks at each point to establish the temperature distribution.
// In the future, we'll likely inject the specific walking strategy so that various
// computational approaches can be explored (Heavy parallelization, GPU acceleration, etc.)
class RandomWalkerSimulation
{
  public:
    RandomWalkerSimulation(const Parameters& params);

    void run();

  private:
    Parameters parameters_;
};

#endif