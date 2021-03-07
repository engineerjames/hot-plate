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

    double discretized_x = parameters_.GEOMETRY.plateWidth / parameters_.N_STEPS_X;
    double discretized_y = parameters_.GEOMETRY.plateHeight / parameters_.N_STEPS_Y;

    Coordinate< double > startingPosition {};
    startingPosition.x = 0 + discretized_x;
    startingPosition.y = 0 + discretized_y;

    Walker walker { startingPosition };

    for ( int i = 0; i < parameters_.N_STEPS_X; ++i )
    {
        for ( int j = 0; j < parameters_.N_STEPS_Y; ++j )
        {
            for ( int n = 0; n < parameters_.N_WALKERS; ++n )
            {
                int walksToEdge = 0;
                while ( ! walkerIsAtEdge( walker ) )
                {
                    CardinalDirection direction = static_cast< CardinalDirection >( uniform_distribution( generator ) );
                    walker.move( direction, discretized_x, discretized_y );
                    walksToEdge++;
                }

                std::cout << "Only needed " << walksToEdge << " to find edge." << std::endl;
                // Need to know what edge it was at...
                temperatures_[i][j] += 100;  // Temperature of the edge for each walker
                walker = Walker { startingPosition };
            }

            temperatures_[i][j] /= parameters_.N_WALKERS;
        }
    }
}

bool RandomWalkerSimulation::walkerIsAtEdge( const Walker& walker ) const
{
    const Coordinate< double >& walkerPosition = walker.getPosition();

    if ( walkerPosition.x <= 0.0 || walkerPosition.x >= parameters_.GEOMETRY.plateWidth || walkerPosition.y <= 0.0 ||
         walkerPosition.y >= parameters_.GEOMETRY.plateHeight )
    {
        return true;
    }

    return false;
}

RandomWalkerSimulation::RandomWalkerSimulation( const Parameters& params )
    : parameters_( params )
    , temperatures_( params.N_STEPS_X )
{
    for ( int i = 0; i < parameters_.N_STEPS_X; ++i )
    {
        temperatures_[i].resize( parameters_.N_STEPS_Y );
    }
}