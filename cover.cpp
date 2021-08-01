/* Made By Rohit Choudhary */


#include <stdio.h>
#include<string.h>
#include <process.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <dos.h>
#include <windows.h>
#include "hexemp.cpp"
#include "stud.cpp"

void optionn();
void signin();
void signup();
int mainmenu();

typedef struct{
    int empid;
    char empname[51];
    char empdesig[51];
} Cover;
Cover c;
FILE *cov;

inline void setFontSize(int a, int b)

{

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();

    lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);

    GetCurrentConsoleFontEx(hStdOut, 0, lpConsoleCurrentFontEx);

    lpConsoleCurrentFontEx->dwFontSize.X = a;

    lpConsoleCurrentFontEx->dwFontSize.Y = b;

    SetCurrentConsoleFontEx(hStdOut, 0, lpConsoleCurrentFontEx);

};

void signin()
{
    int i=0, j=0, x1=30, y1=5, x2=115, y2=30;
    char user[51], p[51], ch, noyes;
    system("cls");
    system("COLOR E0");
    rect(x1,y1,x2,y2);
    gotoxy(55, 10);
    printf("______________LOGIN______________");
    gotoxy(55, 12);
    printf("Enter Your Username: "); fflush(stdin); scanf("%s", &user);
    if (user == NULL)
    {
        optionn();
    }
    gotoxy(55, 14);
    printf("Enter mobile number: "); fflush(stdin); scanf("%10s", &l.phno);
    if (l.phno == NULL)
    {
        optionn();
    }
    gotoxy(55, 16);
    printf("Enter City Name: "); fflush(stdin); scanf("%s", &l.city);
    gotoxy(55, 18);
    printf("Enter Your Password: "); fflush(stdin);
    while(i<50){
		ch=getch();
		if(ch==13) break;
		else if(ch==8){
			if(i>0)
			{
				int n;
				i--;
				gotoxy(55,14); printf(""); //clear till end of line
				for(n=0;n<i;n++) putchar('*');
			}
		}
		else{
			p[i]=ch;
			putchar('*');
			i++;
		}
	}
	p[i]='\0';
    rewind(logi);
    while(fread(&l,sizeof(l),1,logi))
    {
        if(strcmp(l.id,user)==0 && strcmp(l.pass,p)==0)
        {
            j+=1;
            break;
        }
    }
    if(j)
    {
        gotoxy(55, 20);
        printf("Welcome...");
        gotoxy(55, 22);
        system("pause");
        mainmenu();
    }
    else
    {
        gotoxy(55, 20);
        printf("Invalid Details...");
        gotoxy(55, 22);
        printf("Do You Want To Re-enter [y/n]: "); fflush(stdin); scanf("%c", &noyes);
        if (noyes=='y' || noyes=='Y'){
            signin();
        }
        else if (noyes == 'n' || noyes == 'N')
        {
            optionn();
        }
        else
        {
            signin();
        }
        gotoxy(55, 23);
        system("pause");
        signin();

    }

}

void signup()
{
    int k, x1=30, y1=5, x2=115, y2=30;
    char name[64];
    system("cls");
    system("COLOR E0");
    rect(x1,y1,x2,y2);
    gotoxy(63, 10);
    printf("***********************");
    gotoxy(63, 11);
    printf("* CREATE YOUR ACCOUNT *");
    gotoxy(63, 12);
    printf("***********************");
    gotoxy(60, 14);
    printf("Enter Username: "); fflush(stdin); scanf("%s", &l.id);
    gotoxy(60, 16);
    printf("Enter mobile number: "); fflush(stdin); scanf("%s", &l.phno);
    gotoxy(60, 18);
    printf("Enter City Name: "); fflush(stdin); scanf("%s", &l.city);
    gotoxy(60, 20);
    printf("Enter Password: "); fflush(stdin); scanf("%s", &l.pass);

    gotoxy(60, 22);

    fseek(logi,0,SEEK_END);
    fwrite(&l,sizeof(l),1,logi);
    gotoxy(60, 24);
    printf("Account created!");
    gotoxy(60, 26);
    system("pause");
    signin();
}

void optionn()
{
    char opt;
    int x1=30, y1=5, x2=115, y2=30;
    system("cls");
    system("COLOR 0E");

    rect(x1,y1,x2,y2);
    gotoxy(63, 10);
    printf("***********************");
    gotoxy(63, 11);
    printf("*       WELCOME       *");
    gotoxy(63, 12);
    printf("***********************");
    gotoxy(70, 16);
    printf("SignUp");
    gotoxy(70, 18);
    printf("LogIn");
    gotoxy(70, 20);
    printf("Quit");
    gotoxy(60, 24);
    printf("Enter Your Option [S/L/Q]: "); scanf("%c", &opt);
    if (opt =='s' ||opt =='S' ||opt =='l' ||opt =='L' ||opt =='q' ||opt =='Q'){
        gotoxy(62, 24);
    switch(opt)
    {
        case 's': case 'S': signup(); break;
        case 'l': case 'L': signin(); break;
        case 'q': case 'Q': fclose(logi); fclose(cov); fclose(emp); exit(0);
        default: printf("Wrong Choice...");
        gotoxy(62, 26);
        system("pause");
    }
    }
    else
    {
        optionn();
    }


}
void logout()
{
    optionn();
}

int mainmenu()
{
    char choi;
    int x1=30, y1=5, x2=115, y2=30;
    system("cls");
    rect(x1,y1,x2,y2);
    system("COLOR 0E");
    gotoxy(65, 8);
    printf("*************");
    gotoxy(65, 9);
    printf("* Main Menu *");
    gotoxy(65, 10);
    printf("*************");

    gotoxy(60, 14);
    printf("Employee Management System");
    gotoxy(60, 16);
    printf("Student Management System");
    gotoxy(60, 18);
    printf("Logout");
    gotoxy(60, 20);
    printf("Quit");
    gotoxy(60, 22);
    printf("Enter Your Option: "); scanf("%c", &choi);
    if (choi == 'e' || choi == 'E' || choi == 's' || choi == 'S' || choi == 'l' || choi == 'L' || choi == 'q' || choi == 'Q'){
        gotoxy(60, 24);
    switch(choi)
    {
        case 'e': case 'E': empstart(); break;
        case 's': case 'S': work2(); break;
        case 'l': case 'L': logout(); break;
        case 'q': case 'Q': fclose(logi); fclose(cov); fclose(emp); exit(0);
        default: printf("Wrong Choice...");
        gotoxy(60, 26);
        system("pause");
    }
    }
    else
    {
        mainmenu();
    }

}

int main()
{
    int choice, i, x1=5, y1=0, x2=27, y2=6;
    cov = fopen("cover.dat","rb+");
    if (cov == NULL) cov = fopen("cover.dat","wb+");
    logi = fopen("signindetails.dat","rb+");
    if (logi == NULL) logi = fopen("signindetails.dat","wb+");
    emp = fopen("emp.dat", "rb+");
    if(emp==NULL) emp = fopen("emp.dat", "wb+");
    rect(x1,y1,x2,y2);
    system("COLOR E0");
    gotoxy(13,2);
    setFontSize(5,100);

    printf("\e[?25l");
    printf("COLLEGE");
    for (i = 0; i < 3; i++)
    {
        printf("");
        Sleep(500);
    }
    system("cls");
    rect(x1,y1,x2,y2);
    gotoxy(12,2);
    system("COLOR 0E");
    printf("MANAGEMENT");
    for (i = 0; i < 3; i++)
    {
        printf("");
        Sleep(500);
    }
    system("cls");
    rect(x1,y1,x2,y2);
    gotoxy(13,2);
    system("COLOR E0");
    printf("SYSTEM");
    for (i = 0; i < 3; i++)
    {
        printf("");
        Sleep(500);
    }
    setFontSize(2,20);
    system("cls");
    for (;;)
    {
        system("cls");

        printf("\e[?25l");
        optionn();

        system("cls");
        mainmenu();
        }
    }

