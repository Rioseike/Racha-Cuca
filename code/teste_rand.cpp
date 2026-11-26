#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    srand(42);
    for (int i = 0; i < 5; i++) {
        cout << rand() % 4 << endl;
    }
    return 0;
}