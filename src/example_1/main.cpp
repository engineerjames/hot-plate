#include <iostream>
#include <random>
#include <string>

enum class CardinalDirection { NORTH, EAST, SOUTH, WEST };

template <typename T> struct Coordinate {
  T x;
  T y;
};

struct DirichletParameters {
  double plateWidth;
  double plateHeight;

  double Tbottom;
  double Ttop;
  double Tleft;
  double Tright;

  const int N_STEPS_X = 100;
  const int N_STEPS_Y = 100;
};

class Walker {
public:
  Walker(Coordinate<double> starting_position) : position(starting_position) {}

  void Move(CardinalDirection direction, double spacing_x, double spacing_y) {
    switch (direction) {
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

private:
  Coordinate<double> position;
};

constexpr static const int EXPECTED_ARGS = 7;
constexpr static const int N_WALKS = 500;

// Expect application to be called via:
// james$ ./main a b T1 T2 T3 T4
int main(int argc, const char **args) {

  if (argc < EXPECTED_ARGS) {
    std::cout << "Unexpected number of arguments!" << std::endl;
    return 255;
  }

  DirichletParameters dp{};

  // Just hard-code for now
  dp.plateWidth = std::stod(args[1]);
  dp.plateHeight = std::stod(args[2]);
  dp.Tbottom = std::stod(args[3]);
  dp.Ttop = std::stod(args[4]);
  dp.Tleft = std::stod(args[5]);
  dp.Tright = std::stod(args[6]);

  std::random_device randomDevice{};
  std::mt19937 generator(randomDevice());

  // Closed interval, each number will represent movement in a cardinal
  // direction 0 - NORTH 1 - EAST 2 - SOUTH 3 - WEST
  std::uniform_int_distribution<> uniform_distribution{0, 3};

  for (int i = 0; i < N_WALKS; ++i) {
    std::cout << uniform_distribution(generator) << std::endl;
    CardinalDirection direction =
        static_cast<CardinalDirection>(uniform_distribution(generator));
    Walker w{Coordinate<double>()};
    w.Move(direction, 0.1, 0.1);
  }

  return 0;
}