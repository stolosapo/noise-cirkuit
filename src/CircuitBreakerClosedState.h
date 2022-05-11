#ifndef CircuitBreakerClosedState_h__
#define CircuitBreakerClosedState_h__

#include "CircuitBreakerState.h"

namespace NoiseCirkuit
{
    class CircuitBreakerClosedState : public CircuitBreakerState
    {
    public:
        CircuitBreakerClosedState(CircuitBreaker* cb);
        virtual ~CircuitBreakerClosedState();

        virtual bool isRequestAllowed();
    };
}

#endif // CircuitBreakerClosedState_h__
