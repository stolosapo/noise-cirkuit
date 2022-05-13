# noisecirkuit

A simple C++ library that implements the Circuit Breaker pattern.

### Prepare compilation
```bash
./autogen.sh
```

### Installation
```bash
./configure
make
sudo make install
sudo ldconfig /usr/local/lib
```

### Uninstallation
```bash
sudo make uninstall
```

### Run
```bash
noisecirkuit
```

## Clean all untracked files
```bash
git clean -xdf
```

### Use Library
If everything installed fine then pass `-lnoisecirkuit` parameter in linker, when build your application.
Then use it in your app like this:

```c++
#include <iostream>

#include <noisecirkuit/MockHealthPolicy.h>
#include <noisecirkuit/CircuitBreaker.h>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "Testing NoiseCirkuit" << endl;
    
    NoiseCirkuit::MockHealthPolicy health(false);
    NoiseCirkuit::CircuitBreaker cb(&health);
    cb.initialize();

    cout << "Testing NoiseCirkuit, request is allowed: " << cb.isRequestAllowed() << endl;
}
```
