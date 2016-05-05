#include "gtest/gtest.h"
#include "../Tree.h"
#include <iostream>
using namespace std;
using namespace raccoon;

struct SomeData
{
  double x;
  int y;
  char *z;
};
namespace racoon{

// The fixture for testing class Foo.
class TestTree : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  TestTree() {
    // You can do set-up work for each test here.    
  }

  virtual ~TestTree() {
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
TEST_F(TestTree, TestCreateTree) 
{
    Node<SomeData> nd(m_data);    
    Tree<SomeData> foo(&nd);
    ASSERT_TRUE(foo.GetRoot() == &nd);
    
    try{
        Node<SomeData>* tmp(nullptr);
        Tree<SomeData> test(tmp);
        
        // Should never get here
        ASSERT_TRUE(false);
    }
    catch(...)
    {
        // This is expected to throw
    }
}

TEST_F(TestTree, TestAddChild)
{
    Node<SomeData> nd(m_data);
    Tree<SomeData> foo(&nd);
    foo.AddNode(foo.GetRoot(), &nd);    
}

TEST_F(TestTree, TestTreeTraverse)
{
    // Create nodes
    std::vector<Node<int>> nodes;
    for(int i=0;i<7;++i)
    {
        nodes.push_back(Node<int>(i));
    }
    
    Tree<int> foo(&nodes[0]);
    foo.AddNode(&nodes[0], &nodes[1]);
    foo.AddNode(&nodes[0], &nodes[2]);
    
    foo.AddNode(&nodes[1], &nodes[3]);
    foo.AddNode(&nodes[1], &nodes[4]);
    
    foo.AddNode(&nodes[2], &nodes[5]);
    foo.AddNode(&nodes[2], &nodes[6]);
    
    int nodeCount = 0;
    foo.PerformActionOnAllNodes([&nodeCount](const int& i){
        nodeCount += i;        
    });
    
    ASSERT_TRUE(nodeCount == 21);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
}