AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

bin_PROGRAMS = noisecirkuittester

common_sources = \
    MainTestSuite.h MainTestSuite.cpp \
    CircuitBreakerTest.h CircuitBreakerTest.cpp \
    CircuitBreakerClosedStateTest.h CircuitBreakerClosedStateTest.cpp \
    CircuitBreakerOpenStateTest.h CircuitBreakerOpenStateTest.cpp \
    CircuitBreakerHalfOpenStateTest.h CircuitBreakerHalfOpenStateTest.cpp \
    ../src/CircuitBreaker.h ../src/CircuitBreaker.cpp \
    ../src/CircuitBreakerClosedState.cpp \
    ../src/CircuitBreakerHalfOpenState.cpp \
    ../src/CircuitBreakerHealthPolicy.cpp \
    ../src/CircuitBreakerOpenState.cpp \
    ../src/CircuitBreakerState.cpp \
    ../src/TimeService.cpp \
    ../src/MockHealthPolicy.h ../src/MockHealthPolicy.cpp

noisecirkuittester_SOURCES = main.cpp $(common_sources)
noisecirkuittester_CXXFLAGS = $(AM_CXXFLAGS) -lnoisetest

TESTS = noisecirkuittester

