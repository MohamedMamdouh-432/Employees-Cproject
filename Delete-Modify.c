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

void DeleteByName(FILE *ptr,int *recount)
{
     system("cls") ;
     showcursor(0) ;
     char another = 'y' ;

        if(front==NULL)
        {
            printf("\n\nData Base is Empty , We have no employees ...\n\n") ;
            system("pause") ;
            hidecursor(0) ;
            system("cls") ;
        }
        else
        {
            printf("\n\t\t\t\t **** Important Notes ****\n\n");
            printf("\t\t\t\t\tFirst :: Please Enter correct name\n") ;
            printf("\t\t\t\tSecond :: First character should be capital letter\n") ;
            printf("\t\t\t     -------------------------------------------------------") ;
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
                        char key[30] ;
                printf("\n*You should enter correct name of one or two parts* \n") ;
                printf("Enter Employee name you want to delete :  ") ;
                fflush(stdin) ;
                gets(key) ;
                fflush(stdin) ;
                // modifying employee in program data ...
                node *ftr , *ltr , *dtr ;
                ltr = front ;
                ftr = ltr ;
                int flag = 0 ;
                while(ltr != NULL)
                {
                    if( strcmp(key , ltr->e.name) == 0 )
                    {
                        flag = 1 ;
                        break ;
                    }
                    if(ltr == front)
                    {
                        ltr = ltr->next ;
                        ftr = front ;
                    }
                    else
                    {
                        ftr = ltr ;
                        ltr = ltr->next ;
                    }
                }
                if(flag == 0)
                {
                     printf("\n Employee having name  ' %s ' not founded .\n",key) ;
                    goto returningToLoop ;
                }
                else if(flag == 1)
                {
                    if(ltr == front)
                    {
                        dtr = front ;
                        front = front->next ;
                        (*recount)-- ;
                        printf("\n\n\t\t\t*****Employee having  name ' %s ' is Successfully Deleted*****\n\n",key) ;
                        free(dtr) ;
                    }
                    else
                    {
                        ftr->next = ltr->next ;
                        (*recount)-- ;
                        printf("\n\n\t\t\t*****Employee having  name ' %s ' is Successfully Deleted*****\n\n",key) ;
                        free(ltr) ;
                    }
                    // deleting this employee from file data ...
                    fclose(ptr) ;
                    ptr = fopen("Employees DataBase.txt","wb+") ;
                    freopen("Employees DataBase.txt","ab+",ptr) ;

                    ftr = front ;
                    while( ftr != NULL )
                    {
                        fwrite(&ftr->e,sizeof(ftr->e),1,ptr) ;
                        fprintf(ptr,"\n") ;
                        ftr = ftr->next ;
                    }
                }
                    }
                returningToLoop :
                printf("\n\t1 - To delete another employee enter 'y' \t 2 - To go back to main menu enter 'n' \n ") ;
                printf(" \t\t\t\tEnter your choice :  ") ;
                another = getche() ;
                }
                hidecursor(0) ;
                system("cls") ;
        }
}

void Modify(FILE *ptr)
{
     system("cls") ;
     showcursor(0) ;
     char another = 'y' ;
        if(front==NULL)
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
                printf("\n**You should enter correct name of one or two parts** \n") ;
                printf("Enter Employee name you want to modify :  ") ;
                fflush(stdin) ;
                gets(key) ;
                fflush(stdin) ;
                // modifying employee in program data ...
                node *ftr , *ltr , *dtr ;
                ltr = front ;
                ftr = ltr ;
                int flag = 0 ;
                while(ltr != NULL)
                {
                    if( strcmp(key , ltr->e.name) == 0 )
                    {
                        dtr = (node *)malloc( sizeof(node) ) ;
                        printf("\nEnter New Name : ") ;
                        fflush(stdin) ;
                        gets(dtr->e.name) ;
                        fflush(stdin) ;
                        printf("Enter New Id : ") ;
                        scanf("%d",&dtr->e.id) ;
                        printf("Enter New Age : ") ;
                        scanf("%d",&dtr->e.age) ;
                        printf("Enter New Salary : ") ;
                        scanf("%f",&dtr->e.salary) ;
                        flag = 1 ; break ;
                    }
                    if(ltr == front)
                    {
                        ltr = ltr->next ;
                        ftr = front ;
                    }
                    else
                    {
                        ftr = ltr ;
                        ltr = ltr->next ;
                    }
                }
                if(flag == 0)
                {
                     printf("\n Employee having name  ' %s ' not founded .\n",key) ;
                    goto returningToLoop ;
                }
                else
                {
                    if(ltr == front)
                    {
                        dtr->next = front->next ;
                        front = dtr ;
                        free(ltr) ;
                    }
                    else
                    {
                        dtr->next = ltr->next ;
                        ftr->next = dtr ;
                        free(ltr) ;
                    }
                    // modifying employee in program data ...
                    fclose(ptr) ;
                    ptr = fopen("Employees DataBase.txt","wb+") ;
                    freopen("Employees DataBase.txt","ab+",ptr) ;
                    ftr = front ;
                    while( ftr != NULL )
                    {
                        fwrite(&ftr->e,sizeof(ftr->e),1,ptr) ;
                        fprintf(ptr,"\n") ;
                        ftr = ftr->next ;
                    }
                }
                returningToLoop :
                printf("\n\t1 - To modify another employee enter 'y' \t 2 - To go back to main menu enter 'n' \n ") ;
                printf(" \t\t\t\tEnter your choice :  ") ;
                another = getche() ;
                }
                hidecursor(0) ;
                system("cls") ;
        }
}
