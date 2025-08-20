using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
//*The question says to return the leaders in the array 
//* Requirements for that is every element must be smaller 

//? For the brute force am gonna loop through the array for each element am gonna check is their an element  greater after the current element'
vector<int> bruteSol(vector<int>& arr) {
    vector<int> result;
    int size = arr.size();

    // Loop through each element in the array
    for (int i = 0; i < size; i++) {
        bool flag = false;
        // Check if there's any element greater than arr[i] after the current element
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[i]) {
                flag = true;
                break;
            }
        }

        // If no greater element found after arr[i], add it to result
        if (!flag) {
            result.push_back(arr[i]);
        }
    }
    return result;
}
//*~bigO(n^2)

//?__________________________Optimal Sol_______________________________


/**
 * !
 * !
 * !
 */
void optSol(const vector<int>& arr) {
    vector<int> result ;
    int maxi =INT_MIN;
    for(int i = arr.size()-2;i>=0;i--){
        if( arr[i]>maxi){
            result.push_back(arr[i]);
            maxi = arr[i];
            
        }
    }
    // Reverse the result to maintain original order
    sort(result.begin(), result.end());//This will take big og nlog(n)


}

