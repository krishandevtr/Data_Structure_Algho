#include<iostream>
using namespace std;
#include <algorithm> 
struct Array {
    int length;
    int size;
    int* pointer;

    // Default Constructor
    Array() : length(0), size(100) {
        pointer = new int[size]; // Default size is 100
    }

    // Parameterized Constructor
    Array(int length, int size) : length(length), size(size) {
        pointer = new int[size]; // Allocate array of given size
    }

    // Destructor to free allocated memory
    ~Array() {
        delete[] pointer; // Free dynamically allocated memory
    }
};

Array leftRotate(Array &arr,int k ){
    if( k == 0 ) return arr;
    while(k--){
        int first = arr.pointer[0]; 
    for(int i =0; i<arr.length-1;i++){
        arr.pointer[i] = arr.pointer[i+1];
    }
    arr.pointer[arr.length-1] = first;
    }
}

//? Optimal solution for the above question 
// given an array [1,2,3,4,5,6,7,] 
//After rotation it will be [4,5,6,7,1,2,3]
// SOLUTION - Break that array into two halfs one half is til the ,number of rotation to be taken here it is 2
//second half will be after the d that is d+1 
// first half = [1,2,3,]-> reverse -> [3,2,1,]
//second half = [4,5,6,7]-> reverse -> [7,6,5,4]
//Combination of both -> [3,2,1,7,6,5,4] now reverse the whole array 
// final result -> //?[4,5,6,7,1,2,3,]

Array rotate(Array& arr, int k) {
    k = k % arr.length; // Handle rotations larger than array size
    if (k == 0) return arr; // No rotation needed
    std::reverse(arr.pointer, arr.pointer + k); // Reverse first k elements
    std::reverse(arr.pointer + k, arr.pointer + arr.length); // Reverse remaining elements
    std::reverse(arr.pointer, arr.pointer + arr.length); // Reverse the entire array

    return arr; // Return the rotated array
}

//BigO(N+N)


int main(int argc, char const *argv[])
{
    
    
    return 0;
}
