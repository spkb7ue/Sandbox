#include "gtest/gtest.h"
#include <parallel/SpinLockMutex.h>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;
using namespace raccoon;

// The fixture for testing class Foo.
class TestSpinLockMutex : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  TestSpinLockMutex() {
    // You can do set-up work for each test here.
  }

  virtual ~TestSpinLockMutex() {
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

  // Objects declared here can be used by all tests in the test case for Foo
  SpinLockMutex m_spinLock;

  int TestIncrement(int numThreads, int numIncrements);
};

int TestSpinLockMutex::TestIncrement(int numThreads, int numIncrements)
{
    int count = 0;
    std::function<void()> func = [&count, numIncrements, this](){
        for(int i=0;i<numIncrements;++i)
        {
            std::lock_guard<SpinLockMutex> lockGuard(m_spinLock);
            ++count;
        }
    };

    std::vector<std::thread> v;
    for (int n = 0; n < numThreads; ++n) {
        v.emplace_back(func);
    }

    for (auto& t : v) {
        t.join();
    }
    return count;
}

// Tests that the Foo::Bar() method does Abc.
TEST_F(TestSpinLockMutex, TestIncrementingValue)
{
    int numRep = 1000;
    int numThreads = 3;
    int numIncrements = 50;
    for(int i=0;i<numRep;++i)
    {
        ASSERT_TRUE(TestIncrement(numThreads, numIncrements) == numThreads*numIncrements);
    }

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
