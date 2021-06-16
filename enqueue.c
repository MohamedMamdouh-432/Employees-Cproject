#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct data
{
    char name[30] ;
    int id ;
    int age ;
    float salary ;
}emp;

typedef struct queue
{
      emp e ;
      struct queue *next ;
}node ;

node *front=NULL , *back=NULL ;

void Enqueue(FILE *ptr,int *recount)
{
    system("cls") ;
    showcursor(0) ;
    char another = 'y' ;
    node *newPtr ;
    printf("\n\t\t\t\t **** Important Notes ****\n\n");
    printf("\t\t\t\t\tFirst :: Please Enter correct name\n") ;
    printf("\t\t\t\tSecond :: First character should be capital letter\n") ;
    printf("\t\t\t     -------------------------------------------------------") ;
    while(another == 'y')
    {
        newPtr = (node *)malloc(sizeof(node)) ;
        // Read data from user ...
        printf("\n\nEnter Employee Name : ") ;
        fflush(stdin) ;
        gets(newPtr->e.name) ;
        fflush(stdin) ;

        printf("Enter Employee age : ") ;
        scanf("%d",&newPtr->e.age) ;
        printf("Enter Employee salary : ") ;
        scanf("%f",&newPtr->e.salary) ;

        int id , flage=0;

        do
        {
            fflush(stdin);
            printf("enter employee id :");
            scanf("%d",&id);
        }while(!isspace(newPtr->e.id) && getchar()!='\n' ||  id<0) ;

        newPtr->next = NULL ;
        if(front == NULL)
        {
            newPtr->e.id = id ;
            front = back = newPtr ;
        }
        else
        {
            node *temp=front;
            // check if current id is equal to another id ...
              while(temp!= NULL)
                {

                    if(id==temp->e.id)
                    {
                        flage=1;
                        break;
                    }
                    temp=temp->next;
                }
        while(flage==1)
            {
                printf("\n***invalid id*** \n please enter again id: ");
                scanf("%d",&id);
                temp = front ;
                 while(temp!= NULL)
                {

                    if(id==temp->e.id)
                    {
                        flage=1;
                        break;
                    }
                    else{
                        flage=5;
                    }
                    temp=temp->next;
                }

        }
            newPtr->e.id=id;
            back->next = newPtr ;
            back= newPtr ;
        }

        fwrite(&newPtr->e,sizeof(newPtr->e),1,ptr) ;
        fprintf(ptr,"\n") ;
        (*recount)++ ;
        printf("\n\t\t\t**Employee is Successfully Inserted**\n") ;
        printf("\n\t1 - To add new employee enter 'y' \t 2 - To go back to main menu enter 'n' \n ") ;
        printf(" \t\t\t\tEnter your choice :  ") ;
        another = getche() ;
    }
    hidecursor(0) ;
    system("cls") ;
}
