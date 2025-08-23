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


struct  Number 
{
    int num;
};



//In the natural numbers
int spotOneMissingNum(Array &arr) {
    int actualSum = 0;
    int sum = 0;
    
    // Calculate the expected sum of the first n natural numbers, where n = last number in the array
    actualSum = (arr.pointer[arr.length - 1] * (arr.pointer[arr.length - 1] + 1)) / 2;
    
    // Calculate the sum of elements in the array
    for (int i = 0; i < arr.length - 1; i++) {
        sum += arr.pointer[i];
    }
    
    // The missing number is the difference between the expected sum and the sum of the array
    return actualSum - sum;
}

   Number  SpotAndThrow(Array & arr){
    ///Assume that their is one space in the array to store
    int diff = arr.pointer[0] -1 ;
    for(int i = 0 ; i < arr.length; i ++){
        if(arr.pointer[i] = diff ){
            Number num ;
            num .num = arr.pointer[i];
            return  num ;

        }
    }
 
}
//returning a object of array , User can use a loop on object.pointer to access all missing numbers 
Array MissingMulElements(Array &arr1){
    Array arr;
    int k = 0;
    int j;
    int diff;
    diff = arr.pointer[0] - 0;
    for (int  i = 0; i < arr1.length -1; i++){
        if(arr1.pointer[i]-i!=diff){
            j = arr.pointer[i] - diff;
            while(j<arr.pointer[i]){
                int i = 0;
                arr.pointer[i] = j;
                j+=diff; 

            }
        }
    }
    return arr;

}


int main(){
    


    return 0;
}