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


void isDuplicated(Array &arr) {
    int lastDup = 0; // Keeps track of the last duplicate element
    for(int i = 0; i<arr.length-1; i++){
        if(arr.pointer[i] == arr.pointer[i+1] && arr.pointer[i]!=lastDup){
            cout<<arr.pointer[i]<<" is duplicated"<<endl;
            lastDup = arr.pointer[i];
        }
    }
}
//!Count the number of repeated elements and the count
void countDuplicates(Array &arr){
    int lastDup = 0;
    int j = 0;
    for(int i =0; i<arr.length - 1;i ++){
        if(arr.pointer[i] == arr.pointer[i+1]){
            j = i+1;
            while(arr.pointer[i] == arr.pointer[j] )j++;
            cout<<arr.pointer[i]<<" is duplicated "<<j-i<<" times"<<endl;
            i = j-1;
        } 
    }
}
//! FInd the array duplicates using the Hasing tech
void hasingDup(Array &arr){
    Array hash;
    hash.pointer = new int [arr.pointer[arr.length-1]+1];
    for(int i = 0; i<hash.length ; i++){
        hash.pointer[i] = 0;
    } //O(n)
    for(int i = 0; i<hash.length; i++){
        hash.pointer[arr.pointer[i]]++;
    }//O(n)
    for(int i = 0; i<hash.length; i++){
        if(hash.pointer[i]>1) cout<<i<<" is duplicated "<<hash.pointer[i]<<" times"<<endl;
    }//O(n)
}
// n+n+n = 3n
//?O(n);


//! Finding the duplicated on the unsorted array

void findDup(Array & arr){
    for(int i =0 ; i<arr.length-1; i++){
        if(arr.pointer[i] != - 1){
            int count = 1;
        for(int j = i+1; j<arr.length;j++){
            if(arr.pointer[i] == arr.pointer[j]){
                count++;
                arr.pointer[j] = -1;
            }
        }
        if(count>1)cout<<arr.pointer[i]<<" is duplicated "<<count<<" times"<<endl;
        }
    }

// O(n^2)
//Because  the outer loop will continue till the end of the array
// When we calculate how many time initially we will compare the first element with rest of the all elements then second element with all elements
// n-1 + n-2 +n-3 + n-4 + n-5 + n-6 + n-7 + n-8 + n-9 + n-10 + n-11 + n-12 + n-13 + n-14 + n-15 + n-16 + n-17 + n-18 + n-19 + n-20
// n*(n+1) / 2 = n^2
}

//? Finding the duplicates in the unsorted array using the bitsset or the hashTable
void Duplicated(Array &arr){
    Array hash;//Find the largest elements then create a array of size with the largest element +1

    for(int i = 0; i <arr.length; i++){
        hash.pointer[arr.pointer[i]]++;
    }

    for(int i = 0; i <hash.length; i++){
        if(hash.pointer[i]>1) cout<<i<<" is duplicated "<<hash.pointer[i]<<" times"<<endl;
    }

}


int main(int argc, char const *argv[])
{

    
    return 0;
}
