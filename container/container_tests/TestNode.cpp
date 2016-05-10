#include "../Node.h"
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

// Tests that the Foo::Bar() method does Abc.
BOOST_AUTO_TEST_CASE(CreateNode)
{
  SomeData m_data;
  Node<SomeData> nd(m_data);
  BOOST_ASSERT(nd.Data().x == 20.0);
  BOOST_ASSERT(nd.Data().y == 2);
  BOOST_ASSERT(nd.Data().z == nullptr);
}

BOOST_AUTO_TEST_CASE(AddChild)
{
    SomeData m_data;
    Node<SomeData> nd(m_data);
    nd.AddChild(&nd);
    nd.AddChild(&nd);

    BOOST_ASSERT(nd.GetNumChildren() == 2);
}

BOOST_AUTO_TEST_CASE(GetChild)
{
    SomeData m_data;
    Node<SomeData> nd(m_data);

    nd.AddChild(&nd);
    nd.AddChild(&nd);
    BOOST_ASSERT(nd.GetChild(0)->Data().x == 20);
    BOOST_ASSERT(nd.GetChild(1)->Data().x == 20);

    try{
        // This is expected to throw
        nd.GetChild(4);

        // Should never get here.
        BOOST_ASSERT(false);
    }
    catch(...)
    {
        // This is fine behavior
    }

}
