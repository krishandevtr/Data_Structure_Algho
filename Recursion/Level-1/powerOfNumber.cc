#include<iostream>

int pow(int base , int power){
    static int result = 0;
    if(power == 1){
        return base ;
    }

    result = pow(base,power-1);
    return result* base;
}





// 2^3 = 2*2*2


int main(int argc, char const *argv[])
{
    int result = pow(2,4);
    std::cout << "Result: "<<result << std::endl;
    return 0;
}
