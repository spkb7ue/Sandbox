#pragma once

namespace raccoon
{

template<typename LockingStrategy>
class ILock
{
public:
    void lock()
    {
        static_cast<LockingStrategy*>(this)->lockImpl();
    }
    bool try_lock()
    {
        return static_cast<LockingStrategy*>(this)->tryLockImpl();
    };
    void unlock()
    {
        static_cast<LockingStrategy*>(this)->unlockImpl();
    };
};

}
