#ifndef ASSERTION_HPP
#define ASSERTION_HPP

// #define ASSERT(cond)

#include <functional>

class Assertion
{
   public:
    Assertion();

   private:
    std::function< bool() > condition_;
};

#endif