#define BOOST_TEST_MODULE TEST_BTree
#include <boost/test/unit_test.hpp>
#include <parallel/SpinLock.h>
#include <parallel/NullLock.h>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;
using namespace raccoon;
namespace
{
    // Objects declared here can be used by all tests in the test case for Foo
    SpinLock m_spinLock;
    NullLock m_nullLock;

    int TestIncrement(int numThreads, int numIncrements, ILock *lock)
    {
        int count = 0;
        std::function<void()> func = [&count, numIncrements, lock](){
            for(int i=0;i<numIncrements;++i)
            {
                std::lock_guard<ILock> lockGuard(*lock);
                ++count;
            }
        };

        std::vector<std::thread> v;
        for (int n = 0; n < numThreads; ++n) {
            v.emplace_back(func);
        }

        for (auto& t : v) {
            t.join();
        }
        return count;
    }

}

BOOST_AUTO_TEST_CASE(TestSpinLock)
{
    int numRep = 1000;
    int numThreads = 3;
    int numIncrements = 50;
    for(int i=0;i<numRep;++i)
    {
        BOOST_ASSERT(TestIncrement(numThreads, numIncrements, &m_spinLock) == numThreads*numIncrements);
    }
}

BOOST_AUTO_TEST_CASE(TestNullLock)
{
    int numRep = 1000;
    int numThreads = 3;
    int numIncrements = 50;
    long expectedValue = 0;
    long actualValue = 0;
    for(int i=0;i<numRep;++i)
    {
        actualValue += TestIncrement(numThreads, numIncrements, &m_nullLock);
        expectedValue += numThreads*numIncrements;
    }
    /// This test case can fail once in a while. Don't bother about this too much.
    BOOST_ASSERT(actualValue != expectedValue);
}
