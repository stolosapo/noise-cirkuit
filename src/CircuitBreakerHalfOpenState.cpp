#include "CircuitBreaker.h"

#include <stdio.h>
#include <stdlib.h>

using namespace NoiseCirkuit;

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
        /* random 0 - 1 */
        double chance = (double) rand() / RAND_MAX;
        return chance <= cb->policy->halfOpenStatePassChance();
    }

    /* Change state to CLOSED */
    cb->changeState(new CircuitBreakerClosedState(cb));

    /* And check again */
    return cb->isRequestAllowed();
}
