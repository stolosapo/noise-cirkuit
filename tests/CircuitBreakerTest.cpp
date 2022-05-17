#include "CircuitBreakerTest.h"

#include "../src/CircuitBreaker.h"
#include "../src/MockHealthPolicy.h"

using namespace NoiseCirkuit;

CircuitBreakerTest::CircuitBreakerTest(): UnitTestSuite("CircuitBreaker Tests", 0)
{

}

CircuitBreakerTest::~CircuitBreakerTest()
{

}

void CircuitBreakerTest::registerTests()
{
    registerTest("Should Initialized correct", &test_circuitbreaker_should_init_correct);
}

void test_circuitbreaker_should_init_correct()
{
    MockHealthPolicy healthy(true);
    CircuitBreaker cb(&healthy);
    cb.initialize();
}
