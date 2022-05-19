#include "CircuitBreakerTest.h"
#include <noisetest/Assertion.h>
#include "../src/CircuitBreaker.h"
#include "../src/MockHealthPolicy.h"

using namespace NoiseTest;

CircuitBreakerTest::CircuitBreakerTest(): UnitTestSuite("CircuitBreaker Tests", 0)
{

}

CircuitBreakerTest::~CircuitBreakerTest()
{

}

void CircuitBreakerTest::registerTests()
{
    registerTest("Should have state NONE when not initialized", &test_circuitbreaker_should_none_state);
    registerTest("Should Initialized correct", &test_circuitbreaker_should_init_correct);
    registerTest("Should allowed request when initialized and is healthy", &test_circuitbreaker_should_allowed_request_when_initialized);
    registerTest("Should not allow request when not initialized", &test_circuitbreaker_should_notallowed_request_when_notinitialized);
}

void test_circuitbreaker_should_none_state()
{
    NoiseCirkuit::MockHealthPolicy mockPolicy(true);
    NoiseCirkuit::CircuitBreaker cb(&mockPolicy);

    assertEqual(NoiseCirkuit::NONE, cb.getStatus());
}

void test_circuitbreaker_should_init_correct()
{
    NoiseCirkuit::MockHealthPolicy mockPolicy(true);
    NoiseCirkuit::CircuitBreaker cb(&mockPolicy);
    cb.initialize();

    assertEqual(NoiseCirkuit::CLOSED, cb.getStatus());
}

void test_circuitbreaker_should_allowed_request_when_initialized()
{
    NoiseCirkuit::MockHealthPolicy mockPolicy(true);
    NoiseCirkuit::CircuitBreaker cb(&mockPolicy);
    cb.initialize();

    assertTrue(cb.isRequestAllowed());
}

void test_circuitbreaker_should_notallowed_request_when_notinitialized()
{
    NoiseCirkuit::MockHealthPolicy mockPolicy(true);
    NoiseCirkuit::CircuitBreaker cb(&mockPolicy);

    assertFalse(cb.isRequestAllowed());
}
