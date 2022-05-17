AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

bin_PROGRAMS = noisecirkuittester

mainincludedir = $(includedir)/noisecirkuittester
maininclude_HEADERS = \
    MainTestSuite.h \
    CircuitBreakerTest.h

common_sources = \
    MainTestSuite.cpp \
    CircuitBreakerTest.cpp

noisecirkuittester_SOURCES = main.cpp $(common_sources)
noisecirkuittester_CXXFLAGS = $(AM_CXXFLAGS) -lnoisetest

TESTS = noisecirkuittester
