#include<iostream>
using namespace std;


int main(){

    return 0;
}

/**
 * ? If their is a 8*8 grid , we can consider it has a memory
 * ! Memory is divided into small addressable unit that is known as the bytes
 * ! In the each grid is bytes
 * ! Every bytes have an address for the fist grid 1 then second is 2 and so on
 * ! Address are linear it cannot be represented as (x,Y)
 * ! coming to the grid again 
 * ! IF the first grid that is the memory address is 0 and last is 6535 (assuming)
 * ! Then the total number of bytes are 64 *10^24 
 * ! That is 64KB
 * ! When we have large ram like 8gb or 4gb then the entire is memory is not used as single unit 
 * ! The memory can be divided into small chunks called segments
 * ! Usually the size of a segment is 64 KB
 */

/**
 * ? How the program uses the main memory
 * ! when taking a segment
 * ! It is divided into three section
 * *  code section which have the program codes
 * * Next is the heap
 * * Stack
 * ! When we need to use a application the files(machine code) will transfer into the code section
 * ! Once the machine is loaded then the cpu will executes the codes
 * ! if we assume the main function contains 2 variable 
 * ! int a , b 
 * ! Lets assume that the int take 2 bytes(it depends upon the compiler TURBO c compiler 16bits it takes 2 adn the 32bits compiler should take 4 bytes);
 * ! Then for the main function inside the stack ,it will allocate two variable, inside the stack frame or an activation record for the main function
 * ! so , the size of the memory required by a function was decided at compile time only 
 * ! This type of the allocation is known as the static memory allocation
 * ! so what is static here
 * ! The size of the memory is static , when it was decided ? Compile time only, when everything is done at
 * ! 
 */

/**
 * ? When there is a sequence of function call how it is 
 * ! For instance if the main function calls another function and that function invokes another function and that function also invokes another one
 * ! First of all the the machine code is brought into the main memory code section
 * ! Then main function is invoked 
 * ! frame for the function is created then 
 * ! Another frame is created for the next function and again when next function is invoked then another record is created 
 * ! Currently executing functions frame  will be at the top of the stack
 * ! When the function got terminated , Then the control will at the function that invoked the terminated function and the frame for the terminated function is destroyed
 * ! Then when the control gets back to the main fn then last frame will deleted
 */

/**
 * ? How the heap is utilized by the program
 * ! Heap are used in 2 situations, when the things are organized like a tower like structure
 * ! And if it is not organized and its looking like a tower also we call its as heap
 * ! Heap -> organized thing , un organize thing
 * ! Heap memory is something like an resources
 * ! when you need the memory then you can use the memory if you donot need the memory then release the stuff
 * ! Program cannot directly access the heap directly
 * ! so how can we use the heap 
 * ! Using the pointer
 * ! Once you use the new int [] , to allocate memory inside the heap then it need to be released
 * ! Other it gonna bring a situation called Memory leak
 * ! 
 */