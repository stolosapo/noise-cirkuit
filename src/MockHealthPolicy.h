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
        MockHealthPolicy(bool healthy);
        virtual ~MockHealthPolicy();
        virtual bool isHealthy();
    };
}

#endif // MockHealthPolicy_h__
