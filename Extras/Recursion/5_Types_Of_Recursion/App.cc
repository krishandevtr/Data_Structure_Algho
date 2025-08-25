#include<iostream>
using namespace std;


int main(){


    return 0;
}

/**
 * ? Types of recursion 
 * ! Tail Recursion 
 * ! Head recursion
 * ! Tree Recursion
 * ! Indirect Recursion
 * ! Nested  Recursion
 */

/**
 * ? Tail Recursion
 * ! If the function is called by itself and the statement of that function is the invoking the same function
 * ! int fun(x) {
 * !  if(x>0){
 * !       cout<<x<<endl;
 * !       fun(x-1);
 * !   }
 * !}
 * ! This time is performing action in the calling time only
 * ! During the return time ntg is  done 
 * ! Tail recursion can be easily converted to loop instead of the base case their will be while(n<0)
 * ! same statement cout<<
 * ! instead of the calling same fun(n-1) 
 * ! In while loop n--
 * ! Big O(n);
 * ! If you need to write tail recursion then it is better to be using While() loop
 * ! Some compiler that will convert the tail recursion in loop Due the space complexity , in loop it is O(1) ,though in the recursion is O(n)
 * ! 
 * !  
 */

/**
 * ? Head Recursion
 * ! If the function is called by itself and the statement of that function is the invoking the same function
 * ! int fun(x) {
 * !  if(x>0){
 * !       
 * !       fun(x-1)+n;
 * !       cout<<x<<endl;
 * !   }
 * !}
 * ! This gonna return some value when during the return time 
 * ! All the operation are done at the return time only
 * ! This type is called Head Recursion
 * ! Looking the HEad Recursion and when try to implement the stuff using while loop gonna be hard
 * ! 
 * ! 
 */