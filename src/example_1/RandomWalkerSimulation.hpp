#ifndef HOTPLATE_RANDOM_WALKER_SIMULATION_HPP
#define HOTPLATE_RANDOM_WALKER_SIMULATION_HPP

#include "Parameters.hpp"

class RandomWalkerSimulation
{
  public:
    RandomWalkerSimulation(const Parameters& params);

    void run();

  private:
    Parameters parameters_;
};

#endif