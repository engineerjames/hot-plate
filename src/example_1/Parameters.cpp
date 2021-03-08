#include "Parameters.hpp"

Parameters::Parameters( int xSteps, int ySteps, int numberOfWalkers, Parameters::Geometry geometry, Parameters::Temperatures temperatures )
    : N_STEPS_X( xSteps )
    , N_STEPS_Y( ySteps )
    , N_WALKERS( numberOfWalkers )
    , GEOMETRY( geometry )
    , TEMPERATURES( temperatures )
{
}

std::ostream& operator<<( std::ostream& os, const Parameters& params )
{
    os << "Number of steps (x, y): "
       << "( " << params.N_STEPS_X << ", " << params.N_STEPS_Y << " )\n";
    os << "Number of walkers per coordinate: " << params.N_WALKERS << '\n';
    os << "Geometry (width, height): "
       << "( " << params.GEOMETRY.plateWidth << ", " << params.GEOMETRY.plateHeight << " )\n";

    os << "Temperatures (bottom, top, left, right): "
       << "( " << params.TEMPERATURES.Tbottom << ", " << params.TEMPERATURES.Ttop << ", " << params.TEMPERATURES.Tleft << ", "
       << params.TEMPERATURES.Tright << " )\n";

    return os;
}