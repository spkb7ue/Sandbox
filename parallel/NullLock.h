#pragma once
#include "ILock.h"

namespace raccoon
{

class NullLock : public ILock
{
public:
    virtual void lock() override {}
    virtual bool try_lock() override{return true;}
    virtual void unlock() override{}
};

}
