#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <cstdlib> // rand
#include <ctime>
// Brute force solution
std::vector<int> twoSumBrute(const std::vector<int> &arr, int k)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = i + 1; j < arr.size(); ++j)
        { // j = i+1
            if (arr[i] + arr[j] == k)
            {
                return {i + 1, j + 1}; // return immediately
            }
        }
    }
    return {}; // empty if not found
}

std::vector<int> twoSumHash(const std::vector<int> &arr, int k)
{
    std::unordered_map<int, int> hash;
    std::vector<int> result;

    for (int i = 0; i < arr.size(); ++i)
    {
        int compliment = k - arr[i];
        if (hash.find(compliment) != hash.end())
        {
            return {hash[compliment] + 1, i + 1};
        };
        hash[arr[i]] = i;
    }
}

int main(int argc, char const *argv[])
{
    std::vector arr = {
        1,
        3,
        5,
        6,
        7,
        8,
    };
    std::vector<int> result = twoSumHash(arr, 9);
    return 0;
}
