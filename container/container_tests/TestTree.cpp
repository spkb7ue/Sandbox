#include "../Tree.h"
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
namespace raccoon{

// Tests that the Foo::Bar() method does Abc.
BOOST_AUTO_TEST_CASE(TestCreateTree)
{
    SomeData m_data;
    Node<SomeData> nd(m_data);
    Tree<SomeData> foo(&nd);
    BOOST_ASSERT(foo.GetRoot() == &nd);

    try{
        Node<SomeData>* tmp(nullptr);
        Tree<SomeData> test(tmp);

        // Should never get here
        BOOST_ASSERT(false);
    }
    catch(...)
    {
        // This is expected to throw
    }
}

BOOST_AUTO_TEST_CASE(TestAddChild)
{
    SomeData m_data;
    Node<SomeData> nd(m_data);
    Tree<SomeData> foo(&nd);
    foo.AddNode(foo.GetRoot(), &nd);
}

BOOST_AUTO_TEST_CASE(TestTreeTraverse)
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

    BOOST_ASSERT(nodeCount == 21);
}

}
