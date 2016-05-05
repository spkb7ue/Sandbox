#pragma once

#include <atomic>

namespace raccoon{
class SpinLockMutex{
    
private:
    std::atomic_flag m_flag;
    
public:
    SpinLockMutex();
        
    void lock();
    
    void unlock();
    
    SpinLockMutex(const SpinLockMutex&) = delete;
    SpinLockMutex& operator=(const SpinLockMutex&) = delete;
};
}