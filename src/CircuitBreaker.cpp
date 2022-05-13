#include "CircuitBreaker.h"

#include <stdio.h>
#include <stdlib.h>

using namespace NoiseCirkuit;

CircuitBreaker::CircuitBreaker(CircuitBreakerHealthPolicy* policy)
    : policy(policy)
{
    pthread_mutex_init(&_locker, NULL);

    state = NULL;

    /* initialize random seed: */
      srand(time(NULL));
}

CircuitBreaker::~CircuitBreaker()
{
    pthread_mutex_destroy(&_locker);

    if (state != NULL)
    {
        delete state;
    }
}

void CircuitBreaker::initialize()
{
    changeState(new CircuitBreakerClosedState(this));
}

void CircuitBreaker::changeState(CircuitBreakerState* newState)
{
    pthread_mutex_lock(&_locker);

    if (state != NULL)
    {
        delete state;
    }

    state = newState;

    pthread_mutex_unlock(&_locker);
}

bool CircuitBreaker::isRequestAllowed()
{
    if (state == NULL)
    {
        return false;
    }

    return state->isRequestAllowed();
}
