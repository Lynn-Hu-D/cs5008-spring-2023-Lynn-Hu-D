//enter your name here
//enter your email here
//To perform insertion sort of integers stored in a file and display the output and store it in another file.
#include <stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    int arr[10],temp;
    int count=0,i,j;/*count will have the total number of elements in the array*/
    /*read the file*/
    fp=fopen("Input.txt","r");
    if(fp==NULL){
        //if file returns NULL then can't open the file
    printf("\n Cannot open the file \n");
    exit(0);
    }

    //insert your code here
    printf("contents of the file are\n");
    while(fscanf(fp, "%d", &arr[count]) == 1) { 
        printf("%d\n", arr[count]);
        count++;
    } 

    // insertion sort
    for (i = 1; i < count; i++) {
        j = i;
        temp = arr[j];
        while (j > 0 && arr[j - 1] > temp) {
            arr[j] = arr[j - 1];
            j -= 1;
        }
        arr[j] = temp;
    }

    // put the contents of arr array into the file
    printf("output is:\n");
    fp = fopen("Output.txt", "w");
    if (fp == NULL) {
        printf("The file cannot be opened");
        exit(0);
    }
    for (i = 0; i < count; i++) {
        fprintf(fp, "%d\n", arr[i]);
        printf("%d\n", arr[i]);
    }

    fclose(fp);

    return 0;
}
