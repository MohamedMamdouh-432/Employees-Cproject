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

void Dequeue(FILE *ptr,int *recount)
{
        system("cls") ;
        showcursor(0) ;
        char another = 'y' ;
            node *newPtr = (node *)malloc( sizeof(node) ) ;
            rewind(ptr) ;
            if( fread(&newPtr->e,sizeof(newPtr->e),1,ptr) < 1 )
            {
                 printf("\n\nData Base is Empty , We have no employees ...\n\n") ;
                 system("pause") ;
                 hidecursor(0) ;
                 system("cls") ;
            }
            else
            {
                while(another == 'y')
                {
                    if (front == NULL)
                    {
                        printf("\n\nData Base is Empty , We have no employees ...\n\n") ;
                         system("pause") ;
                         hidecursor(0) ;
                         system("cls") ; break ;
                    }
                    else
                    {
                        rewind(ptr) ;
                        // Reading data from file and store it in the form of queue implementation ...
                        int count = 1 ;
                        while( fread(&newPtr->e,sizeof(newPtr->e),1,ptr) >= 1 )
                        {
                            newPtr->next = NULL ;
                            if(count == 1)
                            {
                                front = back = newPtr ;
                                count++ ;
                            }
                            else
                            {
                                back->next = newPtr ;
                                back = newPtr ;
                            }
                            newPtr = (node *)malloc( sizeof(node) ) ;
                            fseek(ptr,1,SEEK_CUR) ;
                        }
                        back->next = NULL ;
                    // Delete from here ...
                        node *temp ;
                        temp = front ;
                        front = front->next ;
                        (*recount)-- ;
                        free(temp) ;
                         // Reopening file data in write mode to delete last data ...
                        fclose(ptr) ;
                        ptr = fopen("Employees DataBase.txt","wb+") ; // delete step
                        freopen("Employees DataBase.txt","ab+",ptr) ;

                        newPtr = front ;
                        while( newPtr != NULL )
                        {
                            fwrite(&newPtr->e,sizeof(newPtr->e),1,ptr) ;
                            fprintf(ptr,"\n") ;
                            newPtr = newPtr->next ;
                        }
                        printf("\n\n\t\t\t*****Employee is Successfully Deleted*****\n\n") ;
                        }
                        printf("\n\t1 - To delete another employee enter 'y' \t 2 - To go back to main menu enter 'n' \n ") ;
                        printf(" \t\t\t\tEnter your choice :  ") ;
                        another = getche() ;
                }
                hidecursor(0) ;
                system("cls") ;
            }
}

void Reset(FILE *ptr)
{
    system("cls") ;
    showcursor(0) ;
    // Free all data from memory...
    node *htr=front ;
    while( htr != NULL )
    {
        front = front->next ;
        free(htr) ;
        htr = front ;
    }
    // Free all data from file ...
    fclose(ptr) ;
    ptr = fopen("Employees DataBase.txt","wb+") ;
    freopen("Employees DataBase.txt","ab+",ptr) ;
    printf("\n\n\n\n\t\t\t*****All Employees are Successfully Deleted*****\n\n") ;
    system("pause");
    hidecursor(0) ;
    system("cls");
}
