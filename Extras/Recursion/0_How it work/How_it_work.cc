#include<iostream>


void fun(int x){
    if(x>0){
        return ;
    }
    std::cout<<x<<std::endl;
    fun(x-1);
}
int main(){
    int x;
    x= 10 ;
    fun(x);
    return 0;
}

/**
 * ?  what is recursion ?
 * ! if a function is calling itself then it is said to be recursive function
 * ! There need to be a base case terminate the function 
 * ! Above is a example for the recursive function 
 * ! A recursive function is traced in the form of a TREE
 */

/**
 * ? Tracing the above function
 * ! The compile start with main function then first statement is executed 
 * ! A memory for variable x is reserved in the stack frame
 * ! Then the a copy of the variable is passed to the fun(3);
 * ! Then fun(){} will executes the base case which is checking whether the parameter is less than 0;
 * ! iF not it is calling the function again but this time we have reduced the value by 1
 * ! Recursion have two phases one is the calling phase 
 * ! Then next is returning phase 
 * ! 
 */