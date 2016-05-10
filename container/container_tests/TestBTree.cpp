#include "../BTree.h"
#include <iostream>
#define BOOST_TEST_MODULE TEST_BTree
#include <boost/test/unit_test.hpp>
using namespace std;
using namespace raccoon;

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

namespace racoon{

BOOST_AUTO_TEST_SUITE(Test_BTree);
// Tests that the Foo::Bar() method does Abc.
BOOST_AUTO_TEST_CASE(TestCreateTree)
{
    SomeData m_data;
    BNode<SomeData> nd(m_data);
    BTree<SomeData> foo(&nd);
    BOOST_ASSERT(foo.GetRoot() == &nd);

    try{
        BNode<SomeData>* tmp(nullptr);
        BTree<SomeData> test(tmp);

        // Should never get here
        BOOST_ASSERT(false);
    }
    catch(...)
    {
        // This is expected to throw
    }
}

BOOST_AUTO_TEST_CASE(TestTreeTraverse)
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

    BOOST_ASSERT(nodes.size() == totalNodes);

    BTree<int> foo(&nodes[0]);
    foo.SetLeft(&nodes[0], &nodes[1]);
    foo.SetRight(&nodes[0], &nodes[2]);

    foo.SetLeft(&nodes[1], &nodes[3]);
    foo.SetRight(&nodes[1], &nodes[4]);

    int nodeCount = 0;

    foo.PerformActionOnAllNodes([&nodeCount](const int& i){
        nodeCount += i;
    });

    BOOST_ASSERT(nodeCount == sum);
}

BOOST_AUTO_TEST_SUITE_END();
}
