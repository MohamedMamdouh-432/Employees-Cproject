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

void draw(int  x, int y) ;
void printCount(FILE *hptr, int x, int y) ;
void printMain(int x, int y) ;
void printStudents(int x, int y) ;
void hidecursor() ;
void showcursor() ;
void gotoxy(int x,int y) ;

int main()
{
    FILE *fptr = fopen("Employees DataBase.txt","ab+") ;
    int  choice = 1 , count=0 ;
    char ch ;
    count = CountData(fptr) ;
    HANDLE console = GetStdHandle ( STD_OUTPUT_HANDLE );
    hidecursor(0);
    while(1)
    {
        draw(62, 5) ;
        printStudents(63,6);
        printCount(fptr, 41, 2) ;
        draw(19, 5) ;
     do
     {
         printMain(20,6);
      switch(choice)
      {
      case 1:
        SetConsoleTextAttribute(console,240);
      gotoxy(20,8); printf("       1]Add New employee.              "); break;
      case 2:
          SetConsoleTextAttribute(console,240);
      gotoxy(20,10); printf("       2]Delete first employee.         "); break;
      case 3:
        SetConsoleTextAttribute(console,240);
      gotoxy(20,12); printf("       3]Delete an employee by name.    "); break;
        case 4:
        SetConsoleTextAttribute(console,240);
      gotoxy(20,14); printf("       4]Modify an employee.            "); break;
      case 5:
        SetConsoleTextAttribute(console,240);
      gotoxy(20,16); printf("       5]Search for an employee.        "); break;
      case 6:
        SetConsoleTextAttribute(console,240);
      gotoxy(20,18); printf("       6]Print all data.                "); break;
      case 7:
        SetConsoleTextAttribute(console,240);
      gotoxy(20,20); printf("       7]Reset all employees'data.      "); break;
      case 8:
        SetConsoleTextAttribute(console,240);
      gotoxy(20,22); printf("       8]Exit from program.             "); break;
      }
    ch=getch();
    if(ch==-32){
        ch=getch();
    }
    if(ch==72){
        choice--;
    if(choice==0)
    {
       choice=8;
    }
}
    if(ch==80){
    choice++;
    if(choice==9){
       choice=1;
    }
}
 }while(ch!=13);
        gotoxy(40,20);
        SetConsoleTextAttribute(console,15) ;
        switch(choice)
        {
            case 1 : Enqueue(fptr,&count); break;
            case 2 : Dequeue(fptr,&count) ; break ;
            case 3 : DeleteByName(fptr,&count); break ;
            case 4 : Modify(fptr) ; break;
            case 5 : Searching(fptr) ; break ;
            case 6 :Display(fptr) ;break ;
            case 7 : Reset(fptr) ; break ;
            case 8 :
                      system("cls");
                      printCount(fptr, 41, 2);
                      draw(41, 5);
                    printStudents(42,6);
                    gotoxy(20,28);
                    exit(0); break ;
        }
    }
        fclose(fptr) ;
        return 0 ;
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void showcursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 20;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void draw(int  x, int y)
{
      int i;
      gotoxy(x,y++); printf("%c",201);
      for (i=0;i<40;i++){
        printf("%c",205);
      }
      printf("%c",187);
      gotoxy(x,y++); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
      gotoxy(x,y++); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
      gotoxy(x,y++); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
      gotoxy(x,y++); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
      gotoxy(x,y++); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
      gotoxy(x,y++); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
      gotoxy(x,y++); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
      gotoxy(x,y++); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
      gotoxy(x,y++); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
      gotoxy(x,y++); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
      gotoxy(x,y++); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
      gotoxy(x,y++); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
       gotoxy(x,y++);printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
      gotoxy(x,y++); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
      gotoxy(x,y++); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
      gotoxy(x,y++); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
      gotoxy(x,y++); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
       gotoxy(x,y++); printf("%c",200);
      for (i=0;i<40;i++){
        printf("%c",205) ;
      }
      printf("%c",188) ;
}

void printCount(FILE *hptr, int x, int y) {
      int newcount = CountData(hptr) ;
      int i;
      gotoxy(x,y); printf("%c",201);
      for (i=0;i<40;i++){
        printf("%c",205);
      }
      printf("%c",187);
      gotoxy(x,y + 1); printf("%c",186);
       for (i=0;i<40;i++){
        printf(" ");
      }
      printf("%c",186);
       gotoxy(x,y + 2); printf("%c",200);
      for (i=0;i<40;i++){
        printf("%c",205) ;
      }
      printf("%c",188) ;
        gotoxy(x + 4,y + 1) ;printf(" Employees Number in Company = %d   ",newcount) ;
}

void printMain(int x, int y) {
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
      gotoxy(x,y); printf(" Please enter the operation you want:   ");
      gotoxy(x,y + 2); printf("        1]Add New employee.             ");
      gotoxy(x,y + 4); printf("        2]Delete first employee.        ");
      gotoxy(x,y + 6); printf("        3]Delete an employee by name.   ");
      gotoxy(x,y + 8); printf("        4]Modify an employee.           ");
      gotoxy(x,y + 10); printf("        5]Search for an employee.       ");
      gotoxy(x,y + 12); printf("        6]Print all data.               ");
      gotoxy(x,y + 14); printf("        7]Reset all employees'data.     ");
      gotoxy(x,y + 16); printf("        8]Exit from program.            ");
      printf("\n");
}

void printStudents(int x, int y) {
        SetConsoleTextAttribute(GetStdHandle ( STD_OUTPUT_HANDLE ),15);
        gotoxy(x + 8,y) ; printf("###Students of team###\n") ;
        gotoxy(x,y + 2) ;printf("Mohamed Mamdouh Salah Ahmed.\n") ;
        gotoxy(x,y + 4) ;printf("Mohamed Abdel Nasser Hammam.\n") ;
        gotoxy(x,y + 6) ;printf("Waheed Haitham Waheed.\n") ;
        gotoxy(x,y + 8) ;printf("Mohamed Naser Mohamed Fares.\n") ;
        gotoxy(x,y + 10) ;printf("Aya Abd El-Moneim.\n\n") ;
        gotoxy(x + 8,y + 12) ;printf("###Doctor of subject###\n") ;
        gotoxy(x,y + 14) ;printf("Prof. Dr. Abdelhamid Attaby.\n\n") ;
}

void Display(FILE *ptr)
{
    system("cls") ;
    showcursor(0) ;
    int newcount = CountData(ptr) ;
    int recount = 0 ;
    printCount(ptr, 41, 2) ;
    node *nptr = (node *)malloc( sizeof(node) ) ;
        if( front == NULL )
        {
            printf("\n\nData Base is Empty , We have no employees ...\n\n") ;
            hidecursor(0) ;
        }
        else
        {
            nptr = front ;
            while( nptr != NULL )
            {
                recount++ ;
                if (recount == 1)
                {
                    printf("\n\nFirst Employee in Front  :: \n") ;
                    printf("\t\t Name : %s\n",nptr->e.name) ;
                    printf("\t\t Age : %d\n",nptr->e.age) ;
                    printf("\t\t Id : %d\n",nptr->e.id) ;
                    printf("\t\t Salary : %0.0f\n\n",nptr->e.salary) ;

                }
                else if(recount == newcount)
                {
                    printf("Last Employee in Back :: \n") ;
                    printf("\t\t Name : %s\n",nptr->e.name) ;
                    printf("\t\t Age : %d\n",nptr->e.age) ;
                    printf("\t\t Id : %d\n",nptr->e.id) ;
                    printf("\t\t Salary : %0.0f\n\n",nptr->e.salary) ;
                }
                else
                {
                    printf("Employee [ %d ] :: \n",recount) ;
                    printf("\t\t Name : %s\n",nptr->e.name) ;
                    printf("\t\t Age : %d\n",nptr->e.age) ;
                    printf("\t\t Id : %d\n",nptr->e.id) ;
                    printf("\t\t Salary : %0.0f\n\n",nptr->e.salary) ;
                }
                nptr = nptr->next ;
            }
        }
    system("pause") ;
    hidecursor(0) ;
    system("cls") ;
}
