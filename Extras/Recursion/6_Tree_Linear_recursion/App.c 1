#include<iostream>
using namespace std;

int  fun(int x){
    if(x>0){
        cout<<x<<endl;
        fun(x-1);
        fun(x-1);

    }



}



int main(){
    int x = 0;

    int result = fun(x);

    return 0;
};

/**
 * ? Linear recursion
 * ! If the function is calling itself one time then it is linear 
 * ! The tail and head is calling itself oly one time;
 */

/**
 * ? TREE RECURSION
 * ! If the fun is calling itself more than one time then it is Tree recursion
 * ! For any value for the n then time complexity is Order(n);
 * ! Because this is in a geometric Progression = 2^0 2^1 2^2 2^3 2^4 ...2^n 
 * ! Sum is = (2^n+1)-1
 * ! That is 2^n
 */