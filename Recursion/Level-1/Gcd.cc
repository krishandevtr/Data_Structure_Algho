#include <iostream>
#include <algorithm>

int Gcd(int num1, int num2, int bound)
{
    if (bound == 1)
        return 1;

    if (num1 % bound == 0 && num2 % bound == 0)
        return bound;

    return Gcd(num1, num2, bound - 1);
}

int main(int argc, char const *argv[])
{

    int result = Gcd(48, 18, 9);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

// Better Solution will be Euclidean Algorithmint Gcd(int a, int b)
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
