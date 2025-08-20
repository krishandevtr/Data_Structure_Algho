#include <iostream>
#include <vector>
using namespace std;

//? Question says that you need to return  max sum of the sub array

//? __________________________________ brute force and Better sol____________________________
/**
 * ! WE can iterate through the array
 * ! store the sum in a variable
 * ! on Every iteration  check whether the sum exceeds the previous sum
 * ! At last return the sum variable
 * ! Important stuff you the 2 pointer to iterate one for locking the variable ,other for looping
 */

//*This was brute force that i gave but this was better solution , the real brute force with three loop which the tutor provided😂
//*That gonna tate n2 *~n in the worst case
int  bruteForce(const vector<int> &arr)
{
    int sum = 0;
    int result = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
        }
        if (sum > result)
        {
            result = sum;
        }
        
    }
    return result;
}
//? This stuff will take bigO(n^2) because we gonna loop through the array in n times 

//? __________________________________ Optimal Sol____________________________

//* Kadane's algorithm 
// ?We will run a loop(say i) to iterate the given array.
// ?Now, while iterating we will add the elements to the sum variable and consider the maximum one.
// ?If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer.
int optimalSol(const vector<int>& arr) {
   int max = INT_MIN;
   int sum =0;
   for(int i= 0; i<arr.size(); i++){
        sum += arr[i];
        if(sum<0){
            sum = 0;
        }
        if(sum > max){
            max = sum ; 
        }
   }
   return max < 0 ? max : 0;
}


