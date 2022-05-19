#include "CircuitBreakerOpenStateTest.h"
#include <noisetest/Assertion.h>
#include "../src/CircuitBreaker.h"
#include "../src/MockHealthPolicy.h"

#include <unistd.h>

using namespace NoiseTest;

CircuitBreakerOpenStateTest::CircuitBreakerOpenStateTest(): UnitTestSuite("CircuitBreakerOpenState Tests", 0)
{

}

CircuitBreakerOpenStateTest::~CircuitBreakerOpenStateTest()
{

}

void CircuitBreakerOpenStateTest::registerTests()
{
    registerTest("Should not allow request when time is not expired", &test_openstate_should_notallow_request_when_time_is_not_expired);
    registerTest("Should change state to HalfOpen when time is expired", &test_openstate_should_change_state_to_halfopen_when_time_is_expired);
}

void test_openstate_should_notallow_request_when_time_is_not_expired()
{
    NoiseCirkuit::MockHealthPolicy mockPolicy(true, 0, 10);
    NoiseCirkuit::CircuitBreaker cb(&mockPolicy);
    NoiseCirkuit::CircuitBreakerOpenState state(&cb);

    assertFalse(state.isRequestAllowed());
}

void test_openstate_should_change_state_to_halfopen_when_time_is_expired()
{
    NoiseCirkuit::MockHealthPolicy mockPolicy(false, 0, 0);
    NoiseCirkuit::CircuitBreaker cb(&mockPolicy);
    NoiseCirkuit::CircuitBreakerOpenState state(&cb);

    sleep(1);

    assertFalse(state.isRequestAllowed());
    assertEqual(NoiseCirkuit::HALFOPEN, cb.getStatus());
}
