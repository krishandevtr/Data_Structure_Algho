char* reverse(char name[],int n){
// let the size of the string be n
int i =0;
int j = n;
while(i<j)
{       char temp = name[i];
        name[i] = name[j];
        name[j] = temp;
        i++;
        j--;
}


    return name;
}