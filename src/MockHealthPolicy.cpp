#ifndef MockHealthPolicy_h__
#define MockHealthPolicy_h__

#include "CircuitBreakerHealthPolicy.h"

namespace NoiseCirkuit
{
    class MockHealthPolicy: public CircuitBreakerHealthPolicy
    {
    private:
        bool healthy;

    public:
        MockHealthPolicy(bool healthy): CircuitBreakerHealthPolicy(), healthy(healthy)
        {

        }

        virtual ~MockHealthPolicy()
        {

        }

        virtual bool isHealthy()
        {
            return this->healthy;
        }
    };
}

#endif // MockHealthPolicy_h__
