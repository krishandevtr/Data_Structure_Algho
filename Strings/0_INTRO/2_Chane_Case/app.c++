///* change the case of the given array 


char* toLoweCase(char value[]){
        //Assuming that all the letters are in the BLOk 
        char * pointer;
        for(int i = 0; value[i]!='\0';i++){
            value[i] = value[i] +32;
        }
        return value;
}

char * toUpperCase(char value[]){
    for(int i = 0; value[i]!='\0';i++){
        value [i] = value [i] -32;
    }
    return value;
}

char * changeCase(char value []){
    for(int i = 0;value[i]!='\0';i++){
        if('A' <= value[i] && value[i] <= 'Z'){
            value[i] = value[i]+32;
        }
        else if ('a' <= value[i] && value[i] <= 'z')
        {
            value[i] = value[i]-32;
        }
        else{
            continue;
        }
    }
    return value;
}