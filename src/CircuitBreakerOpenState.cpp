#include "CircuitBreaker.h"

using namespace NoiseCirkuit;

CircuitBreakerOpenState::CircuitBreakerOpenState(CircuitBreaker* cb)
    : CircuitBreakerState(cb, OPEN)
{
    exitTime = timeRawNow() + cb->policy->openStateTimeoutSeconds();
}

CircuitBreakerOpenState::~CircuitBreakerOpenState()
{

}

bool CircuitBreakerOpenState::isRequestAllowed()
{
    if (timeRawNow() <= exitTime)
    {
        return false;
    }

    /* Change state to HALF-OPEN */
    cb->changeState(new CircuitBreakerHalfOpenState(cb));

    /* And check again */
    return cb->isRequestAllowed();
}
