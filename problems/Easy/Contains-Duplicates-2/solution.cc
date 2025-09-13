#include <iostream>
#include <vector>
#include <unordered_map>

// Brute-force approach
bool containsDuplicateBrute(const std::vector<int>& nums, int k) {
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size() && j <= i + k; ++j) { // check index distance <= k
            if (nums[i] == nums[j])
                return true;
        }
    }
    return false;
}

// Optimal approach using hash map
bool containsDuplicateOptimal(const std::vector<int>& nums, int k) {

}

int main() {
    std::vector<int> arr = {1, 2, 3, 1, 2, 3};
    
    bool resBrute = containsDuplicateBrute(arr, 2);
    bool resOptimal = containsDuplicateOptimal(arr, 2);

    std::cout << "Brute-force result: " << (resBrute ? "true" : "false") << std::endl;
    std::cout << "Optimal result: " << (resOptimal ? "true" : "false") << std::endl;

    return 0;
}
