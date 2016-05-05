#include "SpinLockMutex.h"
using namespace raccoon;
using namespace std;
SpinLockMutex::SpinLockMutex():
    m_flag(ATOMIC_FLAG_INIT)
{}

void SpinLockMutex::lock(){
    while(m_flag.test_and_set(std::memory_order_acquire));
}

void SpinLockMutex::unlock(){
    m_flag.clear(std::memory_order_release);
}
