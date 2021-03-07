#ifndef HOTPLATE_WALKER_HPP
#define HOTPLATE_WALKER_HPP

#include "CardinalDirection.hpp"
#include "Coordinate.hpp"

class Walker
{
   public:
    Walker( Coordinate< double > starting_position );

    void                        move( CardinalDirection direction, double spacing_x, double spacing_y );
    const Coordinate< double >& getPosition() const;

   private:
    Coordinate< double > position;
};

#endif