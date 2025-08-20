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

//? The inital strategy will be sorting and returning the index of arr.pointer[arr.length-1],this is lead to the nlogn due to the sorting 



//? My optimal solution brute  force strategy
 int larNum(Array & arr){
    int max = arr.pointer[0];
    for(int i =1; i<arr.length; i++){
        if(arr.pointer[i]>max) max = arr.pointer[i];
    }
    return max;
 }
// ! Linear 
// ! O(n) we are checking each is number is larger or not 





int main(int argc, char const *argv[])
{
    
    
    return 0;
}
