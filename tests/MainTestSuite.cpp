#include "MainTestSuite.h"
#include "CircuitBreakerTest.h"

MainTestSuite::MainTestSuite(): UnitTestSuite("Main Test Suite", 0)
{

}

MainTestSuite::~MainTestSuite()
{

}

void MainTestSuite::registerTests()
{
    registerTest(new CircuitBreakerTest);
}
