#include <vector>
#include <iostream>

int searchInsert(std::vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (nums[middle] == target)
        {
            return middle;
        }
        else if (nums[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    return left; 
}

int main()
{
    std::vector<int> arr = {1,2,3,4,5,6,8,9};
    int result = searchInsert(arr, 7);
    std::cout << "Insert position: " << result << std::endl;
    return 0;
}
