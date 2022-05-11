#ifndef CircuitBreakerOpenState_h__
#define CircuitBreakerOpenState_h__

#include <time.h>
#include "CircuitBreakerState.h"

namespace NoiseCirkuit
{
    class CircuitBreakerOpenState : public CircuitBreakerState
    {
    private:
        static const int openStateTimeoutSec = 3;

        time_t exitTime;

    public:
        CircuitBreakerOpenState(CircuitBreaker* cb);
        virtual ~CircuitBreakerOpenState();

        virtual bool isRequestAllowed();
    };
}

#endif // CircuitBreakerOpenState_h__
