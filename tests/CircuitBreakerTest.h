#ifndef CircuitBreakerTest_h__
#define CircuitBreakerTest_h__

#include <noisetest/UnitTestSuite.h>

void test_circuitbreaker_should_init_correct();

class CircuitBreakerTest: public NoiseTest::UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	CircuitBreakerTest();
	virtual ~CircuitBreakerTest();

};

#endif // CircuitBreakerTest_h__
