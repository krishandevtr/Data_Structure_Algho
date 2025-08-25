#include <iostream>
int countDigits(int digits, int divider = 10)
{
    digits = std::abs(digits);
    if (digits < divider)
        return 1;
    return 1 + countDigits(digits / 10);
}

int main(int argc, char const *argv[])
{
    int results = countDigits(12345);
    std::cout << "Result: " << results << std::endl;
    return 0;
}
