#pragma once
#include <functional>



namespace raccoon
{
    class ThreadManager
    {
    public:
        ThreadManager(std::function<void()> callback);
    private:
        std::function<void()> m_callback;
    };
}
