#include "gtest/gtest.h"
#include "../BTree.h"
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
class TestBTree : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  TestBTree() {
    // You can do set-up work for each test here.    
  }

  virtual ~TestBTree() {
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
TEST_F(TestBTree, TestCreateTree) 
{
    BNode<SomeData> nd(m_data);    
    BTree<SomeData> foo(&nd);
    ASSERT_TRUE(foo.GetRoot() == &nd);
    
    try{
        BNode<SomeData>* tmp(nullptr);
        BTree<SomeData> test(tmp);
        
        // Should never get here
        ASSERT_TRUE(false);
    }
    catch(...)
    {
        // This is expected to throw
    }
}

TEST_F(TestBTree, TestTreeTraverse)
{
    // Create nodes
    std::vector<BNode<int>> nodes;
    
    // The test involves just adding up the data in all nodes
    const int totalNodes = 5;
    const int sum = totalNodes*(totalNodes-1)/2;
    for(int i=0;i<totalNodes;++i)
    {
        nodes.push_back(BNode<int>(i));
    }
    
    ASSERT_TRUE(nodes.size() == totalNodes);
    
    BTree<int> foo(&nodes[0]);
    foo.SetLeft(&nodes[0], &nodes[1]);
    foo.SetRight(&nodes[0], &nodes[2]);
    
    foo.SetLeft(&nodes[1], &nodes[3]);
    foo.SetRight(&nodes[1], &nodes[4]);
        
    int nodeCount = 0;
    
    foo.PerformActionOnAllNodes([&nodeCount](const int& i){
        nodeCount += i;        
    });
    
    ASSERT_TRUE(nodeCount == sum);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
}