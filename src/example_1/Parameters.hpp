#ifndef HOTPLATE_PARAMETERS_HPP
#define HOTPLATE_PARAMETERS_HPP

#include <iostream>

struct Parameters
{
    struct Geometry
    {
        double plateWidth;
        double plateHeight;
    };

    struct Temperatures
    {
        double Tbottom;
        double Ttop;
        double Tleft;
        double Tright;
    };

    Parameters( int xSteps, int ySteps, int numberOfWalkers, Parameters::Geometry geometry, Parameters::Temperatures temperatures );

    const int                      N_STEPS_X;
    const int                      N_STEPS_Y;
    const int                      N_WALKERS;
    const Parameters::Geometry     GEOMETRY;
    const Parameters::Temperatures TEMPERATURES;
};

std::ostream& operator<< (std::ostream& os, const Parameters& params);

#endif