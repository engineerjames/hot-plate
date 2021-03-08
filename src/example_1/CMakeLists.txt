set( target main )

set( sources
  main.cpp
  Parameters.cpp
  RandomWalkerSimulation.cpp
  Walker.cpp
)

set( headers
  CardinalDirection.hpp
  Coordinate.hpp
  Parameters.hpp
  Walker.hpp
)

add_executable(${target} ${sources} ${headers})

if (NOT MSVC)
  target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
else()
  target_compile_options(${target} PRIVATE /W4)
endif()