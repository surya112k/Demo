void new_acc(void);
void view_list(void);
void edit(void);
void fordelay(int j);


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