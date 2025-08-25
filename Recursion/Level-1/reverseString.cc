#include<iostream>
#include<string>

void reverseString( char text[],int length){

        if(length == 0) {
            std::cout<<text[0]<<std::endl;
            return;
        }
        std::cout << text[length] << std::endl;
        reverseString(text,length-1);
}


int main(int argc, char const *argv[])
{
    reverseString("Apple", 5); 
    return 0;
}
