#include <stdio.h>
#include <windows.h>
#include "test1.h"
#include "test2.h"
#include "delay.h"
#include "close.h"

int i,k,choice,j=200000000;
int main_exit;
void menu(void);
void new_acc(void);
void view_list(void);
void edit(void);
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
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tEnter the password to login:");
    scanf("%s",pass);

    if (strcmp(pass,password)==0)
        {
            printf("\n\nPassword Match!\nLOADING");
            for(i=0;i<=6;i++)
                {
                    fordelay(100000000);
                    printf(".");
                }
            menu();
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
                    printf("Working close");
                }
            else
                {
                    printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;
                }
        }
    return 0;
}


void menu(void)
{
    system("cls");
    printf("\n\n\n\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\n\t\t\t\t1.Create new account\n\t\t\t\t2.Update information of existing account\n\t\t\t\t3.For transactions\n\t\t\t\t4.Check the details of existing account\n\t\t\t\t5.Removing existing account\n\t\t\t\t6.View customer's list\n\t\t\t\t7.Exit\n\n\n\t\t\t\t\t Enter your choice:");
    scanf("%d",&choice);
    for(i=0;i<j;i++)
    {
        k=i;
    }
    //system("color 07");
    switch(choice)
    {
        case 1:
            new_acc();
            break;
        case 2:
            edit();
            break;
        /*
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;*/
        case 6:view_list();
        break;
        case 7:close();
        break;
    }
}

void new_acc(void)
{
    int i=0;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2\xB2 ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {
                printf("Account no. already in use!");
                fordelay(1000000000);
                goto account_no;
            }
    }
    add.acc_no=check.acc_no;
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);
    fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");

    if (main_exit==1)
        menu();
    else if(main_exit==0)
        close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
    {
        system("cls");
        printf("\nNO RECORDS!!\n");}

        view_list_invalid:
        printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");

        if (main_exit==1)
        {
            menu();
        }
        else if(main_exit==0)
        {
            close();
        }
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}


void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   
            test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {
                    printf("Enter the new address:");
                    scanf("%s",upd.address);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    system("cls");
                    printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                    scanf("%lf",&upd.phone);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    system("cls");
                    printf("Changes saved!");
                }
        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

    if(test!=1)
        {   
            system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
            printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
            scanf("%d",&main_exit);
            system("cls");
            if (main_exit==1)
            {
                menu();
            }
            else if (main_exit==2)
            {
                close();
            }
            else if(main_exit==0)
            {
                edit();
            }
            else
            {
                printf("\nInvalid!\a");
                goto edit_invalid;
            }
        }
    else
        {
            printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&main_exit);
            system("cls");
            if (main_exit==1)
            menu();
        else
            close();
        }
}