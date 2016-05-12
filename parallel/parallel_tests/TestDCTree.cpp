#include <parallel/DCTree.h>
#include <vector>
#include <thread>
#include <mutex>
#define BOOST_TEST_MODULE TEST_DCTree
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace raccoon;

namespace
{
struct SomeData
{
    SomeData()
    {
        x = 20.0;
        y = 2;
        z = nullptr;
    }
  double x;
  int y;
  char *z;
};

}

// Tests that the Foo::Bar() method does Abc.
BOOST_AUTO_TEST_CASE(TestDCTree_TestCtor)
{
   // Test Creation of a tree
   SomeData dat;
   BNode<SomeData> x(dat);
   DCTree<SomeData> ruff(&x);

}
