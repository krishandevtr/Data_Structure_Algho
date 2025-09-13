#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

//  Brute solution O(n);
bool containsDuplicatesBrute(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr[i] == arr[j])
            {
                return true;
            }
        }
    }
    return false;
}
// Brute Solution Anaylyzis
// ! Time Complexity: O(n²)
// ! Space Complexity: O(1)

bool containsDuplicatesOptimal(std::vector<int> &arr)
{
    std::unordered_map<int, int> um;
    for (auto &el : arr)
    {
        if (um.find(el) != um.end())
        {
            return true;
        }
        um[el] = 1;
    };
    return false;
}

//! worst case ->  Time : O (n), Space: O(n)
//! Best case ->   Time: O(1) , space: O(n)

bool containsDuplicates(std::vector<int> &arr) {
    std::sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] == arr[i-1])
            return true;
    }
    return false;
}

//! Worst case:
//! Time Complexity : O(n log n) + O(n) ≈ O(n log n) 
//! Space Complexity: O(1)  (in-place sort, ignoring recursion stack)


int main(int argc, char const *argv[])
{
    std::vector<int> arr = {1, 2, 3, 4};
    bool result = containsDuplicatesOptimal(arr);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
