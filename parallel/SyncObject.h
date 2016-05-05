#pragma once
#include <memory>
#include <atomic>

namespace raccoon{
    class SyncObject{
    public:
        SyncObject(std::shared_ptr<std::atomic<bool>> flag,
                   const bool& exitFlag,
                   bool testFlag);
        void Wait();
        void Signal();
    private:
        std::shared_ptr<std::atomic<bool>> m_flag;
        const bool& m_exitFlag;
        const bool m_testFlag;
    };
}