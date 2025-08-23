/**
 * ! This question is asked in three types first isthey will give a row amd column , give the element at that place
 * ! For instance row 3 column 2 
*/ 
/**
 * ! Print any nth row of the pascal triangle 
 * 
 */

 /**
  * * Print the entire pascal triangle
  * 
  */

 //* Pre req formula nCr = n! / r!* (n-r)!

#include <iostream>
#include <vector>
using namespace std;

//* Addressing the first question , if this question is asked then you need to do substract one from r and c then apply ncr
//* if row is 5 and col is 4 then 4C3 = 4! / 3! * (4-3) = 4*3*2*1 / 3*2*1*1 = 4*3*2 = 12

//! Observation is the r = 7 and c = 2 then 7*6*5*4*3*2*1 / 2*1 *(5*4*3*2*1)
//! We can see that the few number will got cancel then remaining will be 7*6/2*1
//! The number will do till c time thats it
int ncr(int n ,int r){
 int result = 1;
    for(int i = 0 ; i<r; i++){ //*bigO(r)
        result*=(n-i);
         result = result/(i+1);
    }
    return result;
}
void bruteSol(const vector<int>& vec,int r, int n){
    ncr(n-1,r-1);
} 

//*Addressing the 2nd question 
//*Note that nth row always have n elements
int printAnyRow(int r, int c){
    int n = r;
    for(int c = 1; c<n;c++){ //* this will bigO(number of elements in the row = n)
        cout<<ncr(r-1,c-1)<<endl; //* this will take bigO(r)
    }//*n2
}


int optSol(int r, int c){
    int n = r;
    for(int i = 1;i<r-1;i++){
        int ans = ans*(n-i);
        ans = ans/i;
        cout<<ans<<endl;
    }//*bigO(n)
}

//*Addressing the third question given a number n you need to generate that many row 

//*first row will be in a list all the row inside a list and these list will be inside a list 

vector<vector<int>>printAll(int n){
    vector<vector<int>> result ;
    for(int r = 1;  r<n;r++){
        vector<int> temp;
        for(int c = 1; c<r;c++){
            temp.push_back(ncr(r-1,c-1));
        }
        result.push_back(temp);

    }
    return result;
}//*~n3


vector<int> generateRow(int r){
    vector<int>answer;
    int ans = 1;
    answer.push_back(1);
    for(int col = 1;col<r;col++){
        ans = ans*(r-col);
        ans /= col;
        answer.push_back(ans);
    }
    return answer;
}

vector<vector<int>>optPrintAll(int n){
    vector<vector<int>> result ;
    for(int i = 1; i<n;i++){
        result.push_back(generateRow(i));
    }
    return result;
}//*


