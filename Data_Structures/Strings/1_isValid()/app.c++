 bool isValid(char name[]){
    for(int i = 0; name[i]!='\0';i++){
        if(!(('A' <= name[i] && name[i] <= 'Z')||('a' <= name[i] && name[i] <= 'z'))){
             return false;
        };
    } 
    return true;
   
 }