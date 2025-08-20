#include<iostream>
#include<set>
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

//

int  remDup(Array &arr){
   set<int>set ;
   for(int i =0; i<arr.length;i++){
    set.insert(arr.pointer[i]);
   }
   int k =set.size();
   int j = 0;
    for(int x:set){
        arr.pointer[j++] = x;
    }
    return k;
}
//?BigO(nlogn)+O(n) , ts:O(n) we are using additional set
//[1,1,2,2,3,3,3,4,4]
int removeDuplicates(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}
//? This is BigO(n); and ts:O(1)
int main(int argc, char const *argv[])
{
    
    
    return 0;
}
