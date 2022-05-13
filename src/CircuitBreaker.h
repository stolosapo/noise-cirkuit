#ifndef CircuitBreaker_h__
#define CircuitBreaker_h__

#include <pthread.h>
#include <time.h>

namespace NoiseCirkuit
{
    class CircuitBreaker;

    enum CircuitBreakerStatus
    {
        NONE = 0,

        CLOSED = 1,

        OPEN = 2,

        HALFOPEN = 3
    };

    class CircuitBreakerHealthPolicy
    {
    private:
        static const double DEFAULT_HALFOPENSTATE_PASS_CHANCE;
        static const int DEFAULT_OPENSTATE_TIMEOUT_SEC;

    public:
        CircuitBreakerHealthPolicy();
        virtual ~CircuitBreakerHealthPolicy();

        virtual bool isHealthy() = 0;
        virtual double halfOpenStatePassChance();
        virtual int openStateTimeoutSeconds();
    };

    class CircuitBreakerState
    {
    private:
        CircuitBreakerStatus status;

    protected:
        CircuitBreaker* cb;

    public:
        CircuitBreakerState(CircuitBreaker* cb, CircuitBreakerStatus status);
        virtual ~CircuitBreakerState();

        virtual bool isRequestAllowed() = 0;
        CircuitBreakerStatus getStatus();
    };

    class CircuitBreakerClosedState : public CircuitBreakerState
    {
    public:
        CircuitBreakerClosedState(CircuitBreaker* cb);
        virtual ~CircuitBreakerClosedState();

        virtual bool isRequestAllowed();
    };

    class CircuitBreakerHalfOpenState : public CircuitBreakerState
    {
    public:
        CircuitBreakerHalfOpenState(CircuitBreaker* cb);
        virtual ~CircuitBreakerHalfOpenState();

        virtual bool isRequestAllowed();
    };

    class CircuitBreakerOpenState : public CircuitBreakerState
    {
    private:
        time_t exitTime;

    public:
        CircuitBreakerOpenState(CircuitBreaker* cb);
        virtual ~CircuitBreakerOpenState();

        virtual bool isRequestAllowed();
    };

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
        CircuitBreakerStatus getStatus();
    };
}

#endif // CircuitBreaker_h__
