#include "gtest/gtest.h"
#include "../Node.h"
#include <iostream>
using namespace std;
using namespace raccoon;

struct SomeData
{
  double x;
  int y;
  char *z;
};

// The fixture for testing class Foo.
class TestNode : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  TestNode() {
    // You can do set-up work for each test here.    
  }

  virtual ~TestNode() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
    m_data.x = 20.0;
    m_data.y = 2;
    m_data.z = nullptr;
    
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
  
  SomeData m_data;
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(TestNode, CreateNode) 
{
  
  Node<SomeData> nd(m_data);
  ASSERT_TRUE(nd.Data().x == 20.0);
  ASSERT_TRUE(nd.Data().y == 2);
  ASSERT_TRUE(nd.Data().z == nullptr);
}

TEST_F(TestNode, AddChild)
{
  Node<SomeData> nd(m_data);
  
  nd.AddChild(&nd);
  nd.AddChild(&nd);
  
  ASSERT_TRUE(nd.GetNumChildren() == 2);
}

TEST_F(TestNode, GetChild)
{
    Node<SomeData> nd(m_data);
    
    nd.AddChild(&nd);
    nd.AddChild(&nd);
    ASSERT_TRUE(nd.GetChild(0)->Data().x == 20);
    ASSERT_TRUE(nd.GetChild(1)->Data().x == 20);      
    
    try{
        // This is expected to throw
        nd.GetChild(4);
        
        // Should never get here.
        ASSERT_TRUE(false);
    }
    catch(...)
    {
        // This is fine behavior
    }
    
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}