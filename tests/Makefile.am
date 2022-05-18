AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

bin_PROGRAMS = noisecirkuittester

common_sources = \
    MainTestSuite.h MainTestSuite.cpp \
    CircuitBreakerTest.h CircuitBreakerTest.cpp

noisecirkuittester_SOURCES = main.cpp $(common_sources)
noisecirkuittester_CXXFLAGS = $(AM_CXXFLAGS) -lnoisetest

TESTS = noisecirkuittester

