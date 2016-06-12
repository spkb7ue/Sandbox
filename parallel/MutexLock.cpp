#include "SpinLock.h"
using namespace raccoon;

SpinLock::SpinLock():m_flag(ATOMIC_FLAG_INIT)
{
}

void SpinLock::lockImpl()
{
    while (m_flag.test_and_set())
    {

    }
}

bool SpinLock::tryLockImpl()
{
    return !m_flag.test_and_set();
}

void SpinLock::unlockImpl()
{
    m_flag.clear();
}
