#pragma once
#include "ILock.h"

namespace raccoon
{

class NullLock : public ILock<NullLock>
{
public:
    void lockImpl(){}
    bool tryLockImpl(){return true;}
    void unlockImpl(){}
};

}
