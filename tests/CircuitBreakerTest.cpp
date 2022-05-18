#include "CircuitBreakerTest.h"
#include <noisetest/Assertion.h>

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

}

void test_circuitbreaker_should_init_correct()
{

}
