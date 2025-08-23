#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;


//? return the two elements from the array where sum is = k
vector<pair<int,int>> bruteForce(const vector<int>& arr,const int k) {
    vector<pair<int, int>> result;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) { 
            // Start from i+1 to avoid redundancy
            if(arr[i] == arr[j]) continue;
            if (arr[i] + arr[j] == k) {
                result.push_back({arr[i], arr[j]});
            }
        }
    }
    return result;
}


vector<pair<int,int>>betterSol(const vector<int>& arr,int target) {
    map<int,int> hash;
    pair<int,int> pairs;
    vector<pair<int,int>> result;
    int companion = 0;
   for(int i = 0; i<arr.size();i++){
    companion = target - arr[i];
    if(hash.find(companion) != hash.end()){
        auto it = hash.find(companion);
        result.push_back({arr[i],companion});
    }else{
        hash[arr[i]] =i; 
    }
   }
   return result;
}


//*Optimal one 



vector<pair<int,int>> optSol(const vector<int>& vec,int target) {
    //* Array should be sorted in asc
  int i = 1;
  int j = vec.size()-2;
  int sum = vec[0]+vec[vec.size()-1];
   vector<pair<int,int>> result;

  while(i<j){
    int sum = vec[i] + vec[j];
    if(sum<target){
        i++;
    }else if(sum > target){
        j--;
    }else{
        result.push_back({vec[i],vec[j]});
            i++; // Move both pointers after finding a pair
            j--;
    }
  }
  return result;
}
