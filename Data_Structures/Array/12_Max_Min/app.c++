
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



void findMinAndMax(Array const &arr){
    int min , max = arr.pointer[0];
    for(int i=0; i<arr.length;i++){
        if(arr.pointer[i] >max ){
            max = arr.pointer[i];
        }else if(arr.pointer[i] < min){
            min = arr.pointer[i];
        }else{
            
        }
    }
}

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
