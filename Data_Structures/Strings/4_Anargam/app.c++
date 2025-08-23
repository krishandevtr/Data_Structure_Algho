#include<vector>
using namespace std;
/**
 * ! Anagram 
 * ! If one pair of strings said to be anagram fi must contains similar letters
 * !  Decimal and medical
 */

//* Brute force 
bool isAnagram(vector<char> arr1,vector<char>arr2){
    if(arr1.size()!=arr2.size()) return false;

    for(int i = 0;i<arr1.size();i++){
        for(int j = 0; j<arr2.size();j++){
            if(arr1[i] !=arr2[j]) return false;
        }
    }
    return true;
}//* O(n2)

