#include <iostream>
#include <climits> // for INT_MAX
#include <algorithm> // for std::min

int minElement(int arr[], int size) {
    if (size == 1)  // base case
        return arr[0];

    return std::min(arr[size - 1], minElement(arr, size - 1));
}

int main() {
    int arr[7] = {1, 4, 6, 34, 7, 5, 32};
    std::cout << "Min Element: " << minElement(arr, 7) << std::endl;
    return 0;
}
