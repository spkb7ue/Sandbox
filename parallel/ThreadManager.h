#pragma once
#include <functional>
#include <atomic>

namespace raccoon
{
    class ThreadManager
    {
    public:
        ThreadManager(std::function<void()> callback);

        void RequestCallbackExecution();

    private:
        std::function<void()> m_callback;
        void ThreadFunction();
        std::atomic_bool m_exitThread;
        std::atomic_bool m_executeCallback;
    };
}
