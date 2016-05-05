#include "gtest/gtest.h"
#include <parallel/SyncObject.h>
#include <memory>
#include <thread>

using namespace std;
using namespace raccoon;

// The fixture for testing class Foo.
class TestSyncObject : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  TestSyncObject() {
    // You can do set-up work for each test here.
  }

  virtual ~TestSyncObject() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).

    m_maxEval = 20;
    m_exitFlag = false;
    m_flag.reset(new std::atomic<bool>());
    *m_flag = true;
    m_producer.reset(new SyncObject(m_flag, m_exitFlag, false));
    m_consumer.reset(new SyncObject(m_flag, m_exitFlag, true));
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  void Producer();
  int m_maxEval;
  std::unique_ptr<SyncObject> m_producer;
  std::unique_ptr<SyncObject> m_consumer;
  std::shared_ptr<std::atomic<bool>> m_flag;
  bool m_exitFlag;
};

void TestSyncObject::Producer()
{
    while(1)
    {

    }
}

// Tests that the Foo::Bar() method does Abc.
TEST_F(TestSyncObject, TestCtor)
{

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
