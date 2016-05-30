#include "ThreadManager.h"
#include <mutex>

using namespace raccoon;

ThreadManager::ThreadManager(std::function<void()> callback):
m_callback(callback),
m_exitThread(false),
m_executeCallback(false)
{}

void ThreadManager::ThreadFunction()
{
    while(true)
    {
        if(m_executeCallback)
        {
            m_callback();
            m_executeCallback = false;
        }
        else if(m_exitThread && !m_executeCallback)
        {
            break;
        }
    }
}

bool ThreadManager::RegisterCallbackExecutionRequest()
{
    std::lock_guard<SpinLock> mutex(m_lock);
    if(m_exitThread)
    {
        return false;
    }

    while(m_executeCallback)
    {
        // Spin thread while the call_back is executing
    }

    m_executeCallback = true;
    return true;
}

void ThreadManager::RegisterThreadTerminationRequest()
{
    std::lock_guard<SpinLock> mutex(m_lock);
    m_exitThread = true;
}
