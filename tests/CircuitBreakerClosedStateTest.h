#ifndef CircuitBreakerClosedStateTest_h__
#define CircuitBreakerClosedStateTest_h__

#include <noisetest/UnitTestSuite.h>

void test_closedstate_should_allow_request_when_is_healthy();
void test_closedstate_should_openstate_when_is_not_healthy();

class CircuitBreakerClosedStateTest: public NoiseTest::UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	CircuitBreakerClosedStateTest();
	virtual ~CircuitBreakerClosedStateTest();

};

#endif // CircuitBreakerClosedStateTest_h__
