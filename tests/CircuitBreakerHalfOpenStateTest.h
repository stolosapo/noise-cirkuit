#ifndef CircuitBreakerHalfOpenStateTest_h__
#define CircuitBreakerHalfOpenStateTest_h__

#include <noisetest/UnitTestSuite.h>

void test_halfopenstate_should_notallow_request_when_is_unhealthy_and_no_chance();
void test_halfopenstate_should_allow_request_when_is_unhealthy_and_chance();
void test_halfopenstate_should_change_state_to_closed_when_is_healthy();

class CircuitBreakerHalfOpenStateTest: public NoiseTest::UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	CircuitBreakerHalfOpenStateTest();
	virtual ~CircuitBreakerHalfOpenStateTest();

};

#endif // CircuitBreakerHalfOpenStateTest_h__
