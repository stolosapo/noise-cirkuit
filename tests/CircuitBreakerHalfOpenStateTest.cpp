#include "CircuitBreakerHalfOpenStateTest.h"
#include <noisetest/Assertion.h>
#include "../src/CircuitBreaker.h"
#include "../src/MockHealthPolicy.h"

#include <unistd.h>

using namespace NoiseTest;

CircuitBreakerHalfOpenStateTest::CircuitBreakerHalfOpenStateTest(): UnitTestSuite("CircuitBreakerHalfOpenState Tests", 0)
{

}

CircuitBreakerHalfOpenStateTest::~CircuitBreakerHalfOpenStateTest()
{

}

void CircuitBreakerHalfOpenStateTest::registerTests()
{
    registerTest("Should not allow request when not healthy and no chance to pass", &test_halfopenstate_should_notallow_request_when_is_unhealthy_and_no_chance);
    registerTest("Should allow request when not healthy but chance to pass", &test_halfopenstate_should_allow_request_when_is_unhealthy_and_chance);
    registerTest("Should change state to CLOSED when is healthy", &test_halfopenstate_should_change_state_to_closed_when_is_healthy);
}

void test_halfopenstate_should_notallow_request_when_is_unhealthy_and_no_chance()
{
    NoiseCirkuit::MockHealthPolicy mockPolicy(false, 0, 10);
    NoiseCirkuit::CircuitBreaker cb(&mockPolicy);
    NoiseCirkuit::CircuitBreakerHalfOpenState state(&cb);

    assertFalse(state.isRequestAllowed());
}

void test_halfopenstate_should_allow_request_when_is_unhealthy_and_chance()
{
    NoiseCirkuit::MockHealthPolicy mockPolicy(false, 1.1, 10);
    NoiseCirkuit::CircuitBreaker cb(&mockPolicy);
    NoiseCirkuit::CircuitBreakerHalfOpenState state(&cb);

    assertTrue(state.isRequestAllowed());
}

void test_halfopenstate_should_change_state_to_closed_when_is_healthy()
{
    NoiseCirkuit::MockHealthPolicy mockPolicy(true);
    NoiseCirkuit::CircuitBreaker cb(&mockPolicy);
    NoiseCirkuit::CircuitBreakerHalfOpenState state(&cb);

    assertTrue(state.isRequestAllowed());
    assertEqual(NoiseCirkuit::CLOSED, cb.getStatus());
}
