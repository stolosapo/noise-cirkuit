AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

bin_PROGRAMS = noisecirkuit

mainincludedir = $(includedir)/noisecirkuit
maininclude_HEADERS = \
    CircuitBreaker.h \
    MockHealthPolicy.h

common_sources = \
    CircuitBreaker.cpp \
    CircuitBreakerClosedState.cpp \
    CircuitBreakerHalfOpenState.cpp \
    CircuitBreakerHealthPolicy.cpp \
    CircuitBreakerOpenState.cpp \
    CircuitBreakerState.cpp \
    TimeService.cpp \
    MockHealthPolicy.cpp

noisecirkuit_SOURCES = main.cpp $(common_sources)
noisecirkuit_LDADD = libnoisecirkuit.la
noisecirkuit_CXXFLAGS = $(AM_CXXFLAGS)

lib_LTLIBRARIES = libnoisecirkuit.la
libnoisecirkuit_la_LDFLAGS = -version-info 1:1:0 -pthread
libnoisecirkuit_la_CXXFLAGS = $(AM_CXXFLAGS) -pthread
libnoisecirkuit_la_SOURCES = $(common_sources)

TESTS = noisecirkuit