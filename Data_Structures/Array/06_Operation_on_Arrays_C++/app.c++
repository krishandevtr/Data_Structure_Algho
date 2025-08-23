#include <iostream>
#include <utility>
using namespace std;



struct Array
{
    int *pointer;
    int size;
    int length; // Number of the elements
};

void Display(Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        cout << "Elements are: " << arr.pointer[i];
    };
};

void Append(Array &arr, int value)
{
    if (arr.length == arr.size)
    {
        cout << "Memory full";
    }
    else
    {
        arr.pointer[arr.length] = value;
        arr.length++;
    }
};

void InsertAt(Array &arr, int pos, int value)
{
    if (arr.length >= arr.size)
    {
        cout << "Memory full";
    }
    else
    {
        if (pos >= 0 && pos <= arr.length)
        {
            for (int i = arr.length; i > pos; i--)
            {
                arr.pointer[i] = arr.pointer[i - 1];
            };
            arr.pointer[pos] = value;
            arr.length++;
        }
    };
};

// case pos = 3
// size = 5{1,2,3,4,}
// length = 5
void Delete(Array &arr, int pos)
{
    if (pos < 0 || pos >= arr.length)
    {
        return;
    }
    else
    {
        for (int i = pos; i < arr.length - 1; i++)
        {
            arr.pointer[i] = arr.pointer[i + 1];
        }
        arr.length--;
    }
};

int getIndex(Array arr, int key)
{
    // Using the linear search

    for (int i = 0; i < arr.length; i++)
    {
        if (arr.pointer[i] == key)
            return i;
        // int temp = arr.pointer[i]
        // int arr.pointer[i] = arr.pointer[0];
        // int arr.pointer[0] = temp;
    }
    return -1;
}

int Get(Array arr, int index)
{

    if (index >= 0 && index < arr.length)
    {
        return arr.pointer[index];
    }

    return -1;
};

int Set(Array arr, int index, int key)
{
    if (index > 0 && index < arr.length)
    {
        arr.pointer[index] = key;
        return 0;
    }
}

int Max(Array arr)
{
    int max = arr.pointer[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.pointer[i] > max)
            max = arr.pointer[i];
    }
    return max;
}
int Min(Array arr)
{
    int min = arr.pointer[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.pointer[i] < min)
            min = arr.pointer[i];
    }
    return min;
}

int Sum(Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.pointer[i];
    };
    return sum;
}

int RecursiveSum(Array arr, int n)
{
    int sum;
    if (n < 0)
    {
        return 0;
    }
    else
    {
        return RecursiveSum(arr, n - 1) + arr.pointer[n];
    };
};

int * reverse(Array arr,int length){

int left = 0;
int right = length-1;
 while(left<right){

    int temp = arr.pointer[left];
     arr.pointer[left] = arr.pointer[right];
     arr.pointer[right ] =temp; 
     left ++;
     right--;
    
}
return arr.pointer;
}

Array leftShift(Array &arr){
    for(int i = 0;i<arr.length-1; i++){
        arr.pointer[i] = arr.pointer[i+1];
    }
    arr.pointer[arr.length-1] =0;
    arr.length--;
    return arr;
};

Array rightShift(Array &arr) {
    // Shift elements from the end towards the beginning
    for (int i = arr.length - 1; i > 0; i--) {
        arr.pointer[i] = arr.pointer[i - 1];  // Shift element to the right
    }
    arr.pointer[0] = 0;
    return arr;
}

//! During the left shift we have removed one first element store that stuff in variable then copy that variable in the last index ,This is know as the rotation
int * Rotation(Array &arr){
    int firstIndex = arr.pointer[0];
    for(int i = 0;i<arr.length-1; i++){
        arr.pointer[i] = arr.pointer[i+1];
    }
    arr.pointer[arr.length-1] =firstIndex;
    return arr.pointer;
};

bool isSorted (Array arr){

    for(int i  = 0; i<arr.length-1; i ++){
        if(arr.pointer[i]>=arr.pointer[i+1]){
            return false;
        } 
    }
    return true;
}

  Array InsertAtSorted(Array &arr, int value) {
    if (arr.length >= arr.size) {
        cout << "Memory full";
        return;  // Indicates failure
    }
    int i;
    // Find the position to insert the value
    for (i = arr.length - 1; i >= 0; i--) {
        if (arr.pointer[i] <= value) {
            break;  // Found the correct position
        }
        arr.pointer[i + 1] = arr.pointer[i];  // Shift elements to the right
    }
    
    // Insert the value
    arr.pointer[i + 1] = value;
    arr.length++;  // Increase the length of the array

    return arr;  // Return the updated array pointer
}
void Rearrange(Array &arr){
    int i=0 ,j=arr.pointer[arr.length]-1 ;
    while(i<j){
        while(arr.pointer[i]>0)i++;
        while(arr.pointer[j]<0)j--;
        if(i<j) {swap(arr.pointer[i],arr.pointer[j]);}

    }
};

Array Merge(Array &arr1,Array &arr2){
    int * pointer;
    Array arr3;
    arr3.pointer = new int[(arr1.length+arr2.length)];
    int i= 0 ; int j = 0; int k = 0;

    while(i < arr1.length && j<arr2.length){
        if(arr1.pointer[i]<arr2.pointer[j]){
            arr3.pointer[k] = arr2.pointer[j];
            k++;
            j++;
        }else{
             arr3.pointer[k] = arr1.pointer[i];
             k++;
             i++;
        }

    }

    for(; i<arr1.length;i++){
        arr3.pointer[k]=arr1.pointer[i];
        k++;
    }
    for(; j<arr2.length;j++){
        arr3.pointer[k]=arr2.pointer[j];
        k++;
    }

return arr3;
};

Array Union(Array &arr1 ,Array &arr2){
    Array arr3;
    arr3.pointer = new int[(arr1.length+arr2.length)];
    int i= 0 ; int j = 0; int k = 0;
    while(i < arr1.length && j<arr2.length){
        if(arr1.pointer[i]<arr2.pointer[j]  ){
            arr3.pointer[k] = arr1.pointer[i];
            k++;
            i++;
        }else if(arr1.pointer[i]>arr2.pointer[j]){
            arr3.pointer[k] = arr2.pointer[j];
            j++;
            k++;
        }
        else{
            arr3.pointer[k] = arr1.pointer[i];
            i++;
            j++;
            k++;
        }
    }
    for(; i<arr1.length;i++){
        arr3.pointer[k] = arr1.pointer[i];
        k++;
    }
        for(; j<arr2.length;j++){
        arr3.pointer[k] = arr2.pointer[j];
        k++;
    }
    return arr3;
}

Array nonSortedIntersection(const Array &arr1,const Array &arr2 ) {
    //Assuming the arr1 and arr2 have a valid length
    Array store;
    int i =0;
    int k = 0;
    while(i<arr1.length){ // m 
        if(arr1.pointer[i] == arr2.pointer[i]){
            store.pointer[k] = arr1.pointer[i];
            k++;
            i++;
        }
        i++;
    }
    return store;

}

Array sortedIntersection(const Array arr1, const Array arr2) {
    Array store;
    store.pointer = new int[min(arr1.length, arr2.length)];
    store.length = 0;

    int i = 0, j = 0, k = 0;
    while (i < arr1.length && j < arr2.length) {
        if (arr1.pointer[i] < arr2.pointer[j]) {
            i++;
        } else if (arr1.pointer[i] > arr2.pointer[j]) {
            j++;
        } else {
            // Element in both arrays
            store.pointer[k++] = arr1.pointer[i];
            i++;
            j++;
        }
    }

    store.length = k; // Update the length of the resulting array
    return store;
}

Array difference(const Array arr1, const Array arr2) {
    int i = 0, j = 0, k = 0;
    Array store;

    // Iterate over both arrays
    while (i < arr1.length && j < arr2.length) {
        if (arr1.pointer[i] < arr2.pointer[j]) {
            // Element from arr1 is smaller, add it to the result array
            store.pointer[k++] = arr1.pointer[i];
            i++;
        } 
        else if (arr1.pointer[i] > arr2.pointer[j]) {
            // Element from arr2 is smaller, move the pointer in arr2
            j++;
        } 
        else {
            // Elements are equal, so move both pointers
            i++;
            j++;
        }
    }

    // If there are remaining elements in arr1, add them to the result
    while (i < arr1.length) {
        store.pointer[k++] = arr1.pointer[i++];
    }

    // Return the result array
    return store;
}


int main()
{
    Array arr;
    cout << "Enter the size of the array: ";
    cin >> arr.size;

    cout << "How many elements do you need to insert";
    cin >> arr.length;

    arr.pointer = new int[arr.size];

    cout << "Enter all elements";
    for (int i = 0; i < arr.length; i++) cin >> arr.pointer[i];

    //?You can use a menu driver for the user and you can use switch case to set call the each method
    //? Ask the user which operation do he needed to perform on the array
    return 0;
}
