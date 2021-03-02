#include <iostream>

struct DirichletParameters {
  double plateWidth;
  double plateHeight;

  double Tbottom;
  double Ttop;
  double Tleft;
  double Tright;
};

constexpr static const int EXPECTED_ARGS = 7;

// Expect application to be called via:
// james$ ./main a b T1 T2 T3 T4
int main(int argc, const char **args) {

  if (argc < EXPECTED_ARGS) {
    std::cout << "Unexpected number of arguments!" << std::endl;
    return 255;
  }

  DirichletParameters dp{};

  // Just hard-code for now
  dp.plateWidth  = std::stod(args[1]);
  dp.plateHeight = std::stod(args[2]);
  dp.Tbottom     = std::stod(args[3]);
  dp.Ttop        = std::stod(args[4]);
  dp.Tleft       = std::stod(args[5]);
  dp.Tright      = std::stod(args[6]);

  return 0;
}