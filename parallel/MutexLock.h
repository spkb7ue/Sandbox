#pragma once
#include "ILock.h"
#include <atomic>

namespace raccoon
{
    class SpinLock : public ILock<SpinLock>
    {
    public:
        SpinLock();
        void lockImpl();
        bool tryLockImpl();
        void unlockImpl();
    private:
        std::atomic_flag m_flag;
    };
}
