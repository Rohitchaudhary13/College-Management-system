#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#define Student struct Stud

void titlee();
void rect(int x1,int y1,int x2, int y2);
void add(FILE *fp);
void modify(FILE *fp);
void display(FILE *fp);
void Indivisual(FILE *fp);
void password();
FILE *del(FILE *fp);
void printChar(char ch, int n);
void title();
FILE *tp;
FILE *logi;
typedef struct{
    int recordno;
    char id[51], pass[51], city[51], phno[11];
}login;
login l;

struct pass
{
    char pass[25];
} pa;

struct Stud
{
    char name[100];
    char dept[50];
    int roll;
    float sgpa[12];
    float cgpa;
};

int work2()
{
    int ch, id, k, i, x1=30, y1=5, x2=115, y2=30;
    char c, pas[50];
    system("cls");
    SetConsoleTitle("Student Management System | DIU");
    FILE *fp;
    Student s;
    char option;
    char another;

    if ((fp = fopen("db.txt", "rb+")) == NULL)
    {
        if ((fp = fopen("db.txt", "wb+")) == NULL)
        {
            printf("Can't create or open Database.");
            return 0;
        }
    }
    logi = fopen("loginn.dat","rb+");
    if (logi == NULL) logi = fopen("loginn.dat","wb+");

        system("cls");
        system("color 30");
        rect(x1,y1,x2,y2);
        gotoxy(60, 10);
        printf("<<<< Loading Please Wait >>>>");
        gotoxy(62, 12);
        for (i = 0; i < 5; i++)
        {

            printf("(*_*)");
            Sleep(500);
        }
        gotoxy(63, 14);
        printf("*  *  *  *  *  *  *  *");
        gotoxy(63, 16);
        printf("*                    *");
        gotoxy(63, 18);
        printf("*       Welcome      *");
        gotoxy(63,20);
        printf("*                    *");
        gotoxy(63, 22);
        printf("*  *  *  *  *  *  *  *");
        gotoxy(60, 24);
        system("pause");
        system("cls");
        titlee();
        system("COLOR 03");
        rect(x1,y1,x2,y2);
        gotoxy(65, 12);
        printf("MICRO PROJECT 2021");
        gotoxy(68, 14);
        printf("THE HEXCLAN");
        gotoxy(63, 16);
        printf("ABES ENGINEERING COLLEGE");
        gotoxy(56, 18);
        printChar('=', 38);
        gotoxy(61, 20);
        system("pause");

        while (1)
        {
            titlee();
            system("COLOR 03");
            rect(x1,y1,x2,y2);

            gotoxy(60, 12);
            printf("Add Student");
            gotoxy(60, 14);
            printf("Modify Student");
            gotoxy(60, 16);
            printf("Show All Student");
            gotoxy(60, 18);
            printf("Individual View");
            gotoxy(60, 20);
            printf("Remove Student");
            gotoxy(60, 22);
            printf("Change Password");
            gotoxy(60, 24);
            printf("Logout");

            gotoxy(60, 26);
            printf("Enter Your Option :--> ");
            scanf("%s", &option);

            switch (option)
            {
            case 'a': case 'A':
                add(fp);
                break;
            case 'm': case 'M':
                modify(fp);
                break;
            case 's': case 'S':
                display(fp);
                break;
            case 'i': case 'I':
                Indivisual(fp);
                break;
            case 'r': case 'R':
                fp = del(fp);
                break;
            case 'c': case 'C':
                system("cls");
                system("color 5f");
                password();
                break;
            case 'l': case 'L':
                return 1;
                break;
            default:gotoxy(48, 29);
                printf("No Action Detected");
                gotoxy(48, 31);
                printf("Press Any Key");
                getch();
                system("pause");
            }
        }
    }


void password()
{
    char c;
    printf("\nEnter new password :");
    fflush(stdin);
    gets(pa.pass);
    printf("\nSave password (y/n) :");
    fflush(stdin);
    scanf("%c", &c);
    if (c == 'y' || c == 'Y')
    {
        tp = fopen("F:/Password.txt", "w+");
        fwrite(&pa, sizeof(pa), 1, tp);
        fclose(tp);
        printf("\n\tPassword Saved\n");
    }
    else
    {
        printf("Password not saved :\n");
        printf("Press any key to continue >>>");
        getch();
    }
}

void printChar(char ch, int n)
{
    while (n--)
    {
        putchar(ch);
    }
}

void titlee()
{
    system("cls");

    gotoxy(60, 6);
    /*printf("\n\n\t");*/
    printf("*******************************");
    gotoxy(60, 7);
    printf("*  STUDENT MANAGEMENT SYSTEM  *");
    gotoxy(60, 8);
    printf("*******************************");

}

/*Insert at end*/

void add(FILE *fp)
{
    int x1=30, y1=5, x2=115, y2=30, j=17;
    titlee();

    char another = 'y';
    Student s;
    int i;
    float cgpa;

    fseek(fp, 0, SEEK_END);
    while (another == 'y' || another == 'Y')
    {
        rect(x1,y1,x2,y2);
        gotoxy(50,10);
        printf("Enter Full Name of Student: ");
        fflush(stdin);
        fgets(s.name, 100, stdin);
        s.name[strlen(s.name) - 1] = '\0';
        gotoxy(50,12);
        printf("Enter Department Name: ");
        fflush(stdin);
        fgets(s.dept, 50, stdin);
        s.dept[strlen(s.dept) - 1] = '\0';
        gotoxy(50,14);
        printf("Enter Roll number: ");
        scanf("%d", &s.roll);
        gotoxy(50,16);
        printf("Enter SGPA for 12 semesters: ");

        for (i = 0, cgpa = 0; i < 12; i++)
        {
            gotoxy(50,j);
            scanf("%f", &s.sgpa[i]);
            cgpa += s.sgpa[i];
            j++;
        }

        cgpa /= 12.0;
        s.cgpa = cgpa;

        fwrite(&s, sizeof(s), 1, fp);

        printf("\n\n\t\tAdd another student?(Y/N)?");
        fflush(stdin);
        another = getchar();
    }
}

FILE *del(FILE *fp)
{
    titlee();

    Student s;
    int flag = 0, tempRoll, siz = sizeof(s);
    FILE *ft;

    if ((ft = fopen("temp.txt", "wb+")) == NULL)
    {
        printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
        system("pause");
        return fp;
    }

    printf("\n\n\tEnter Roll number of Student to Delete the Record");
    printf("\n\n\t\t\tRoll No. : ");
    scanf("%d", &tempRoll);

    rewind(fp);

    while ((fread(&s, siz, 1, fp)) == 1)
    {
        if (s.roll == tempRoll)
        {
            flag = 1;
            printf("\n\tRecord Deleted for");
            printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t", s.name, s.dept, s.roll);
            continue;
        }

        fwrite(&s, siz, 1, ft);
    }

    fclose(fp);
    fclose(ft);

    remove("db.txt");
    rename("temp.txt", "db.txt");

    if ((fp = fopen("db.txt", "rb+")) == NULL)
    {
        printf("ERROR");
        return NULL;
    }

    if (flag == 0)
        printf("\n\n\t\tNO STUDENT FOUND WITH THE INFORMATION\n\t");

    printChar('-', 65);
    printf("\n\t");
    system("pause");
    return fp;
}

void modify(FILE *fp)
{
    int x1=30, y1=3, x2=115, y2=37, j=22;
    titlee();
    rect(x1,y1,x2,y2);

    Student s;
    int i, flag = 0, tempRoll, siz = sizeof(s);
    float cgpa;
    gotoxy(50,10);
    printf("Enter Roll Number of Student to MODIFY the Record : ");
    scanf("%d", &tempRoll);

    rewind(fp);

    while ((fread(&s, siz, 1, fp)) == 1)
    {
        if (s.roll == tempRoll)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        fseek(fp, -siz, SEEK_CUR);
        gotoxy(50,11);
        printf("Record Found");
        gotoxy(50,12);
        printChar('=', 38);
        gotoxy(50,14);
        printf("Student Name: %s", s.name);
        gotoxy(50,15);
        printf("Student Roll: %d", s.roll);
        gotoxy(50,16);
        printChar('=', 38);
        gotoxy(50,17);
        printf("Enter New Data for the student");
        gotoxy(50,18);
        printf("Enter Full Name of Student: ");
        fflush(stdin);
        fgets(s.name, 100, stdin);
        s.name[strlen(s.name) - 1] = '\0';
        gotoxy(50,19);
        printf("Enter Department: ");
        fflush(stdin);
        fgets(s.dept, 50, stdin);
        s.dept[strlen(s.dept) - 1] = '\0';
        gotoxy(50,20);
        printf("Enter Roll number: ");
        scanf("%d", &s.roll);
        gotoxy(50,21);
        printf("Enter SGPA for 12 semesters\n");
        for (i = 0, cgpa = 0; i < 12; i++)
        {
            gotoxy(50,j);
            scanf("%f", &s.sgpa[i]);
            cgpa += s.sgpa[i];
            j++;
        }
        cgpa /= 12.0;
        s.cgpa = cgpa;

        fwrite(&s, sizeof(s), 1, fp);
    }

    else{
        gotoxy(60,35);
        printf("!!!! ERROR !!!! RECORD NOT FOUND");}

    gotoxy(60,34);
    system("pause");
}

void display(FILE *fp)
{
    int j=8;
    system("cls");
    gotoxy(60, 3);
    /*printf("\n\n\t");*/
    printf("*******************************");
    gotoxy(60, 4);
    printf("*  STUDENT MANAGEMENT SYSTEM  *");
    gotoxy(60, 5);
    printf("*******************************");
    Student s;
    int i, siz = sizeof(s);

    rewind(fp);

    while ((fread(&s, siz, 1, fp)) == 1)
    {
        gotoxy(15, j);
        printf("NAME : %s", s.name);
        j=j+2;
        gotoxy(15, j);
        printf("Depertment : %s", s.dept);
        j=j+2;
        gotoxy(15, j);
        printf("ROLL : %d", s.roll);
        j=j+2;
        gotoxy(10, j);
        printf("SGPA: ");
         j=j+2;

        for (i = 0; i < 12; i++)
            printf("| %.2f |", s.sgpa[i]);
        gotoxy(15, j);
        printf("CGPA : %.2f\n\t", s.cgpa);
        j=j+2;
        gotoxy(5, j);
        printChar('-', 65);
        j=j+2;
    }
    printf("\n\n\n\t");
    printChar('*', 65);
    printf("\n\n\t");
    system("pause");
}

void Indivisual(FILE *fp)
{
    titlee();

    int tempRoll, flag, siz, i;
    Student s;
    char another = 'y';

    siz = sizeof(s);

    while (another == 'y' || another == 'Y')
    {
        printf("\n\n\tEnter Roll Number: ");
        scanf("%d", &tempRoll);

        rewind(fp);

        while ((fread(&s, siz, 1, fp)) == 1)
        {
            if (s.roll == tempRoll)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            printf("\n\t\tNAME : %s", s.name);
            printf("\n\n\t\tDepartment : %s", s.dept);
            printf("\n\n\t\tROLL : %d", s.roll);
            printf("\n\n\tSGPA: ");

            for (i = 0; i < 12; i++)
                printf("| %.2f |", s.sgpa[i]);
            printf("\n\n\t\tCGPA : %.2f\n\t", s.cgpa);
            printChar('-', 65);
        }
        else
            printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");

        printf("\n\n\t\tShow another student information? (Y/N)?");
        fflush(stdin);
        another = getchar();
    }
}
