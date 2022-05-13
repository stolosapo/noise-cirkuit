#include "CircuitBreaker.h"

using namespace NoiseCirkuit;

const double CircuitBreakerHealthPolicy::DEFAULT_HALFOPENSTATE_PASS_CHANCE = 0.02;
const int CircuitBreakerHealthPolicy::DEFAULT_OPENSTATE_TIMEOUT_SEC = 3;

CircuitBreakerHealthPolicy::CircuitBreakerHealthPolicy()
{

}

CircuitBreakerHealthPolicy::~CircuitBreakerHealthPolicy()
{

}

double CircuitBreakerHealthPolicy::halfOpenStatePassChance()
{
    return DEFAULT_HALFOPENSTATE_PASS_CHANCE;
}

int CircuitBreakerHealthPolicy::openStateTimeoutSeconds()
{
    return DEFAULT_OPENSTATE_TIMEOUT_SEC;
}
