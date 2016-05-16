#pragma once
#include <functional>
#include <atomic>
#include "SpinLock.h"

namespace raccoon
{
    class ThreadManager
    {
    public:
        ThreadManager(std::function<void()> callback);

        bool RegisterCallbackExecutionRequest();
        void RegisterThreadTerminationRequest();

    private:
        SpinLock m_lock;
        std::function<void()> m_callback;
        void ThreadFunction();

        std::atomic_bool m_exitThread;
        std::atomic_bool m_executeCallback;
    };
}
