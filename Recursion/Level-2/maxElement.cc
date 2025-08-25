#include <algorithm>
#include <iostream>

int maxElement(int arr[], int size) {
    static int maxVal = INT_MIN; 

    if (size == 1) {
        maxVal = std::max(maxVal, arr[0]); 
    }

    maxVal = std::max(maxVal, arr[size - 1]);
    return maxElement(arr, size - 1);
}

int main() {
    int arr[7] = {1, 4, 6, 34, 7, 5, 32};
    std::cout << "Max Element: " << maxElement(arr, 7) << std::endl;
    return 0;
}
