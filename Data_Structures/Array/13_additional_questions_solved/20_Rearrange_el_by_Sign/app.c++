//?There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements.
//?Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

#include <iostream>
#include <vector>
#include <vector>
using namespace std;
void bruteForce(vector<int> &arr)
{
    vector<int> posList;
    vector<int> negList;
    //? Big O(n)
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            negList.push_back(arr[i]);
        }
        else
        {
            posList.push_back(arr[i]);
        }
    }
    //? BigO(n)
    for (int j = 0; j < arr.size(); j++)
    {
        arr[2 * j] = posList[j];
        arr[2 * j + 1] = negList[j];
    }
    //? This will end up in (2n) and sc: of big(n)
}

//* We cannot opt the extra space it will get more complicated

#include <iostream>
#include <vector>
using namespace std;

vector<int> optSol(const vector<int> &arr)
{
    vector<int> result(arr.size(), 0);

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            result[i * 2] = arr[i];
        }
        else
        {
            result[2 * i + 1] = arr[i];
        }
    }
    return result;
}
//*________________________________________A variant of this question in this there is a difference because given array might contain n/2 +n/2 pos and negs if there is un equal just append them to the end

#include <iostream>
#include <vector>
using namespace std;

vector<int> OptSolution( vector<int> &arr)
{
    vector<int> pos, neg;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            pos.push_back(arr[i]);
        }
        else
        {
            neg.push_back(arr[i]);
        }
    }

    if (pos.size() > neg.size())
    {
        for (int j = 0; j < pos.size(); j++)
        {
            arr[2*j+1] = neg[j];
             arr[2*j] = pos[j];
        }
    }else{
        for(int j =0;j<pos.size();j++){
            arr[2*j] = pos[j];
        }
    }
}
