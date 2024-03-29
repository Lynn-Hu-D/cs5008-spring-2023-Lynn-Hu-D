
/*Lingyu Hu*/
/* hu.lingyu@northeastern.edu*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char name[20];
    int age;
    char address[100];
    int reg;
    int priority;
    struct node *next;
}node_t;

/* Inserting patients in the queue based on priority*/
node_t *insert(struct node *front)
{

    node_t *p,*temp;
    char name[20],address[100];
    temp=(node_t*)malloc(sizeof(node_t));
    printf("Enter patient Name:");
    scanf("%s", temp->name);
    printf("Enter the patient's age:");
    scanf("%d",&(temp->age));
    printf("Enter the address:");
    scanf("%s",temp->address);
    printf("Enter the reg no:");
    scanf("%d",&(temp->reg));
    printf("Enter the priority:");
    scanf("%d",&(temp->priority));
    int pri=temp->priority;

 /*insert your code here*/
 if (front == NULL || pri > front->priority) {
    temp->next = front;
    return temp;
 }

node_t* cur = front;
while (cur->next != NULL) {
    if (pri > cur->next->priority) {
        temp->next = cur->next;
        cur->next = temp;
        return front;
    }
    cur = cur->next;
}
cur->next = temp;
return front;

}


/* Delete the node which is present at the front*/
node_t *delete(struct node *front)
{
    /*Insert your code here*/
    if (front == NULL) {
        printf("%s", "There is no patient record.");
    } else {
        node_t* temp = front;
        front = front->next;
        printf("Deleted Record is : %d\n", temp->reg);
        printf("Patient's name is : %s\n", temp->name);
        printf("Patient's age is : %d\n", temp->age);
        free(temp);
    }
    return front;
            
}

/* To display the patients records */
void display(node_t *front)
{
    node_t *temp=front;
    if(front==NULL)
    printf("\nTHERE IS NO PATIENT");
    else
    {
        printf("\nPriority wise appointments are:\n");
        while(temp!=NULL)
        {
        printf("The name of patient is:%s\n",temp->name);
        printf("The age of patient is:%d\n",temp->age);
        printf("The address of patient is : %s\n",temp->address);
        printf("---------------------------------------------------\n");
        temp=temp->next;
        }
    }
    return;
}
/* Function to free the nodes*/
void freenode(node_t *temp)
{
    if(temp!=NULL){
    freenode(temp->next);
    free(temp);
    }
}

/*-----------------Main program---------------------------*/
int main()
{
    node_t *front=NULL;
    int option;
    do{
        printf("\t\t\t Hospital emergency room system\n");
        printf("\t\t\t1.ADD A PATIENT\n");
        printf("\t\t\t2.DELETE A RECORD\n");
        printf("\t\t\t3.PATIENTS WAITING IN THE QUEUE\n");
        printf("\t\t\tEnter your choice:");
        scanf("%d",&option);
            switch(option)
            {
            /*Select 1 to insert elements in the priority queue*/
            case 1:
            front= insert(front);
            break;
             /* Select 2 to delete the elements at the front of priority queue*/
            case 2:
            front= delete(front);
            break;
            /* Select 3 To display the elements present in the priority queue*/
            case 3:
            display(front);
            break;
            /* Select 4 to terminate*/
            case 4:
            printf("The program is being terminated\n");
            break;
            }
    }
    while(option!=4);
        freenode(front);
return 0;
}
