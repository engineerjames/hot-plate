#include <iostream>
#include <random>
#include <string>

#include "CardinalDirection.hpp"
#include "Coordinate.hpp"
#include "Parameters.hpp"
#include "Walker.hpp"

constexpr static const int EXPECTED_ARGS = 7;

// Expect application to be called via:
// james$ ./main a b T1 T2 T3 T4
int main( int argc, const char **args )
{
    if ( argc < EXPECTED_ARGS )
    {
        std::cout << "Unexpected number of arguments!" << std::endl;
        return 255;
    }

    Parameters dp { 100, 100, 500 };

    // Just hard-code for now
    dp.plateWidth  = std::stod( args[1] );
    dp.plateHeight = std::stod( args[2] );
    dp.Tbottom     = std::stod( args[3] );
    dp.Ttop        = std::stod( args[4] );
    dp.Tleft       = std::stod( args[5] );
    dp.Tright      = std::stod( args[6] );

    std::random_device randomDevice {};
    std::mt19937       generator( randomDevice() );

    // Closed interval, each number will represent movement in a cardinal
    // direction 0 - NORTH 1 - EAST 2 - SOUTH 3 - WEST
    std::uniform_int_distribution<> uniform_distribution { 0, 3 };

    for ( int i = 0; i < dp.N_WALKERS; ++i )
    {
        std::cout << uniform_distribution( generator ) << std::endl;
        CardinalDirection direction = static_cast< CardinalDirection >( uniform_distribution( generator ) );
        Walker            w { Coordinate< double >() };
        w.Move( direction, 0.1, 0.1 );
    }

    return 0;
}