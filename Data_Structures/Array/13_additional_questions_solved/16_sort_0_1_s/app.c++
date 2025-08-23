#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * ! This is the question that asks you to sort the array consist of 0,1,2
 */
//?_____________________________brute_________________________
/**
 * ? In this brute we gonna sort the array using bubble sort or merge sort which will be bigO(nlog) and space complexity of BigO(1)
 */

//?____________________________Better solution __________________________
/**
 * ?Loop through the array take three variables if you saw a zero increment the one variable and similar for the other number 1 and 2
 * ? then you need to overwrite the array using a loop
 */
void sort( vector<int> &vec)
{
    int zeros = 0;
    int ones = 0;
    int twos = 0;
    for(int i =0; i<vec.size();i++){
        if(vec [ i] == 0){
            zeros++;
        }else if(vec[i]== 1){
            ones++;
        }else{
            twos++;
        }
    }
        for(int i = 0; i<zeros;i++)vec[i] = 0;
        for(int j = zeros; j<zeros+ones;j++) vec[j] = 1;
        for(int k = ones; k<vec.size();k++) vec[k] = 2;
}
//* This will use the t.c : 2n sc: 1
//?_____________________________Optimal solutions__________________
//* We gonna use the dutch national flag algorithm 

void dutchSolution(vector<int> &arr){
    int mid, high, low;
    mid = 0; low = 0; high = arr.size() - 1;
    
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if(arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[high], arr[mid]);
            high--;
        }
    }
};

//* This will be bigO(n)

/**
 * ! We gonna use the three pointer low , mid and high
 * ! There are three rules 
 * ! it states everything from o ... low - 1 will be 0 extreme left
 * ! it states everything from low... mid-1 will be 1
 * !  everything from high+1 ... n-1 will be  2 which is the extreme right
 * ! everything from mid... high will be  random numbers(0,1,2) in un sorted way
 */


int main()
{
    return 0;
}