#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "coord.hpp"

TEST_CASE("Coord test")
{
    Coord c1{5,6};
    Coord c2{5,5};
    Coord c3{5,5};
    Coord c4{19,19};
    Coord c5{390};
    CHECK(c1 != c2);
    CHECK(c3 == c2);
    CHECK(c4.toInt() == 399);
    CHECK(c5 == *(new Coord{19,10}) );
}

int main(int argc, const char **argv) {
  doctest::Context context(argc, argv);
  int test_result = context.run();
  if (context.shouldExit()) return test_result;
  return 0;
}
