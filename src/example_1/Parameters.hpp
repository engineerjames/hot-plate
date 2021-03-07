#ifndef HOTPLATE_PARAMETERS_HPP
#define HOTPLATE_PARAMETERS_HPP

struct Parameters
{
    double plateWidth;
    double plateHeight;

    double Tbottom;
    double Ttop;
    double Tleft;
    double Tright;

    Parameters( int xSteps, int ySteps, int numberOfWalkers )
        : N_STEPS_X( xSteps )
        , N_STEPS_Y( ySteps )
        , N_WALKERS( numberOfWalkers )
    {
    }

    const int N_STEPS_X;
    const int N_STEPS_Y;
    const int N_WALKERS;
};

#endif