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

void Searching(FILE *ptr)
{
        system("cls") ;
        showcursor(0) ;
        node *newPtr ;
        char another = 'y' ;
            // Searching for employee in program data...
            if(front == NULL)
            {
                printf("\n\nData Base is Empty , We have no employees ...\n\n") ;
                system("pause") ;
                hidecursor(0) ;
                system("cls") ;
            }
            else
            {
                printf("\n\t\t\t\t ********** Important Notes **********\n\n");
                printf("\t\t\t\t\tFirst :: Please Enter correct name\n") ;
                printf("\t\t\t\tSecond :: First character should be capital letter\n") ;
                printf("\t\t\t     -------------------------------------------------------") ;
                while(another == 'y')
                {
                    char key[30] ;
                    int index=0 ;
                    printf("\n**You should enter correct name of one or two parts** \n") ;
                    printf("Enter Employee name to search :  ") ;
                    fflush(stdin) ;
                    gets(key) ;
                    fflush(stdin) ;

                    newPtr = front ;
                    while(newPtr != NULL)
                    {
                        index++ ;
                        if( strcmp(newPtr->e.name , key) == 0)
                        {
                            printf("\n Employee having name  ' %s ' existing at index ( %d )  ::\n",key,index) ;
                            printf("\t\t Name : %s\n", newPtr->e.name) ;
                            printf("\t\t Age : %d\n", newPtr->e.age) ;
                            printf("\t\t Id : %d\n", newPtr->e.id) ;
                            printf("\t\t Salary : %0.0f\n", newPtr->e.salary) ;
                            break ;
                        }
                        newPtr = newPtr->next  ;
                    }
                if(newPtr == NULL)
                {
                    printf("\n Employee having name  ' %s ' not founded .\n",key) ;
                }
                    printf("\n\t1 - To search for another employee enter 'y' \t 2 - To go back to main menu enter 'n' \n ") ;
                    printf(" \t\t\t\tEnter your choice :  ") ;
                    another = getche() ;
                }
                hidecursor(0) ;
                system("cls") ;
            }
}
