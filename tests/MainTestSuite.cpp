#include "MainTestSuite.h"
#include "CircuitBreakerTest.h"
#include "CircuitBreakerClosedStateTest.h"
#include "CircuitBreakerOpenStateTest.h"
#include "CircuitBreakerHalfOpenStateTest.h"

MainTestSuite::MainTestSuite(): UnitTestSuite("Main Test Suite", 0)
{

}

MainTestSuite::~MainTestSuite()
{

}

void MainTestSuite::registerTests()
{
    registerTest(new CircuitBreakerTest);
    registerTest(new CircuitBreakerClosedStateTest);
    registerTest(new CircuitBreakerOpenStateTest);
    registerTest(new CircuitBreakerHalfOpenStateTest);
}
