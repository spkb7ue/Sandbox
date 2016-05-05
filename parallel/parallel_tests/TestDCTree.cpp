#include "gtest/gtest.h"
#include <parallel/DCTree.h>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;
using namespace raccoon;

struct SomeData
{
  double x;
  int y;
  char *z;
};

// The fixture for testing class Foo.
class TestDCTree : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  TestDCTree() {
    // You can do set-up work for each test here.
  }

  virtual ~TestDCTree() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).


  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(TestDCTree, TestCtor)
{
   // Test Creation of a tree
   SomeData dat;
   BNode<SomeData> x(dat);
   DCTree<SomeData> ruff(&x);

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
