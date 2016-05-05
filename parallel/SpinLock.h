#pragma once
#include "ILock.h"
#include <atomic>

namespace raccoon
{
    class SpinLock : public ILock
    {
    public:
        SpinLock();
        virtual void lock() override;
        virtual bool try_lock() override;
        virtual void unlock() override;
    private:
         std::atomic_flag m_flag;
    };
}
