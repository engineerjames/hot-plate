#ifndef HOTPLATE_RANDOM_WALKER_SIMULATION_HPP
#define HOTPLATE_RANDOM_WALKER_SIMULATION_HPP

#include <vector>

#include "Parameters.hpp"

class Walker;

// Initially, the intent is to just have this class manage the execution of
// a single strategy--we'll iterate through each discrete point in the domain
// and generate N walks at each point to establish the temperature distribution.
// In the future, we'll likely inject the specific walking strategy so that various
// computational approaches can be explored (Heavy parallelization, GPU acceleration, etc.)
class RandomWalkerSimulation
{
   public:
    RandomWalkerSimulation( const Parameters& params );

    void initialize();
    void run();

   private:
    bool   walkerIsAtEdge( const Walker& walker ) const;
    double getEdgeTemperature( const Walker& walker ) const;

    Parameters                           parameters_;
    std::vector< std::vector< double > > temperatures_;
};

#endif