#include<iostream>
void printNumbers(int value){
    if(value ==1){
        std::cout<<"Value:  1"<<std::endl;
        return;
    }
   std::cout<<"value: :"<<value<<std::endl; 
   printNumbers(value-1);
   
}


int main(int argc, char const *argv[])
{
    printNumbers(10);
    return 0;
}
