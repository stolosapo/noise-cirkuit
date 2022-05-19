#ifndef MockHealthPolicy_h__
#define MockHealthPolicy_h__

#include "CircuitBreaker.h"

namespace NoiseCirkuit
{
    class MockHealthPolicy: public CircuitBreakerHealthPolicy
    {
    private:
        bool healthy;
        double _halfOpenStatePassChance;
        int _openStateTimeoutSeconds;

    public:
        MockHealthPolicy(bool healthy);
        MockHealthPolicy(bool healthy, double halfOpenStatePassChance, int openStateTimeoutSeconds);
        virtual ~MockHealthPolicy();
        virtual bool isHealthy();
        void setHealthy(bool healthy);
        virtual double halfOpenStatePassChance();
        virtual int openStateTimeoutSeconds();
    };
}

#endif // MockHealthPolicy_h__
