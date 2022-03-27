int i,k,temp,choice,j;
int main_exit;

struct date{
    int month,day,year;

    };
struct done{

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