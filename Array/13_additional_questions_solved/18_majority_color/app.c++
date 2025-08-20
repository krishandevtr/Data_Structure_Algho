#include <iostream>
#include <map>
#include <vector>
using namespace std;

int  bruteSol(const vector<int>& arr) {
    int n = arr.size();
    int count =0;
        for(int i = 0; i<n;i++){
            count =0;
            for(int j = i; i<n;j++){
                if(arr[i] == arr[j]) count++;
            }
            if(count <n/2) return arr[i];
        }
}
/**
 * ! For each element we gonna traverse the array so this is in inefficient 
 * !BigO(n2)
 */
int betterSol (vector<int>arr){
    map<int,int>hash;
    for(int i = 0; i<arr.size();i++){
        hash[arr[i]]++;
    } //log n
    for(auto value : hash){
        if(value .second < arr.size()/2) return value.first;
    }//n
    return -1;
}

//? This gonna take nlog n 

int optimalSol(vector<int> arr){
    int count=0 , el ,counter =0;
    for(int i =0; i<arr.size(); i++){
        if(count == 0){
            el = arr[i];
            count = 1;
        }
        else if(arr[i] == el){
            count ++;
        }else {
            count --;
        }
    }
    for(int j = 0; j<arr.size(); j++){
        if(arr[j] == el){
                counter ++;
        }
    }
    if(counter <arr.size()/2){
        return el;
    }
    return -1;
}


