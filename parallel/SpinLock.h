#include "ILock.h"
#include <atomic>

namespace racoon
{
    class SpinLock : public ILock
    {
    public:
        virtual void lock() override;

    private:

    };
}
