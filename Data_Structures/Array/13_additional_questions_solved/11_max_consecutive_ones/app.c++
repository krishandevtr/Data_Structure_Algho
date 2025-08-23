#include <iostream>
#include <vector >

using namespace std;

//* the question is max consecutive ones that present in the array

// How to solve the problem
//! Initial solution will be to brute force with one pointe always check wether the number is one
// If one then use a count variable then starting counting using an inner loop
// when should stop until you find another number then store the value to a variable then if you spot another series of 1 then start couting the number stop when u get a new number
// beforeing storing the count value make sure that value that you gonna store is greater than the current count value
// because our goal to return the max

//[1,2,4,91,1,4,1,1,1,1,1,]
int maxConsecutive(vector<int> arr)
{
    int result = 0;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            count++;
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[j] == 1)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            if (result < count)
            {
                result = count;
                count = 0;
            }
        }
    }
    return result;
}
// Think  of the worst case
//? this will be O(n2)

//! optimal  solution wil be

// we doesnot need the inner loop here because the count and the result is enough here because if there is break in the series then we can simply change the count to be 0
// Before storing you know what to do eh 😉

int max(vector<int> const &arr)
{
    int count = 0;
    int result = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
        else
        {
            if (result < count)
            {
                result = count;
            }
            count = 0;
        }
    }
    if (result < count)
    {
        result = count;
    }
    return result;
}

int main()
{
    return 0;
}