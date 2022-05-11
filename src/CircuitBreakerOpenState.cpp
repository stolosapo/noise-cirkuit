#include "CircuitBreakerOpenState.h"
#include "CircuitBreaker.h"
#include "TimeService.h"

using namespace NoiseCirkuit;

CircuitBreakerOpenState::CircuitBreakerOpenState(CircuitBreaker* cb)
    : CircuitBreakerState(cb, CB_OPEN)
{
    exitTime = timeRawNow() + openStateTimeoutSec;
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
