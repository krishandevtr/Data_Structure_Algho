#include<iostream>
using namespace std;
#include<vector>
 const int NUM = 97;
//*Brute method
bool isDup(char value []){
    for(int i = 0; value[i]!='\0';i++){
        for(int j = i+1;value[j]!='\0';j++){
            if(value[i] == value[j]) return true;
        }
    }
    return false;
}

//*Using Hashing;

bool isDuplicateHash(char arr[]){
    vector<int>hash(26,0);

    for(int i = 0;arr[i]!='\0';i++){
        int value = arr[i]-NUM;
        hash[value]++;
    }

    for(int i = 0; i<hash.size();i++){
        if(hash[i] >1){
            return true;
        }
    }
    return false;
}


//* Find the duplicates using bitwise operator
/**
 * ! left shift <<
 * ! bits oRing -> Merging
 * ! bit ANDing -> Masking
 *  */ 
/**
 * ! 1byte -> 8 bits
 * ! 0-> least significant bit and the 7 is the most significant bit
 * * oRing -> Merging
 * ! 
 * !
 */

bool isDuplicate(char arr[]) {
    long int h = 0, x = 0; // Bitmask and temporary variable
    for (int i = 0; arr[i] != '\0'; i++) {
        x = 1;
        int value = arr[i] - 'a'; // Adjust based on input range (e.g., lowercase letters)
        x = x << value; // Set the bit corresponding to the character
        if ((x & h) > 0) { // Check if the bit is already set
            cout << arr[i] << " is duplicated" << endl;
            return true; // Duplicate found
        } else {
            h = x | h; // Set the bit in the bitmask
        }
    }
    return false; // No duplicates found
}


int main(){

}