int arrayAccumulator(int *arr, int size) {
    static int sum = 0;
    if (size == 0) {       
        sum += arr[0];    
        return sum;
    }
    sum += arr[size - 1];  
    return arrayAccumulator(arr, size - 1);
}

int main() {
    int arr[7] = {1,7,2,5,3,2,10};
    int result = arrayAccumulator(arr, 7);
    return 0;
}
