#include <iostream>

int fib(int value)
{
    ;
    if (value == 0)
        return 0;
    if (value == 1)
        return 1;

    return fib(value - 1) + fib(value - 2);
}

int main(int argc, char const *argv[])
{
    int fibs = fib(10);
    std::cout << "This is the nth term in sequence: " << fibs << std::endl;
    return 0;
}
