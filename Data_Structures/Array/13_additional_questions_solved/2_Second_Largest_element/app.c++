#include<iostream>
using namespace std;
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



//!Initial solution is simple we can use any sorting with n log n and , we not return the n-2 pos ad the result 🤦‍♀️
//*Edge case what if the largest number is repeated for 2 time
//* we are sure that last index is the largest element,store it in an variable
//* But we can start from the n-2 (for int i = arr.pointer[arr.length-2]; i>=0;i-- )
//* {if arr.pointer[i]!= largestNum} return arr.pointer[i] break;
//* in this way we can ensure that the number is not duplicated
//?This is the worst that can take to O(n) because what if the number is not in here , what if the smax is in 1st index



//! Better solution (my solution )

int getSecondLargest(Array &arr){
    int max , min;
    max = arr.pointer[0];
    min = -1;
    for(int  i =1; i<arr.length; i++){
        if(arr.pointer[i] >max){
            max = arr.pointer [i];
        }
    }
    for(int i = 1; i<arr.length;i++){
        if(arr.pointer[i]<max && arr.pointer[i]>min) min = arr.pointer[i];
    }
    return min;
}




int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
