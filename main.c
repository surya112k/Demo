#include <stdio.h>
#include <windows.h>
#include "test1.h"
#include "test2.h"
#include "delay.h"
#include "close.h"

int i,j;
int main_exit;
void menu(void);
struct date
{
    int month,day,year;
};
struct{
    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
    }add,upd,check,rem,transaction;


int main()
{
    char pass[20],password[20]="surya";
    printf("\n\n\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {
          printf("\n\nPassword Match!\nLOADING");
          system("cls");
          printf("Menu calling test1");
          for(i=0;i<=6;i++)
          {
            fordelay(100000000);
            printf(".");
          }
          system("cls");
          menu();
          close();
        }
    else
        {   
          printf("\n\nWrong password!!\a\a\a");
          login_try:
          printf("\nEnter 1 to try again and 0 to exit:");
          scanf("%d",&main_exit);
          if (main_exit==1)
            {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();
                    printf("Working close");}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}

void menu(void)
{
    int choice,i,k,j =200000000;
    system("cls");
    system("color F0");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    printf("\nThe choice is : %d",choice);
    for(i=0;i< j ;i++)
    {
        k=i;
    }
    system("color 07");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;/*
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:close();
        break;*/
    }
}