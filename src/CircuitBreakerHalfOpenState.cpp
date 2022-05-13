#include "CircuitBreaker.h"

#include <stdio.h>
#include <stdlib.h>

using namespace NoiseCirkuit;

const double CircuitBreakerHalfOpenState::chance = 0.02;

CircuitBreakerHalfOpenState::CircuitBreakerHalfOpenState(CircuitBreaker* cb)
    : CircuitBreakerState(cb, HALFOPEN)
{

}

CircuitBreakerHalfOpenState::~CircuitBreakerHalfOpenState()
{

}

bool CircuitBreakerHalfOpenState::isRequestAllowed()
{
    if (!cb->policy->isHealthy())
    {
        return (double) rand() <= chance;
    }

    /* Change state to CLOSED */
    cb->changeState(new CircuitBreakerClosedState(cb));

    /* And check again */
    return cb->isRequestAllowed();
}
