#include <utils/Data.h>
#define BOOST_TEST_MODULE TEST_Data
#include <boost/test/unit_test.hpp>
#include <string>

using namespace raccoon;

BOOST_AUTO_TEST_CASE(TestData_Workflow)
{
    Data<double, float, std::string> d(3.0, 5.0f, "This is a joke");
}
