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


void leftRotate(Array &arr){
    int  rot = arr.pointer[0];
    for(int i=0; i<arr.length-1;i++){
        arr.pointer[i] = arr.pointer[i+1];
    }
    arr.pointer[arr.length-1] = rot;
}
//? BigO(n) traversing the whole array in one 
//? No extra space is used 






int main(int argc, char const *argv[])
{
    
    
    return 0;
}
