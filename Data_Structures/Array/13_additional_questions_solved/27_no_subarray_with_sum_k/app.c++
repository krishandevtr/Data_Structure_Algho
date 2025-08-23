#include <iostream>
#include <map>
#include <vector>
using namespace std;

// You are given an array of integers arr and an integer k. Write a function int optSol(const vector<int>& arr, int k) that counts the number of contiguous subarrays (subsequences of consecutive elements) whose sum equals k.

void bruteSol(const vector<int>& vec) {

}

/**
 * ! We gonna implement the prefix sum tech here
 * !  This will work on both positive and negative numbers
 */
int betterSol(const vector<int>& arr,int k)
{  
    map<int, int> mpp; // To store prefix sum frequencies
    mpp[0] = 1; // Handle case when prefix sum itself equals k
    int presum = 0, cnt = 0;

    for (int i = 0; i < arr.size(); i++) {
        presum += arr[i]; // Calculate prefix sum

        int remove = presum - k; // Check if (prefix sum - k) exists
        cnt += mpp[remove]; // Add the frequency of 'remove' to count

        mpp[presum]++; // Update the prefix sum frequency
    }

    return cnt;



}


//*1, 2, 3, 4, 1, 2}, k = 5

//* This will only work with pos 
int optSol(const vector<int>& arr, int k) {
    int j = 0, i = 0;
    int sum = 0;
    int count = 0;
    int n = arr.size();

    while (j < n) {
        // Expand the window by adding arr[j]
        sum += arr[j];

        // Shrink the window until sum <= k
        while (sum > k && i <= j) {
            sum -= arr[i];
            i++;
        }

        // Check if the current sum equals k
        if (sum == k) {
            count++;
        }

        // Move the end of the window forward
        j++;
    }
    return count;
}

