#include <iostream>
using namespace std;

int factorial(int value) {
    static int result = 1; 
    if (value == 1) return result;
    result *= value;
    return factorial(value - 1);
}

int main() {
    cout << "Factorial of 5: " << factorial(5) << endl; 
    return 0;
}
