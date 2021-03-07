#include <iostream>
#include <memory>

#include "CardinalDirection.hpp"
#include "Coordinate.hpp"
#include "Parameters.hpp"
#include "RandomWalkerSimulation.hpp"
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

    Parameters::Geometry     geometryParams {};
    Parameters::Temperatures temperatureParams {};

    geometryParams.plateWidth  = std::stod( args[1] );
    geometryParams.plateHeight = std::stod( args[2] );

    temperatureParams.Tbottom = std::stod( args[3] );
    temperatureParams.Ttop    = std::stod( args[4] );
    temperatureParams.Tleft   = std::stod( args[5] );
    temperatureParams.Tright  = std::stod( args[6] );

    Parameters dp { 100, 100, 500, geometryParams, temperatureParams };

    auto sim = std::make_unique< RandomWalkerSimulation >( dp );

    sim->initialize();
    sim->run();

    return 0;
}