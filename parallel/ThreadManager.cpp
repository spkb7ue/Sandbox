#include "ThreadManager.h"

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
        if(m_exitThread)
        {
            break;
        }
        if(m_executeCallback)
        {
            m_callback();
            m_executeCallback = false;
        }
    }
}

bool ThreadManager::RegisterCallbackExecutionRequest()
{
    while(m_executeCallback)
    {
        // Spin thread while the call_back is executing
    }

    m_executeCallback = true;
    return !m_exitThread;
}

void ThreadManager::ExitThread()
{
    while(m_executeCallback)
    {

    }
}
