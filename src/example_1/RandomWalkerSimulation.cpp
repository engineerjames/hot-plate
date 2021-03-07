#include "RandomWalkerSimulation.hpp"

#include <iostream>
#include <random>

#include "CardinalDirection.hpp"
#include "Walker.hpp"

void RandomWalkerSimulation::initialize()
{
    std::cout << "Initializing simulation with the following parameters:" << std::endl;
    std::cout << parameters_ << std::endl;

    for ( auto& column : temperatures_ )
    {
        for ( auto& val : column )
        {
            val = 0.0;
        }
    }
}

void RandomWalkerSimulation::run()
{
    std::random_device randomDevice {};
    std::mt19937       generator( randomDevice() );

    // Closed interval, each number will represent movement in a cardinal
    // direction 0 - NORTH 1 - EAST 2 - SOUTH 3 - WEST
    std::uniform_int_distribution<> uniform_distribution { 0, 3 };

    for ( int i = 0; i < parameters_.N_WALKERS; ++i )
    {
        CardinalDirection direction = static_cast< CardinalDirection >( uniform_distribution( generator ) );
        Walker            w { Coordinate< double >() };
        w.Move( direction, 0.1, 0.1 );
    }
}

RandomWalkerSimulation::RandomWalkerSimulation( const Parameters& params )
    : parameters_( params )
{ }