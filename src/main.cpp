#include <iostream>

#include "CircuitBreaker.h"
#include "MockHealthPolicy.h"

using namespace std;
using namespace NoiseCirkuit;

int main(int argc, char* argv[])
{
    // Create first a Health Policy instance
    MockHealthPolicy healthy(true, 0.02, 3);

    // Create a new CircuitBreaker that checks this policy
    CircuitBreaker cb(&healthy);
    cb.initialize();

    // and use it..
    bool allowed = cb.isRequestAllowed();

    cout << "NoiseCirkuit Library" << endl << endl;
    cout << "Now: " << timeRawNow() << endl;
    cout << "Allowed: " << allowed << endl;
    cout << endl;
    cout << "Bye Bye.." << endl;
}
