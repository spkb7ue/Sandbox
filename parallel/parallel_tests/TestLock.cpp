#include "gtest/gtest.h"
#include <parallel/SpinLock.h>
#include <parallel/NullLock.h>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;
using namespace raccoon;

// The fixture for testing class Foo.
class TestLock : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  TestLock() {
    // You can do set-up work for each test here.
  }

  virtual ~TestLock() {
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
  SpinLock m_spinLock;
  NullLock m_nullLock;

  static int TestIncrement(int numThreads, int numIncrements, ILock *lock);
};

int TestLock::TestIncrement(int numThreads, int numIncrements, ILock *lock)
{
    int count = 0;
    std::function<void()> func = [&count, numIncrements, lock](){
        for(int i=0;i<numIncrements;++i)
        {
            std::lock_guard<ILock> lockGuard(*lock);
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
TEST_F(TestLock, SpinLock)
{
    int numRep = 1000;
    int numThreads = 3;
    int numIncrements = 50;
    for(int i=0;i<numRep;++i)
    {
        ASSERT_TRUE(TestIncrement(numThreads, numIncrements, &m_spinLock) == numThreads*numIncrements);
    }
}

TEST_F(TestLock, NullLock)
{
    int numRep = 1000;
    int numThreads = 3;
    int numIncrements = 50;
    long expectedValue = 0;
    long actualValue = 0;
    for(int i=0;i<numRep;++i)
    {
        actualValue += TestIncrement(numThreads, numIncrements, &m_nullLock);
        expectedValue += numThreads*numIncrements;
    }
    ASSERT_FALSE(actualValue == expectedValue);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
