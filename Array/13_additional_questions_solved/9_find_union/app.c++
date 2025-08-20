#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Forgot to add the intersection folder the answer will below the union algorithm

vector<int> Union(const vector<int> &vec, const vector<int> &vec2)
{
    vector<int> result;
    int i, j;
    i = j = 0;
    while (i < vec.size() && j < vec2.size())
    {
        if (vec[i] <= vec2[j])
        {
            result.push_back(vec[i]);
            if (result.back() != vec[i])
            {
                result.push_back(vec[i]);
                i++;
            }
        }
        else
        {
            if (vec2.size() == 0 || vec2.back() != vec2[j])
            {
                result.push_back(vec2[j]);
                j++;
            }
        }
    }
    for (; i < vec.size(); i++)
    {
        if (vec.back() != vec[i])
        {
            result.push_back(vec[i]);
        }
    }
    for (; j < vec.size(); j++)
    {
        if (vec.back() != vec[j])
        {
            result.push_back(vec[j]);
        }
    }

    return result;
}
//* TC: O(n+n)-> worst case
//* SC: o(n+n)->worst case

/**
 * !___________________________________________________________________________________________
 *
 */

// initial solution will be brute force with 2 pointer
//  i we know that the intersection operation are mostly done in the sets
//  That means the set will be sorted and the set will contains any dup
//  one pointer will be i that gonna take care the fist arr and then j gonna take care the second array
//  what we will do is loop through the both array at once if the i and j are similar then we gonna put the  number in the result array
//  increment i and j till both of them gets simillar value

vector<int> intersection(vector<int> arr, vector<int> arr2)
{
    vector<int> result;
    int i = 0, j = 0;
    int sizeArr = arr.size();
    int sizeArr2 = arr2.size();

    while (i < sizeArr && j < sizeArr2)
    {
        if (arr[i] < arr2[j])
        {
            i++; // Move i if element in arr is smaller
        }
        else if (arr[i] > arr2[j])
        {
            j++; // Move j if element in arr2 is smaller
        }
        else
        {
            // If both elements are equal, add to result
            if (result.empty() || result.back() != arr[i])
            {
                result.push_back(arr[i]);
            }
            i++;
            j++;
        }
    }

    return result;
}

int main()
{
    vector<int> vec1 = {1, 3, 5, 7}; // First vector
    vector<int> vec2 = {2, 4, 6, 8}; // Second vector

    // Call Union function and store the result
    vector<int> result = Union(vec1, vec2);

    // Print the result
    cout << "Union of the two vectors: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
