#include "SpinLock.h"
using namespace raccoon;

SpinLock::SpinLock():m_flag(ATOMIC_FLAG_INIT)
{
}

void SpinLock::lock()
{
    while (m_flag.test_and_set())
    {

    }
}

bool SpinLock::try_lock()
{
    return !m_flag.test_and_set();
}

void SpinLock::unlock()
{
    m_flag.clear();
}
