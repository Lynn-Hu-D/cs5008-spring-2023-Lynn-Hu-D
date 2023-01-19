/*C Program to read and print the n employee details using structure and dynamic memory allocation*/
#include <stdio.h>
#include <stdlib.h>
/*structure to hold the details of an employee*/
typedef struct employee
{
    int empId;
    char Name[100]; //array, string
    char Designation[100];
    char Dept[10];

}employee_t;

/* Read the employee details using scanf*/
void readData(int n, employee_t* s)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter the employeeId, Name, Designation and Dept of employee %d:\n", i+1);
        scanf("%d\n%s\n%s\n%s", &s[i].empId, s[i].Name, s[i].Designation, s[i].Dept);
    }
    
    
}

/* Function to print the employee details*/
void display(int n, employee_t* s)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("The details of the employee %d:\nempId: %d\nName: %s\ndesignation: %s\nDept: %s\n", i+1, *&s[i].empId, s[i].Name, s[i].Designation, s[i].Dept);
    }
    
     
}

/*----------Main Program--------*/
int main()

{
int n=0; // n is the number of employees
printf("Enter the number of employees: ");
scanf("%d", &n); // the address of n: &n

//dynamic memory allocation
employee_t* s = (employee_t*)(malloc(n * sizeof(employee_t)));
if (s != NULL) {
    readData(n, s);
    display(n, s);
    free(s); 
} 
printf("/////");
return 0;
}

