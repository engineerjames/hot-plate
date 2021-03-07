#include "Walker.hpp"

Walker::Walker( Coordinate< double > starting_position )
    : position( starting_position )
{
}

void Walker::Move( CardinalDirection direction, double spacing_x, double spacing_y )
{
    switch ( direction )
    {
        case CardinalDirection::NORTH:
            position.y += spacing_y;
            break;
        case CardinalDirection::EAST:
            position.x += spacing_x;
            break;
        case CardinalDirection::SOUTH:
            position.y -= spacing_y;
            break;
        case CardinalDirection::WEST:
            position.x -= spacing_x;
            break;

        default:
            break;
    }
}
