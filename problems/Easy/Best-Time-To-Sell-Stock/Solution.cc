#include<iostream> 
#include<algorithm> 
#include<vector> 

// Brute force solution 
int bruteSolution (std::vector<int> &arr){
    int profit = 0;
    for(int i =0;i<arr.size(); ++i){
        for(int j = i+1;j<arr.size(); ++j){
            int diff = arr[j] - arr[i];
            if(diff>0){
                profit = std::max(diff,profit);
            }
        }
    }
    return profit;
}

// Optimal solution

int optimalSolution (std::vector<int> &arr){
        int lowestStockIndex = 0;
        int currentProfit = 0;
        int currentStockIndex  = 1;

        while(currentStockIndex< arr.size()){
            if(arr[lowestStockIndex]>arr[currentStockIndex]){
                lowestStockIndex = currentStockIndex;
                ++currentStockIndex;
            }
            else if (arr[lowestStockIndex]<arr[currentStockIndex]){
                currentProfit = std::max(currentProfit, arr[currentStockIndex]-arr[lowestStockIndex]);
                ++currentStockIndex;

            }else{
                ++currentStockIndex;
            }
        }

        return  currentProfit;
}

int main( int argc, char const *argv[])

{
    std::vector<int> arr = {3,3,5,0,0,3,1,4};

    int result =bruteSolution(arr);
    std::cout<<result<<std::endl;
    
    return 0;
}
