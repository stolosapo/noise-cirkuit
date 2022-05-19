#ifndef CircuitBreakerTest_h__
#define CircuitBreakerTest_h__

#include <noisetest/UnitTestSuite.h>

void test_circuitbreaker_should_none_state();
void test_circuitbreaker_should_init_correct();
void test_circuitbreaker_should_allowed_request_when_initialized();
void test_circuitbreaker_should_notallowed_request_when_notinitialized();

class CircuitBreakerTest: public NoiseTest::UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	CircuitBreakerTest();
	virtual ~CircuitBreakerTest();

};

#endif // CircuitBreakerTest_h__
