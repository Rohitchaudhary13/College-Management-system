
#include <stdio.h>
#include<string.h>
#include <process.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <dos.h>

void rect(int x1,int y1,int x2,int y2);
int mainmenu();
void department();
void cse();
void ece();
void it();
void me();
void remain();
int work();
FILE *dept;

void gotoxy(int x, int y)
{
    COORD CRD;
    CRD.X = x;
    CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void department()
{
    char choose;
    int x1=30, y1=5, x2=115, y2=30;
    dept = fopen("dept.dat", "rb+");
    if(dept==NULL) dept = fopen("dept.dat", "wb+");
    system("cls");
    system("COLOR 30");
    rect(x1,y1,x2,y2);
    gotoxy(65, 8);
    printf("*****************");
    gotoxy(65, 9);
    printf("*  DEPARTMENTS  *");
    gotoxy(65, 10);
    printf("*****************");
    gotoxy(60, 12);
    printf("CSE Department");
    gotoxy(60, 14);
    printf("ECE Department");
    gotoxy(60, 16);
    printf("IT Department");
    gotoxy(60, 18);
    printf("ME Department");
    gotoxy(60, 20);
    printf("Remaining Department");
    gotoxy(60, 22);
    printf("Quit");
    gotoxy(60, 24);
    printf("Enter Your Option: "); fflush(stdin); scanf("%c", &choose);
    if (choose == 'c' || choose == 'C' || choose == 'e' || choose == 'E' || choose == 'i' || choose == 'I' || choose == 'q' || choose == 'Q'){
        gotoxy(60, 26);
    switch(choose)
    {
        case 'c': case 'C': cse(); break;
        case 'e': case 'E': ece(); break;
        case 'i': case 'I': it(); break;
        case 'm': case 'M': me(); break;
        case 'r': case 'R': remain(); break;
        case 'q': case 'Q': fclose(dept); exit(0);
        default: printf("Wrong Choice...");
        gotoxy(60, 27);
        system("pause");
    }
    }
    else if(choose==0x0A)
        {
            mainmenu();
        }
    else
    {
        mainmenu();
    }
}

void cse()
{
    work();
}
void ece()
{
    work();
}
void it()
{
    work();
}
void me()
{
    work();
}
void remain()
{
    work();
}

void title()
{

    system("COLOR 03");
    gotoxy(57,7);
    printf("************************************");
    gotoxy(57,8);
    printf("*    EMPLOYEE MANAGEMENT SYSTEM    *");
    gotoxy(57,9);
    printf("************************************");

}

void hline(int x1,int x2,int y)
{
  int i;
  for(i=x1;i<=x2;i++)
  {
    gotoxy(i,y);
    printf("%c",196);
  }
}
void vline(int y1,int y2,int x)
{
  int i;
  for(i=y1;i<=y2;i++)
  {
    gotoxy(x,i);
    printf("%c",179);
  }
}

void rect(int x1,int y1,int x2, int y2)
{
  /*printing corners*/
  gotoxy(x2,y1);
  printf("%c",191);
  gotoxy(x1,y2);
  printf("%c",192);
  gotoxy(x2,y2);
  printf("%c",217);
  gotoxy(x1,y1);
  printf("%c",218);
  /* printing lines */
  hline(x1+1,x2-1,y1);
  hline(x1+1,x2-1,y2);
  vline(y1+1,y2-1,x1);
  vline(y1+1,y2-1,x2);
}

typedef struct{
    int empid;
    char empname[51];
    char empdesig[51];
} Employee;
Employee e;
FILE *emp;


void line(){
	int n;
	for(n=1;n<=50;n++) printf("_");
	printf("\n");
}

void addemployee(){
    system("cls");
    system("COLOR 0E");
    gotoxy(65,10);
    printf("*******************");
    gotoxy(65,11);
    printf("*  ADD  EMPLOYEE  *");
    gotoxy(65,12);
    printf("*******************");
    gotoxy(60,15);
    printf("Enter Employee Id: "); scanf("%d", &e.empid);
    gotoxy(60,17);
    printf("Enter Employee Name: "); fflush(stdin); gets(e.empname);
    gotoxy(60,19);
    printf("Enter Employee Designation: "); fflush(stdin); gets(e.empdesig);
    fseek(emp,0,SEEK_END);
    fwrite(&e,sizeof(e),1,emp);
    gotoxy(60,21);
    printf("Record Saved...\n");
    fclose(emp);
    emp = fopen("emp.dat", "rb+");
    if(emp==NULL) emp = fopen("emp.dat", "wb+");
    gotoxy(60,23);
    system("pause");
}

void showemployee(){
    int l = 8;
    system("cls");
    system("COLOR 0E");
    rewind(emp);
    gotoxy(50,5);
    line();
    gotoxy(50,6);
    printf("%3s\t%-20s %-30s \n","Id","Name","Designation");
    gotoxy(50,7);
    line();
    /*gotoxy(50,15);*/
    while(fread(&e,sizeof(e),1,emp)){
        gotoxy(50,l);
        printf("%3d\t%-20s %-30s\n", e.empid, e.empname, e.empdesig);
        l++;
    }
    gotoxy(50,32);
    system("pause");
}

void searchemployee(){
    int empid, found=0;
    system("cls");
    system("COLOR 0E");
    gotoxy(65,10);
    printf("*******************");
    gotoxy(65,11);
    printf("*  FIND EMPLOYEE  *");
    gotoxy(65,12);
    printf("*******************");
    gotoxy(55,15);
    printf("Employee Id to search: "); scanf("%d", &empid);
    rewind(emp);
    while(fread(&e,sizeof(e),1,emp)){
        if(e.empid == empid){
            found=1;
            break;
        }
    }
    if(found)
        {gotoxy(55,17);
        printf("Record found as %d %s %s ", e.empid, e.empname, e.empdesig);}
    else{
        gotoxy(55,19);
        printf("Record not found");}
    gotoxy(55,21);
    system("pause");
}

void updateemployee(){
    int empid, found=0, x1=30, y1=5, x2=115, y2=30;
    system("cls");
    system("COLOR 0E");
    rect(x1,y1,x2,y2);
    gotoxy(63,8);
    printf("*********************");
    gotoxy(63,9);
    printf("*  UPDATE EMPLOYEE  *");
    gotoxy(63,10);
    printf("*********************");
    gotoxy(50,12);
    printf("Employee Details to Update: "); scanf("%d", &empid);
    rewind(emp);
    while(fread(&e,sizeof(e),1,emp)){
        if(e.empid == empid){
            found=1;
            break;
        }
    }
    if(found){
        gotoxy(50,14);
        printf("Old Name was %s", e.empname); fflush(stdin);gotoxy(50,16);printf("Enter New Name: "); gets(e.empname);
        gotoxy(50,18);
        printf("Old Designation was %s", e.empdesig); fflush(stdin);gotoxy(50,20);printf("Enter New Employee Designation: "); gets(e.empdesig);

        fseek(emp,-sizeof(e),SEEK_CUR);
        fwrite(&e,sizeof(e),1,emp);
        gotoxy(65,22);
        printf("Record Updated...");
    }
    else{
        gotoxy(65,22);
        printf("Record not found");}
    gotoxy(60,24);
    system("pause");
}

void delemployee(){
    int empid, found=0, x1=30, y1=5, x2=115, y2=30;
    system("cls");
    system("COLOR 0E");
    rect(x1,y1,x2,y2);
    gotoxy(65,10);
    printf("*********************");
    gotoxy(65,11);
    printf("*  DELETE EMPLOYEE  *");
    gotoxy(65,12);
    printf("*********************");
    gotoxy(60,14);
    printf("Employee Id to Delete: "); scanf("%d", &empid);
    rewind(emp);
    while(fread(&e,sizeof(e),1,emp)){
        if(e.empid == empid){
            found=1;
            break;
        }
    }
    if(found){
        FILE *temp=fopen("temp", "wb");
        rewind(emp);
        while(fread(&e,sizeof(e),1,emp)){
            if(e.empid!=empid){
                fwrite(&e,sizeof(e),1,temp);
            }
        }
        fclose(emp); fclose(temp);
        remove("emp.dat"); rename("temp", "emp.dat");
        emp = fopen("emp.dat", "rb+");
        gotoxy(60,16);
        printf("Record Deleted...");
    }

    else
        {gotoxy(60,16);
        printf("Record not found");}
    gotoxy(60,18);
    system("pause");
}

int work()
{
    int x1=30, y1=5, x2=115, y2=30;
    char choice;

    for(;;)
    {
        system("cls");
        system("COLOR E0");
        rect(x1,y1,x2,y2);
        title();
        gotoxy(63,12);
        printf("Add Employee");
        gotoxy(63,14);
        printf("Show Employee");
        gotoxy(63,16);
        printf("Find Employee");
        gotoxy(63,18);
        printf("Update Employee");
        gotoxy(63,20);
        printf("Delete Employee details");
        gotoxy(63,22);
        printf("Quit");

        gotoxy(60,24);
        printf("[ Press Enter to Return ]");
        gotoxy(59,26);
        printf("Enter the choice (a/s/f/u/d/q): ");fflush(stdin);
        scanf("%c", &choice);



        if (choice == 'a' ||choice == 'A'||choice == 's'||choice == 'S'||choice == 'f'||choice == 'F'||choice == 'u'||choice == 'U'||choice == 'd'||choice == 'D'||choice == 'q'||choice == 'Q'){
            switch(choice){
            case 'a': case 'A': addemployee(); break;
            case 's': case 'S': showemployee(); break;
            case 'f': case 'F': searchemployee(); break;
            case 'u': case 'U': updateemployee(); break;
            case 'd': case 'D': delemployee(); break;
            case 'q': case 'Q': fclose(emp); fclose(emp); fclose(dept); exit(0);
            default: gotoxy(63,30); printf("Invalid Choice..."); system("pause");

        }
        }
        else if(choice==0x0A)
        {
            department();
        }
        else
        {
            work();
        }

    }
}

void empstart()
{
    int i;
    system("cls");

    system("COLOR 30");
    gotoxy(68,14);
    printf("Welcome To");
    gotoxy(60,16);
    printf("Employee Management System");
    for (i = 0; i < 5; i++)
    {
        printf(" ");
        Sleep(500);
    }
    department();
}
