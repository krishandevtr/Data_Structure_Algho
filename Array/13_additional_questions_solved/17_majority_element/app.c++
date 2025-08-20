#include <iostream>
#include <vector>
#include <map>
using namespace std;

//?__________________brute force_____________
int  majorityElement(const vector<int>& vec) {
    int count = 0;
    for(int i = 0; i<vec.size();i++){
         count = 0;
        for(int j = i ; j<vec.size();j++){
            if(vec[i] == vec[j]) count ++;
        }
        if(count >vec.size()/2) return vec[i] ;
    }
    return -1;
}

//?___________________________better Solutions______________

int betterSolution(vector<int>vec){
    map<int,int> hash ;
    for(int i = 0; i<vec.size();i++){
        hash[vec[i]]++;
    }
    for(auto pair:hash){
        if(pair.second< vec.size()/2) return pair.first; 
    }
    return -1;
}

//?__________________________Optimal Solution____________________
/**
 * ? Mores voting algorithm , this algorithm states that if their is a majority element this is dominates rest of the element will cancel
 * ! Take a counter variable and element variable , then loop through the array assign first element to the variable , if you meet the same variable then increment the count else decrement the counn t
 * ! If the count reaches zero then increment increment the element (take the second element )
 * ! 
 */
int optimalSolution(vector<int> &arr){
    // {2 2 1  1 1 2 2 }
       //size of the given array:
    int n = arr.size();
    int cnt = 0; // count
    int el; // Element
    for(int i = 0; i<n; i++){
        if(cnt == 0){
            cnt = 1;
            el = arr[i];
        }
        else if(arr[i] == el) cnt++;
        else cnt --;
    }
    int counter = 0;
    for(int i= 0 ; i <n; i++){
        if(arr[i] == el) counter ++;
    
    }
    if(counter > n/2) return el;
    return -1;
}
//* O(n) traversing the array + o(n) confirming wether is that the majority element 




int main() {
    return 0;
}