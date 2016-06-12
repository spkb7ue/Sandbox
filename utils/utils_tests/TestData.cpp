#include <utils/Data.h>
#define BOOST_TEST_MODULE TEST_Data
#include <boost/test/unit_test.hpp>
#include <string>

using namespace raccoon;
namespace
{
    struct point
    {
        point():x(1.0f),y(2.0f),z(3.0f){}
        float x;
        float y;
        float z;
    };
}

BOOST_AUTO_TEST_CASE(TestData_Workflow)
{
    point p;
    Data<double, point, std::string> d(3.0, p, "This is a joke");
    point q = Get<1>(d);
    BOOST_ASSERT(p.x == q.x);
}
