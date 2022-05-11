#ifndef CircuitBreaker_h__
#define CircuitBreaker_h__

#include <pthread.h>

#include "CircuitBreakerHealthPolicy.h"
#include "CircuitBreakerClosedState.h"
#include "CircuitBreakerOpenState.h"
#include "CircuitBreakerHalfOpenState.h"

namespace NoiseCirkuit
{
    class CircuitBreaker
    {
    private:
        pthread_mutex_t _locker;

        CircuitBreakerHealthPolicy* policy;
        CircuitBreakerState* state;

        void changeState(CircuitBreakerState* newState);

        friend class CircuitBreakerClosedState;
        friend class CircuitBreakerOpenState;
        friend class CircuitBreakerHalfOpenState;

    public:
        CircuitBreaker(CircuitBreakerHealthPolicy* policy);
        virtual ~CircuitBreaker();

        void initialize();
        bool isRequestAllowed();
    };
}

#endif // CircuitBreaker_h__
