//! The question is we need to check whether the array is sorted , and rotated;
//? if sorted then true or false

//* [1,2,3,4,5,6]->true  [3,4,5,1,2,]-> true because the array is rotated ; [2,1,3,4] array is not sorted or rotated


//* if the array is rotated their will be one sudden break only one time , if

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


bool isSorted(Array &arr){
    int count = 0;
    for(int i =0; i<arr.length-1;i++){
        if(arr.pointer[i]>arr.pointer[i+1]) count ++;
    }

    if(arr.pointer[arr.length]<arr.pointer[0]) count++;

    return count<=1;
}

int main(int argc, char const *argv[])
{
    
    
    return 0;
}

