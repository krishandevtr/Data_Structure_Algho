#include<iostream>


int sum (int value){
    static int result = 0;
    if(value == 1) return 1;
    result= sum(value-1);
    return result+value;     
}





int main(int argc, char const *argv[])
{
    std::cout<<sum(5)<<std::endl;
    return 0;
}
