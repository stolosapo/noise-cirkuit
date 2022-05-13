#include "MockHealthPolicy.h"

using namespace NoiseCirkuit;

MockHealthPolicy::MockHealthPolicy(bool healthy)
    : CircuitBreakerHealthPolicy(), healthy(healthy)
{

}

MockHealthPolicy::~MockHealthPolicy()
{

}

bool MockHealthPolicy::isHealthy()
{
    return this->healthy;
}
