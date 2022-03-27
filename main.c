#include "headers.h"

void main()
{
    char pass[20],password[20]="surya";
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tEnter the password to login:");
    scanf("%s",pass);

    if (strcmp(pass,password)==0)
        {
            printf("\n\nPassword Match!\nLOADING");
            for(i=0;i<=6;i++)
                {
                    delay(100000000);
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
                    delay(1000000000);
                    system("cls");
                    goto login_try;
                }
        }
}