#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> bruteForce(const vector<int>& arr,int target) {
    set<vector<int>>st;
    for(int i = 0; i<arr.size();i++){
        for(int j = i+1;j<arr.size();j++){
            for(int k = j+1;k<arr.size();k++){
                if(arr[i]+arr[j]+arr[k] == target){
                    vector<int> temp = {arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                vector<vector<int>> ans(st.begin(),st.end());
                return ans;
            }
        }
    }
}

//*This is algo is  a shit because this gonna take a lot a memory and time 
//* worst case : n3
///* space : using the set 

 vector<vector<int>>  betterSol(const vector<int>& vec) {
    set<vector<int>> ans;
    
    for(int i = 0; i<vec.size();i++){
        set<int>hashSet;
        for(int j= i+1; j<vec.size();j++){
            int third = -(vec[i]+vec[j]);
            if(hashSet.find(third)!=hashSet.end()){
                vector<int>temp = {vec[i],vec[j],third};
                sort(temp.begin(),temp.end());
                ans.insert(temp);
            }
            hashSet.insert(third);
        }
    }
    vector<vector<int>> result(ans.begin(),ans.end());
    return result;
}
//* tc: n2*log m; log m is the size of the set
//* sc: O(n)  + O(no of el in set)

 vector<vector<int>>  optSol(const vector<int>& vec) {
    vector<vector<int>> ans;
    sort(vec.begin(),vec.end()); //* nlogn to sort
    for(int i = 0;i<vec.size();i++){//* n
        if(i>0 && vec[i-1 == vec[i]]) continue;
        int j = i+1; 
        int k = vec.size()-1;
        while(j<k){//*n
            int sum = vec[i]+vec[j]+vec[k];
            if(sum<0){
                j++;
            }else if (sum>0)
            {
                    i++;
                
            }else
            {
                vector<int>temp = {vec[i],vec[j,vec[k]]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k&&vec[i] == vec[i-1]) i++;
                while(j<k&&vec[k] == vec[k]+1) k--;
            }
        }
    }//* nlogn+ n2;
    return ans;
}



