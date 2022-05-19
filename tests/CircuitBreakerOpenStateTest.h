#ifndef CircuitBreakerOpenStateTest_h__
#define CircuitBreakerOpenStateTest_h__

#include <noisetest/UnitTestSuite.h>

void test_openstate_should_notallow_request_when_time_is_not_expired();
void test_openstate_should_change_state_to_halfopen_when_time_is_expired();

class CircuitBreakerOpenStateTest: public NoiseTest::UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	CircuitBreakerOpenStateTest();
	virtual ~CircuitBreakerOpenStateTest();

};

#endif // CircuitBreakerOpenStateTest_h__
