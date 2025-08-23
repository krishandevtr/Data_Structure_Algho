/**
 * * Character set or ASCI code
 * ! A set of character supported of compiler
 * ! we define a set of number to represents a character
 * ! This number is known as ASCII code
 * ! UNICODES are differrent for national languages -> hindi , chinese
 * ! In ASCII A = 65 , B = 56 ...Z = 90
 * ! a = 97, b = 98.....z = 122
 * ! 0 = 48 , 1 = 49 , 2= 50 .....9 = 59
 * ! Other symbols have codes
 * ! for enter button = 10
 * ! for space = 13
 * ! for esc = 27
 * ! ASCI starts from 0 -127
 * ! 7 bitts are needed to represents one code
 * ! 
 */

/**
 * * UNICODES
 * ! 2bytes are needed
 * ! 16-bits
 * ! 4 4 bits 
 * ! for ex: C03A
 */

 char temp = 'A'; // declare a char variable must be inside single quotes 
 // Cannot be multiple characters
 //* char temp = 'AB' -> wrong char temp = "A"-> wrong


//* Char X [5] = {'A','B','C','D','E'}

//* IF we declare a char array of size of 10 but we are only using the first 5 space then rest of them will be 0 
//*How can we know the end of the string we can use something called
//! string delimeter \0 
//! We can also say this as null or end of the string
//! In other languages the end of string is spotted using the length 


//* char name[] = {'J','H','O','n',\0}
