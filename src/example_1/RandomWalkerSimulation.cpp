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

    // We don't need to start at any edge, since the temperature at each
    // edge is established by the boundary conditions.
    for ( int i = 1; i < parameters_.N_STEPS_X - 1; ++i )
    {
        for ( int j = 1; j < parameters_.N_STEPS_Y - 1; ++j )
        {
            Coordinate< double > startingPosition {};
            startingPosition.x = i * discretized_x;
            startingPosition.y = j * discretized_y;

            Walker walker { startingPosition };

            for ( int n = 0; n < parameters_.N_WALKERS; ++n )
            {
                int walksToEdge = 0;
                while ( ! walkerIsAtEdge( walker ) )
                {
                    CardinalDirection direction = static_cast< CardinalDirection >( uniform_distribution( generator ) );
                    walker.move( direction, discretized_x, discretized_y );
                    walksToEdge++;
                }

                temperatures_[i][j] += getEdgeTemperature( walker );
            }
        }
    }

    for ( auto& column : temperatures_ )
    {
        for ( auto& val : column )
        {
            val /= parameters_.N_WALKERS;
        }
    }
}

double RandomWalkerSimulation::getEdgeTemperature( const Walker& walker ) const
{
    const Coordinate< double >& walkerPosition = walker.getPosition();

    // One temperature will end up getting favored at the corners (since the walker will be present
    // on two edges simultaneously)
    if ( walkerPosition.x <= 0.0 )
    {
        return parameters_.TEMPERATURES.Tleft;
    }
    else if ( walkerPosition.x >= parameters_.GEOMETRY.plateWidth )
    {
        return parameters_.TEMPERATURES.Tright;
    }
    else if ( walkerPosition.y <= 0.0 )
    {
        return parameters_.TEMPERATURES.Tbottom;
    }
    else if ( walkerPosition.y >= parameters_.GEOMETRY.plateHeight )
    {
        return parameters_.TEMPERATURES.Ttop;
    }
    else
    {
        std::cerr << "Walker should not have made it here: " << walker.getPosition().x << ", " << walker.getPosition().y << std::endl;
        return 0.0;
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