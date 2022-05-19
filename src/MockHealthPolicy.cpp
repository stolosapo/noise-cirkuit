#include "MockHealthPolicy.h"

using namespace NoiseCirkuit;

MockHealthPolicy::MockHealthPolicy(bool healthy)
    : CircuitBreakerHealthPolicy(),
        healthy(healthy)
{
    this->_halfOpenStatePassChance = CircuitBreakerHealthPolicy::halfOpenStatePassChance();
    this->_openStateTimeoutSeconds = CircuitBreakerHealthPolicy::openStateTimeoutSeconds();
}

MockHealthPolicy::MockHealthPolicy(bool healthy, double halfOpenStatePassChance, int openStateTimeoutSeconds)
    : CircuitBreakerHealthPolicy(),
        healthy(healthy),
        _halfOpenStatePassChance(halfOpenStatePassChance),
        _openStateTimeoutSeconds(openStateTimeoutSeconds)
{

}

MockHealthPolicy::~MockHealthPolicy()
{

}

bool MockHealthPolicy::isHealthy()
{
    return this->healthy;
}

void MockHealthPolicy::setHealthy(bool healthy)
{
    this->healthy = healthy;
}

double MockHealthPolicy::halfOpenStatePassChance()
{
    return this->_halfOpenStatePassChance;
}

int MockHealthPolicy::openStateTimeoutSeconds()
{
    return this->_openStateTimeoutSeconds;
}
