set( target assertion )
add_library( ${target} assertion.hpp assertion.cpp )
target_include_directories( ${target} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} )