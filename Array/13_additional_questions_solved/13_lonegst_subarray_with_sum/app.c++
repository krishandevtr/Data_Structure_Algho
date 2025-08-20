//! Question is , you are given a array with a value you need to find out the longest sub array that gives you the value(k);
#include <iostream>
#include <vector>
#include <map>
using namespace std;

//* ___________________________________Initial solution___________________________________________
int subArray(const vector<int> &arr, int k)
{
    int sum = 0;
    int result;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                result = j - i + 1;
            }
        }
        return result;
    }
}
/**
 * ! initial solution(brute force) Tc: O(n*n)
 * ! SC: O(1) does not use any extra space
 */

//*_______________________________________Better solution________________________________________
//! we gonna play with the hash map or  map
//? This is similar like the js object literal
//? Accessing a element have an time complexity of O(1)

//*_____________________How we gonna execute the plan_____________________________________________
//! Assume that we have an array of with values of [1,2,3,1,1,1,1,4,2,3],k = 3
//! initialize a variable called sum with value of 0, And a length variable to hold the length
//?  first element is one so gonna add the one to the sum  but this is not our k
//! Note the sum and the index in the map first value will be (sum, index) so it will be 1 ,0
//? second element is 2 add two to the sum we got 3 which is three  then store the stuff into the hashmap 3,1, store the length as 2 because the first two elements
//! Third element which is three then add three to the sum which is six
//* Here we gonna do some reverse mathematics
//! We got at sum of three and now the sum is 6 then we say that x-k X (x which is the sum ) is the next sub array because the 6-3 is 3
//! store the sum and len but the length is 1 which is not greater than the sum
//? Next element is the 1, Add 7 to the sum we will get sum as 7 then previous sum has to be 4 but didnot got a sum 4 yet so add the index and the sum to be map
//?Next element is 1 , sum is 8 then the possible sum are 5 and three
//! But we didnot got the sum as 5 yet so store the sum and the index
//? next is 1 sum is 9 possible values of the sum are 6 and 3
//! Yes we have a sum of 6 so the index after that till the current index will a new sub array add the sum and the store the sum and the index in the map,Update the length
//? Continue the steps
//* Note that in the question the data type of the k will be long long

int hashSolution(vector<int> arr, int k)
{ // Note that am using the int instead of the long long
    map<int, int> sumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            if (maxLen < i + 1)
            {
                maxLen = i + 1;
            } //*-- check whether the sum and the k is same if same then update the maxLen
            int rem = sum - k;
            if (sumMap.find(rem) != sumMap.end())
            {
                int len = i - sumMap[rem];
                if (maxLen < len)
                {
                    maxLen = len;
                }
            }
        } // * -- Check whether the sum -k exist that means if the sum is 7 we need to know ensure that the 4 is their, we know that some sub array have an sum as 4 then after that index til the current index is our new subarray so how to do that take the difference and store it has new len

        if (sumMap.find(sum) == sumMap.end())
        {
            sumMap[sum] = i;
        }// * if difference not their and the sum is not their then we can add the sum and the index to the map
    }
    return maxLen;
}


/**
 *! Checking whether I understood or not  
 *
 */

int BetterSolution(vector <int> arr, int k){
    int maxLen;
    map<int,int> preSum;
    int sum = 0;

    for(int  i =0; i<arr.size(); i++){
        sum +=arr[i];
        if(sum == k){
            if(maxLen<i+1){
                maxLen = i+1;
            }
        }
        int rem = sum -k;
        if(preSum.find(rem)!=preSum.end()){
            int len = i-preSum[rem];//after the prefix till the current index;
            if(maxLen<len){
                maxLen = len;
            }
        }

        if(preSum.find(sum)!= preSum.end()){
            preSum[sum] = i;
        }   
    }
    return maxLen;
}
//?Tc: BigO(N * logN) if we are using the map else if we are using the un ordered map then it will be BigO(N*1)
//? If we use the unordered map then if there collision then the searching will end up the n then the TC: will be quadratic
//?SC:bigO(N) 
//?The above stuff will work on the positives and the zeros then we will go for the optimal one 




//*_____________________________________optimal solution___________________________________________/

//! Two pointer and tim 
//! sliding window approach

/**
 * *Sliding Window Approach:
 * The idea behind the sliding window technique is to maintain a window (a contiguous subarray) and adjust the window size dynamically based on the sum of its elements.
 */
int optimalSolution(vector<int> arr, int k) {
    int right = 0, left = 0, len = 0, sum = 0;
    while (right < arr.size()) {
        // Increment right pointer and add the value to sum
        sum += arr[right];
        // Shrink the window from the left if sum is less than k
        while (left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }
        // Check if the current window sum is equal to k
        if (sum == k) {
            len = max(len, right - left + 1);
        }
        // Move the right pointer
        right++;
    }
    return len;
}

//! Tc: bigO(2n)


























int main()
{
    return 0;
}