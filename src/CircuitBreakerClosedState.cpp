#include "CircuitBreaker.h"

using namespace NoiseCirkuit;

CircuitBreakerClosedState::CircuitBreakerClosedState(CircuitBreaker* cb)
    : CircuitBreakerState(cb, CLOSED)
{

}

CircuitBreakerClosedState::~CircuitBreakerClosedState()
{

}

bool CircuitBreakerClosedState::isRequestAllowed()
{
    if (cb->policy->isHealthy())
    {
        return true;
    }

    /* Change state to OPEN */
    cb->changeState(new CircuitBreakerOpenState(cb));

    /* And check again */
    return cb->isRequestAllowed();
}
