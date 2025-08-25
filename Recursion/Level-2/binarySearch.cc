int binary_helper(int arr[], int element, int left, int right)
{
    if (left > right) 
        return -1;

    int middle = (left + right) / 2;

    if (element < arr[middle])
        return binary_helper(arr, element, left, middle - 1);
    else if (element > arr[middle])
        return binary_helper(arr, element, middle + 1, right);
    else
        return middle; 
}

int BinarySearch(int arr[], int element, int size)
{
    return binary_helper(arr, element, 0, size - 1);
}
