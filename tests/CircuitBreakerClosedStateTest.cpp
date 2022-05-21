#include "CircuitBreakerClosedStateTest.h"
#include <noisetest/Assertion.h>
#include "../src/CircuitBreaker.h"
#include "../src/MockHealthPolicy.h"

using namespace NoiseTest;

CircuitBreakerClosedStateTest::CircuitBreakerClosedStateTest(): UnitTestSuite("CircuitBreakerClosedState Tests", 0)
{

}

CircuitBreakerClosedStateTest::~CircuitBreakerClosedStateTest()
{

}

void CircuitBreakerClosedStateTest::registerTests()
{
    registerTest("Should allow request when is healthy", &test_closedstate_should_allow_request_when_is_healthy);
    registerTest("Should change to OPEN state when is not healthy", &test_closedstate_should_openstate_when_is_not_healthy);
}

void test_closedstate_should_allow_request_when_is_healthy()
{
    NoiseCirkuit::MockHealthPolicy mockPolicy(true);
    NoiseCirkuit::CircuitBreaker cb(&mockPolicy);
    NoiseCirkuit::CircuitBreakerClosedState closedState(&cb);

    assertTrue(closedState.isRequestAllowed());
}

void test_closedstate_should_openstate_when_is_not_healthy()
{
    NoiseCirkuit::MockHealthPolicy mockPolicy(false, 0, 10);
    NoiseCirkuit::CircuitBreaker cb(&mockPolicy);
    NoiseCirkuit::CircuitBreakerClosedState closedState(&cb);

    assertFalse(closedState.isRequestAllowed());
    assertEqual(NoiseCirkuit::OPEN, cb.getStatus());
}
