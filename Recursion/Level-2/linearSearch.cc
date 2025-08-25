#include<iostream>
int linearSearch(int arr[], int element, int length) {
    if (length == 0) return -1;        // Base case: not found
    if (arr[length - 1] == element)    // Check last valid index
        return length - 1;
    return linearSearch(arr, element, length - 1);
}

int main(int argc, char const *argv[])
{
     int arr[5] = {1, 3, 5, 7};
    int result = linearSearch(arr,5,4);
    std::cout<<result;
    return 0;
}
