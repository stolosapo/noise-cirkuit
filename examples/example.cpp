#include <iostream>

#include <noisecirkuit/CircuitBreaker.h>

using namespace std;

class ExampleHealthPolicy: public NoiseCirkuit::CircuitBreakerHealthPolicy
{
    public:
        ExampleHealthPolicy()
        {

        }

        virtual ~ExampleHealthPolicy()
        {

        }

        virtual bool isHealthy()
        {
            // Add here some logic of what makes our system healthy
            // for now lets say that our system is healthy
            return true;
        }
};

int main(int argc, char* argv[])
{
    cout << "Testing NoiseCirkuit" << endl;

    ExampleHealthPolicy health;
    NoiseCirkuit::CircuitBreaker cb(&health);
    cb.initialize();

    cout << "Request is allowed: " << cb.isRequestAllowed() << endl;
}
