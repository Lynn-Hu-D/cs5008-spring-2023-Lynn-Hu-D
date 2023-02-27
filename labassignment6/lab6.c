//enter your name here
//enter your email here

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* function to encrypt the data*/
void encrypt(char text[], int key)
{
    //insert your code here
    char begin;
    int i = 0;
   
    while (text[i] != '\0'){
        if (text[i] >= 'A' && text[i] <= 'Z'){
            begin = 'A';
        } else {
            begin = 'a';
        }
        text[i] = (text[i] - begin + key) % 26 + begin;
        i += 1;
    } 
}

/*function to decrypt the data*/
void decrypt(char text[],int key)
{
    
    //insert your code here
    char begin;
    int i = 0;
   
    while (text[i] != '\0'){
        if (text[i] >= 'A' && text[i] <= 'Z'){
            begin = 'A';
        } else {
            begin = 'a';
        }
        text[i] = (text[i] - begin - key + 26) % 26 + begin;
        i += 1;
    } 
    
}


/*----------- Main program---------------*/
int main()
{
    char text[20] ;
    int keyvalue=3;
    /*Input string */
    printf("Enter the message:  ");
    scanf("%s",text);
    printf("text input   = %s\n",text);
    
    /*call function to encrypt the data*/
    encrypt(text,keyvalue);
    printf("Encrypted value = %s\n",text);
    
    /*call function to decrypt the data*/
    decrypt(text,keyvalue);
    printf("Decrypted value = %s\n",text);
    
    return 0;
}
