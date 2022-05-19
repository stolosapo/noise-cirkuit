#include "CircuitBreakerTest.h"
#include <noisetest/Assertion.h>
#include "CircuitBreaker.h"
#include "MockHealthPolicy.h"

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
    NoiseCirkuit::MockHealthPolicy mockPolicy(true);
    NoiseCirkuit::CircuitBreaker cb(&mockPolicy);

    assertEqual(NoiseCirkuit::NONE, cb.getStatus());
}

void test_circuitbreaker_should_init_correct()
{

}
