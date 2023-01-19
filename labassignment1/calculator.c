//Lingyu Hu
//hu.lingyu@northeastern.edu
#include<stdio.h>
int main()
{
    int num1,num2,answer,choice;
    
    printf("Enter your choice\n");
    printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n");
    scanf("%d",&choice);
    
    printf("Enter num1 and num2 values");
    scanf("%d %d", &num1, &num2);
    
    switch (choice) {
        case 1:
            answer = num1 + num2;
            printf("Addition\nSum=%d\n", answer);
            break;
        
        case 2:
            answer = num1 - num2;
            printf("Substraction\nDifference=%d\n", answer);
            break;
        
        case 3:
            answer = num1 * num2;
            printf("Muliplication\nProduct=%d\n", answer);
            break;
        
        case 4:
            if (num2 == 0) {
                printf("divide by zero error");
                break;
            } else {
                answer = num1 / num2;
                printf("Divison\nQuotient=%d\n", answer);
                answer = num1 % num2;
                printf("Remainder=%d\n", answer);
                break;
            }
        default:
            printf("Invalid option");
            break;
        
    }
    
           
    return 0;
}
