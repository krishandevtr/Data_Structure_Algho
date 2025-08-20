#include <iostream>
#include <vector>
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


//we need to find the missing numbers am use the hashing not bothering the space complexity 
// do a linear search and then on every iteration go the index of that number on the hash then increment that 
// if the number is the 10 in the hash go to the index 10 and ++



//Finally loop through the array of the hash then if the value is 10 then return the index 

//? This is algorithm is to spot one missing number 
//! this is not  for fiding multiple missing numbers

int  missingNumber(const vector<int>& vec) {
    if (vec.empty()) return -1; // Handle empty input
    if(vec.back() == 0) return -1 ;

Array hash;
hash.pointer = new int [ vec.back()+1];
for(int s = 0; s<hash.length ; s++){
    hash.pointer[s]=0;
}
for(int i = 0;i<vec.size(); i++){
    hash.pointer[vec[i]]++;
}//Big0(n)

for(int j = 0; j<hash.length;j++){
    if(hash.pointer[j] == 0) return j;
}//o(n)


//* we have another method to solve this question that is to find the sum of the given number using the equation then 
//* substract the value from the total sum that number is the that we got from the result is our result 


}
int main() {
    return 0;
}
