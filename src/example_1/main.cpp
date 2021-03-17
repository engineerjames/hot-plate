#include <iostream>
#include <memory>
#include <string>

#include "CardinalDirection.hpp"
#include "Coordinate.hpp"
#include "MatrixWriter.hpp"
#include "Parameters.hpp"
#include "RandomWalkerSimulation.hpp"
#include "Walker.hpp"

constexpr static const int EXPECTED_ARGS = 7;

// Expect application to be called via:
// james$ ./main a b T1 T2 T3 T4
int main( int argc, const char **args )
{
    Parameters::Geometry     geometryParams {};
    Parameters::Temperatures temperatureParams {};

    if ( argc < EXPECTED_ARGS )
    {
        std::cout << "Using default parameters." << std::endl;
        geometryParams.plateWidth  = 1.5;
        geometryParams.plateHeight = 3.0;        
        temperatureParams.Tbottom = 300;
        temperatureParams.Ttop    = 200;
        temperatureParams.Tleft   = 350;
        temperatureParams.Tright  = 550;
    }
    else
    {
        geometryParams.plateWidth  = std::stod( args[1] );
        geometryParams.plateHeight = std::stod( args[2] );
        temperatureParams.Tbottom = std::stod( args[3] );
        temperatureParams.Ttop    = std::stod( args[4] );
        temperatureParams.Tleft   = std::stod( args[5] );
        temperatureParams.Tright  = std::stod( args[6] );
    }

    Parameters dp { 100, 100, 10000, geometryParams, temperatureParams };

    auto sim = std::make_unique< RandomWalkerSimulation >( dp );

    sim->initialize();
    sim->run();

    MatrixWriter< RandomWalkerSimulation::MatrixType > writer { sim->getTemperatures() };
    writer.write( "./testoutput.csv" );

    return 0;
}