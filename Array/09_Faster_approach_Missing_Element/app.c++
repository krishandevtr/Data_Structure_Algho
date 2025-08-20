#include <iostream>
#include <climits>  // For INT_MIN
using namespace std;

struct Array {
    int length;
    int size;
    int* pointer;

    // Default Constructor
    Array() : length(0), size(100) {
        pointer = new int[size];  // Default size is 100
    }

    // Parameterized Constructor
    Array(int length, int size) : length(length), size(size) {
        pointer = new int[size];  // Allocate array of given size
    }

    // Destructor to free allocated memory
    ~Array() {
        delete[] pointer;  // Free dynamically allocated memory
    }
};

void hashMissing(Array &arr) {
    int largestNum = INT_MIN;
    
    // Step 1: Find the largest number in arr
    for (int i = 0; i < arr.length; i++) {
        if (arr.pointer[i] > largestNum) {
            largestNum = arr.pointer[i];
        }
    }

    // Step 2: Initialize the hash array to store counts
    Array hash(largestNum + 1, largestNum + 1);  // Array to track presence of numbers
    for (int i = 0; i < largestNum + 1; i++) {
        hash.pointer[i] = 0;  // Initialize all to 0
    }

    // Step 3: Count the occurrences of each number in the hash table
    for (int i = 0; i < arr.length; i++) {
        if (arr.pointer[i] >= 0 && arr.pointer[i] <= largestNum) {
            hash.pointer[arr.pointer[i]]++;  // Increment the count at the index
        }
    }

    // Step 4: Find and print the missing numbers
    for (int i = 0; i < largestNum + 1; i++) {
        if (hash.pointer[i] == 0) {
            cout << "Missing number is: " << i << endl;
        }
    }
}

int main() {
    Array arr(5, 100);
    arr.pointer[0] = 0;
    arr.pointer[1] = 1;
    arr.pointer[2] = 3;
    arr.pointer[3] = 5;
    arr.pointer[4] = 6;

    // Find and print missing numbers
    hashMissing(arr);
    return 0;
}
