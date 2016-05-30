#include <utils/FastUtils.h>
#define BOOST_TEST_MODULE TEST_Utils
#include <boost/test/unit_test.hpp>

using namespace raccoon;

// Tests that the Foo::Bar() method does Abc.
BOOST_AUTO_TEST_CASE(TestUtils_TestBinaryRepresentation)
{
    static_assert(get_bits<9>::bit_num == 1001, "Got a wrong binary representation");
    static_assert(Bin<9>::value == 1001, "Got a wrong binary representation");
}
