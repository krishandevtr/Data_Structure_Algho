#include <iostream>
#include <vector>

std::vector<int> plusOneOptimal(std::vector<int> &digits)
{
    int n = digits.size();

    // Start from the last digit
    for (int i = n - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    //  case with 9
    std::vector<int> newDigits(n + 1, 0);
    newDigits[0] = 1;
    return newDigits;
}

int main(int argc, char const *argv[])
{

    std::vector<int> arr = {4, 3, 2, 1};
    std::vector<int> result = plusOneOptimal(arr);

    return 0;
}
