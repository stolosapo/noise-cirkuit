#!/bin/sh

g++ -g -c -o main.o main.cpp
g++ -g -c -o MainTestSuite.o MainTestSuite.cpp
g++ -g -c -o CircuitBreakerTest.o CircuitBreakerTest.cpp
g++ -g -c -o CircuitBreakerClosedStateTest.o CircuitBreakerClosedStateTest.cpp
g++ -g -c -o CircuitBreakerOpenStateTest.o CircuitBreakerOpenStateTest.cpp
g++ -g -c -o CircuitBreakerHalfOpenStateTest.o CircuitBreakerHalfOpenStateTest.cpp
g++ -g -c -o CircuitBreaker.o ../src/CircuitBreaker.cpp
g++ -g -c -o CircuitBreakerClosedState.o ../src/CircuitBreakerClosedState.cpp
g++ -g -c -o CircuitBreakerHalfOpenState.o ../src/CircuitBreakerHalfOpenState.cpp
g++ -g -c -o CircuitBreakerHealthPolicy.o ../src/CircuitBreakerHealthPolicy.cpp
g++ -g -c -o CircuitBreakerOpenState.o ../src/CircuitBreakerOpenState.cpp
g++ -g -c -o CircuitBreakerState.o ../src/CircuitBreakerState.cpp
g++ -g -c -o TimeService.o ../src/TimeService.cpp
g++ -g -c -o MockHealthPolicy.o ../src/MockHealthPolicy.cpp

g++ main.o \
    MainTestSuite.o \
    CircuitBreakerTest.o \
    CircuitBreakerClosedStateTest.o \
    CircuitBreakerOpenStateTest.o \
    CircuitBreakerHalfOpenStateTest.o \
    CircuitBreaker.o \
    CircuitBreakerClosedState.o \
    CircuitBreakerHalfOpenState.o \
    CircuitBreakerHealthPolicy.o \
    CircuitBreakerOpenState.o \
    CircuitBreakerState.o \
    TimeService.o \
    MockHealthPolicy.o \
    -o tester -lnoisetest

./tester