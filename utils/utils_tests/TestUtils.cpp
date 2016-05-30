#include <utils/FastUtils.h>
#define BOOST_TEST_MODULE TEST_Utils
#include <boost/test/unit_test.hpp>

using namespace raccoon;

BOOST_AUTO_TEST_CASE(TestUtils_TestBinaryRepresentation)
{
    static_assert(GetBinaryRepresentationV1<9>::bit_num == 1001, "Got a wrong binary representation");
    static_assert(GetBinaryRepresentationV2<9>::value == 1001, "Got a wrong binary representation");
}
