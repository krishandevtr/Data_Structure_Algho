#include <iostream>
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



//!  Union of Two Arrays
    //Assume that the array is sorted and the have valid length 
    //compare each element in the arr1 ,arr2 then select smallest element then copy to a new array
    //If the element is equal then we use simply copy the element into new array and increment the value of the iterators
    //* TIme complexity is (n)
Array Union(Array const &arr1,Array const arr2){
    int i , j , k;
    i = j = k = 0;
    Array store;
    store.size = arr1.length + arr2.length;
    store.pointer = new int[arr1.length + arr2.length];
    while(i<arr1.length && j<arr2.length){
        if(arr1.pointer[i]<arr2.pointer[j]){
            store.pointer[k++] = arr1.pointer[i];
            i++;
        }else if (arr1.pointer[i]>arr2.pointer[j])
        {
            store.pointer[k++] = arr2.pointer[j];
            j++;
        }else{
            store.pointer[k++] = arr1.pointer[i];
            j++;
            i++;
        }

    }
    for(;i<arr1.length;i++){
        store.pointer[k] = arr1.pointer[i];
        k++;
    }
        for(;j<arr2.length;j++){
        store.pointer[k] = arr2.pointer[j];
        k++;
    }
    return store;
}


Array Reverse(Array  &array){
    //using brute force with 2 pointer 
    int i , j;
    i = 0;
    j = array.length -1 ;
    int temp =0;
    while(i<j){
        temp = array.pointer[i];
        array.pointer[i] = array.pointer[j];
        array.pointer[j] = temp;
        i++;
        j--;
    }
    return array;
}




int main(){

}