#pragma once
#include <functional>
#include <atomic>
#include "SpinLock.h"
#include <mutex>

namespace raccoon
{
    template<typename LockingPolicy>
    class ThreadManager
    {
    public:
        ThreadManager(std::function<void()> callback);

        /**
        * Register the request to execute the callback.
        * @return true ff the request was successful or false otherwise.
        * If the return value is true, it is guaranteed that the callback will
        * be executed exactly once. If the callback is currently in execution,
        * this method will stall the calling thread.
        */
        bool RegisterCallbackExecutionRequest();


        void RegisterThreadTerminationRequest();

    private:
        LockingPolicy m_lock;
        std::function<void()> m_callback;
        void ThreadFunction();

        std::atomic_bool m_exitThread;
        std::atomic_bool m_executeCallback;
    };

    template<typename LockingPolicy>
    ThreadManager<LockingPolicy>::ThreadManager(std::function<void()> callback):
        m_callback(callback),
        m_exitThread(false),
        m_executeCallback(false){}

    template<typename LockingPolicy>
    void ThreadManager<LockingPolicy>::ThreadFunction()
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

    template<typename LockingPolicy>
    bool ThreadManager<LockingPolicy>::RegisterCallbackExecutionRequest()
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

    template<typename LockingPolicy>
    void ThreadManager<LockingPolicy>::RegisterThreadTerminationRequest()
    {
        std::lock_guard<LockingPolicy> mutex(m_lock);
        m_exitThread = true;
    }
}
