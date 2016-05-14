#include "ThreadManager.h"

using namespace raccoon;

ThreadManager::ThreadManager(std::function<void()> callback):
m_callback(callback),
m_exitThread(false)
{}

void ThreadManager::ThreadFunction()
{
    while(true)
    {
        if(m_exitThread)
        {
            break;
        }

        if(m_callback != nullptr)
        {
            m_callback();
        }
        m_executeCallback = false;
    }
}

void ThreadManager::RequestCallbackExecution()
{

}
