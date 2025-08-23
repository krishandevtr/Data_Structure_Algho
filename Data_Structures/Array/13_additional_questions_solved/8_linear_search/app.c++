#include <iostream>
#include <vector>
using namespace std;

//* given an array return the index of the first occurance this number in this array

int linearSearch(vector<int> &vec, int val)
{

    int i = 0;
    int size = vec.size();
    for (i; i < size; i++)
    {
        if (vec[i] == val)
            return i;
    }
    return -1;
}
int main()
{
    return 0;
}