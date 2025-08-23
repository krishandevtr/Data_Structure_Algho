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


//? Inefficient Because the time is O(n^2)
void sum_K(Array const &arr,const int k){
    int j =0;
    for(int i =0; i<arr.length-1; i++){
        for(j=i+1;j<arr.length;j++ ){
            if(arr.pointer[i] + arr.pointer[j] == k){
                cout<<"pair to get the "<<k<<"are"<<arr.pointer[i]<<"and"<<arr.pointer[j]<<endl;
            }
        }
    }
}

//?Above stuff with o(n)
void k_sum(Array const &arr,const int k){
    int i = 0;
    Array hash; 
    //Scan through the array then if current index 
    for(i; i<arr.length; i++){
        if(hash.pointer[k-arr.pointer[i]]!=0){
            cout<<"Pair got "<<hash.pointer[arr.pointer[i]]<<" and "<<arr.pointer[i]<<endl;
        }
        hash.pointer[arr.pointer[i]]++;
    }

}

//?finding the sum of the pairs in the sorted array
void kSum(Array &arr, const int k) {
    int i = 0;                // Start pointer
    int j = arr.length - 1;   // End pointer

    while (i < j) {           // Continue while pointers don't cross
        int sum = arr.pointer[i] + arr.pointer[j];

        if (sum == k) {
            cout << "Pair found: " << arr.pointer[i] << " and " << arr.pointer[j] << endl;
            i++;              // Move to the next possible pair
            j--;
        } else if (sum < k) {
            i++;              // Increase the sum by moving `i` to the right
        } else {
            j--;              // Decrease the sum by moving `j` to the left
        }
    }
}//Order(n) single traversal 



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
