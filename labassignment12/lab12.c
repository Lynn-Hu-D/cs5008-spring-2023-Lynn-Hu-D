//enter your email here
//enter your name here

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int compression(char arr[], int n, char res[]){
    
    //insert your code here
    if (n < 2) {
        return 2;
    }

    int l = 0;
    int r = 0;
    int index = 0;
    int num;

    while ( r < n) {
        while (arr[l] == arr[r]) {
            r += 1;
        }
        num = r - l;
        res[index++] = arr[l];

        if (num != 1) {
            char cur[50];
            sprintf(cur, "%d", num);
            int i = 0;
            while (cur[i] != 0){            
                res[index++] = cur[i++];
            }
        }
        
        l = r;
    }

    return index;
    
}
 
int main()
{
    char a[]="aaaaaaaaaaaaaabbbbcccd";

    char res[50];
    int r,n=strlen(a);//n is the size of input array
    r=compression(a,n,res);
    printf("length of the compressed string:%d\n",r);

    return 0;
}
