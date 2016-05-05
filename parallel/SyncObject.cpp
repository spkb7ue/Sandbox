#include "SyncObject.h"
using namespace raccoon;

SyncObject::SyncObject(std::shared_ptr<std::atomic<bool>> flag,
                       const bool& exitFlag,
                       bool testFlag):
m_flag(flag),
m_exitFlag(exitFlag),
m_testFlag(testFlag)
{}

void SyncObject::Wait(){
    while(!m_exitFlag && *m_flag == m_testFlag);
}

void SyncObject::Signal(){
    *m_flag = m_testFlag;
}
