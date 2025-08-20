
//? next_permutation : find next lexicographically greater permutation
#include <iostream>
#include <vector>
#include <algorithm>
//!What is permutation 
//* Number of ways to arrange a given set of numbers [1,2]-> 2,1, 1,2
using namespace std;
//? Before getting into problem
/**
 * ! Steps
 * ! Generate all posble permutation 
 * ! Do a linear search then spot the given array 
 * ! If the match found then return the next set 
 * ! If the given array is the last sol then return the first set
 * ! We can use the recursion 
 */
//* But this algorithm is so inefficient because it will take n! * n time  which is extremely higher order

//* ________________Optimal sol__________________
/**
 * ! Their is a in built func in the stl to use when u say their is iin built fun then the intervier will ask you to implement the stuff
 * !
 */
void generateNext(const vector<int>& vec) {
    const vector<int> temp = vec;
      if (std::next_permutation(temp.begin(), temp.end())) {
        // Print the next permutation
        std::cout << "Next permutation: ";
        for (int num : temp) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } else {
        // If no next permutation exists, indicate it
        std::cout << "No next permutation exists. The sequence is in descending order." << std::endl;
    }
}
//*__________________________Implementation_________________________________

vector<int> optimalSol(std::vector<int>& arr) {
    int n = arr.size();
    int i;

    // Step 1: Find the first index `i` from the end such that arr[i] < arr[i + 1]
    for (i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            break;
        }
    }

    // If no such index exists, the permutation is the largest. Reverse the array to get the smallest permutation.
    if (i < 0) {
        std::reverse(arr.begin(), arr.end());
    } else {
        // Step 2: Find the first index `j` from the end such that arr[j] > arr[i]
        for (int j = n - 1; j > i; j--) {
            if (arr[j] > arr[i]) {
                // Step 3: Swap arr[i] and arr[j]
                std::swap(arr[i], arr[j]);
                break;
            }
        }

        // Step 4: Reverse the sequence from arr[i + 1] to the end to get the next permutation
        std::reverse(arr.begin() + i + 1, arr.end());
    }
    return arr;
}