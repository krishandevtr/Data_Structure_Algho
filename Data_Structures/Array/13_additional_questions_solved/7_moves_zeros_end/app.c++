#include <iostream>
#include <utility>
#include<algorithm>
using namespace std;

struct Array
{
    int length;
    int size;
    int *pointer;

    // Default Constructor
    Array() : length(0), size(100)
    {
        pointer = new int[size]; // Default size is 100
    }

    // Parameterized Constructor
    Array(int length, int size) : length(length), size(size)
    {
        pointer = new int[size]; // Allocate array of given size
    }

    // Destructor to free allocated memory
    ~Array()
    {
        delete[] pointer; // Free dynamically allocated memory
    }
};

//! Initial code that is brute force with additional space

Array moveZeros(Array &arr){
    int k = 0;
    int size = arr.length;
    Array store;
    store.pointer = new int [size];

    for(int i =0; i<arr.length; i++){
        if(arr.pointer[i] != 0){
            store.pointer[k++] = arr.pointer[i];
        }
    }//BigO(n)

    for(int j = 0;j<k; j++ ){
        arr.pointer[j] = store.pointer[j];
    }
    for(int n = k;n<arr.length; n++) arr.pointer[n] = 0;
    

    return arr;
}


/**
 * ! Optimal  code (my solution)//optimal one
 * The approach involves using two pointers: 'left' starting from the beginning and 'right' from the end.
 * Increment 'left' until a zero is found and decrement 'right' until a non-zero is found.
 * If 'left' does not find a zero, it increments.
 * If 'right' does not find a non-zero, it decrements.
 * The main condition is that 'left' should be less than 'right'.
 * The entry point inside the while loop is when (arr.pointer[left] == 0 && arr.pointer[right] != 0).
 *
 */
Array moveZeros(Array &arr)
{
    int left = 0;
    int right = arr.length - 1;

    while (left < right)
    {
        if (arr.pointer[left] == 0 && arr.pointer[right] != 0)
        {
            swap(arr.pointer[left], arr.pointer[right]);
            left++;
            right--;
        }
        else if (arr.pointer[left] != 0)
        {
            left++;
        }
        else if (arr.pointer[right] == 0)
        {
            right--;
        }
    }
    int firstZeroIndex = arr.length;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.pointer[i] == 0)
        {
            firstZeroIndex = i;
            break;
        }
    }
    sort(arr.pointer ,arr.pointer+firstZeroIndex);
    return arr; // Return the modified array
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
