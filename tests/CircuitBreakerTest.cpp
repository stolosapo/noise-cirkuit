#include "CircuitBreakerTest.h"
#include <noisetest/Assertion.h>

#include "CircuitBreaker.h"
#include "MockHealthPolicy.h"

using namespace NoiseCirkuit;
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
}

void test_circuitbreaker_should_none_state()
{
    MockHealthPolicy healthy(true);
    CircuitBreaker cb(&healthy);

    assertEqual(NONE, cb.getStatus());
}

void test_circuitbreaker_should_init_correct()
{
    MockHealthPolicy healthy(true);
    CircuitBreaker cb(&healthy);
    cb.initialize();

    assertEqual(CLOSED, cb.getStatus());
}
