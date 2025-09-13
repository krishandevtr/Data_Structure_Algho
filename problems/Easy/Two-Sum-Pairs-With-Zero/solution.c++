#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

// Given an integer array arr
// return all the unique pairs [arr[i], arr[j]] such that i != j and arr[i] + arr[j] == 0.
// Note: The pairs must be returned in sorted order
// The solution array should also be sorted, and the answer must not contain any duplicate pairs.
//* Constraints:
// 3 <= arr.size <= 10^5
// -105 <= arr[i] <= 10^5

//! Below algorithm solves this problem in time:  O(n^2) and space : O(n2)
//! we need to somehow eliminate the inner and we avoid copying arr into vector

std::vector<std::vector<int>> getPairBrute(std::vector<int> &arr)
{
    std::set<std::vector<int>> uniquePairs;

    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr[i] + arr[j] == 0 && arr[i] != arr[j])
            {
                std::vector<int> res = {arr[i], arr[j]};
                std::sort(res.begin(), res.end());
                uniquePairs.insert(res);
            }
        }
    }

    // Convert set back to vector of vectors
    std::vector<std::vector<int>> result(uniquePairs.begin(), uniquePairs.end());
    return result;
}





//  This solution is pretty efficient when comparing the above one , 
//  TIme : O(n);
//  space: o(n); -> storing the result


std::vector<std::vector<int>> getPair(std::vector<int> &arr) {
    std::sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    std::vector<std::vector<int>> result;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == 0) {
            result.push_back({arr[left], arr[right]});
            
            int leftVal = arr[left], rightVal = arr[right];
            while (left < right && arr[left] == leftVal) ++left;
            while (left < right && arr[right] == rightVal) --right;

        } else if (sum < 0) {
            ++left;
        } else {
            --right;
        }
    }
    return result;
}


int main(int argc, char const *argv[])
{
    std::vector<int> arr = {6, 1, 8, 0, 4, -9, -1, -10, -6, -5};
    std::vector<std::vector<int>> result = getPairBrute(arr);
    return 0;
}
