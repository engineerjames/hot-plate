#ifndef HOTPLATE_WALKER_HPP
#define HOTPLATE_WALKER_HPP

#include "CardinalDirection.hpp"
#include "Coordinate.hpp"

class Walker
{
   public:
    Walker( Coordinate< double > starting_position );

    void Move( CardinalDirection direction, double spacing_x, double spacing_y );

   private:
    Coordinate< double > position;
};

#endif