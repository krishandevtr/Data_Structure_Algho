#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>


using namespace std;

//?_________________Brute Sol_______________________________
//*Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.
//* [,102,4,100,1,101,3,2,1,1];
//*Answer will be [1,2,3,4];-. return 4; length is 4

bool exists(const vector<int> &arr, int el)
{
    for (int num : arr)
    {
        if (num == el)
            return true;
    }
    return false;
}
// Brute force solution
int longestConsecutiveSequence(const vector<int> &arr)
{
    int longest = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int currentElement = arr[i];
        int count = 1;
        // Check for all consecutive elements
        while (exists(arr, currentElement + 1))
        {
            currentElement++;
            count++;
        }
        longest = max(longest, count);
    }
    return longest;
}
//* O(N2)

int  longestConsecutiveSequenceBetter(const vector<int> &arr)
{
    int lastNum = INT_MIN;
    int count = 0;
    int result = 0;
    int i;
    sort(arr.begin(), arr.end()); //* N Log N
    for ( i= 0; i < arr.size(); i++)//* N
    {
        if(arr[i] -1 == lastNum){
            count ++;
            lastNum = arr[i];
        }
        else if (arr[i] == lastNum){

            
        }
        else{
            lastNum = arr[i];
            count = 1;
        }
        result = max(result, count);
    }
    return result;
}

//* This will end up in Big(2nlogn) but the degree is w can avoid the constant so nlogn

int longestConsecutiveSequenceOptimal(vector<int> arr){
    int result ;
    unordered_set<int> set;
    for(int i =0; i<arr.size();i++){
        set.insert(arr[i]);
    }
    for(auto st:set){
        if(set.find(st-1)  == set.end()){
                int cnt = 1;
                int curentEl = st;
                while(set.find(curentEl+1)!= set.end()){
                    curentEl ++;
                    cnt ++;
                }
             result = max (result , cnt);
        }
    }
    return 0;
}
//* In worst case case the set will take 