#include <stdio.h>
#include <windows.h>
#include "test1.h"
#include "test2.h"

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void close(void)
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tThis C Mini Project is developed by Surya.K.M");
    for(int i=0;i<=6;i++)
    {
      fordelay(100000000);
      printf(".");
    }
}

int main()
{
    char pass[20],password[20]="surya";
    int i=0,a;
    int main_exit;
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
          a=menu();
          switch(a)
            {
              case 1:new_acc();
              break;
            }
          system("cls");
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