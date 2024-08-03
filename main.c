// a simple bank management system ig

#include <stdio.h>

void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
void deleteAccount();

struct 
{
    double num;
    char name[20];
    float bal; 
} acc;

int main()
{
    printf("%d",sizeof(acc.num));
    int choice;

    printf("Hey! What you wanna do? \n");
    printf("1. Create Account?\n");
    printf("2. Check Balance\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. delete Account\n");
    printf("6. Exit\n");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1: 
        createAccount();
        break;
    case 2: 
        depositMoney();
        break;
    case 3: 
        createAccount();
        break;
    case 4: 
        withdrawMoney();
        break;
    case 5: 
        deleteAccount();
        break;    
    case 6: 
        return 0;
        break;
    default:
        printf("Invalid input \n");  
        main();
        break;
    }
}

void createAccount()
{
    acc;
    FILE *f;
    f = fopen("Accounts.txt","w");

    printf("Enter Account number\n");
    scanf("%d",&acc.num);
    printf("Enter Name\n");
    scanf("%s",&acc.name);
    acc.bal = 0.0;

    fprintf(f, "{%d,\n%s,\n%.2f}",acc.num,acc.name,acc.bal);
    fclose(f);
}

void depositMoney()
{
    acc;
    double num;
    printf("Enter the amount you want to deposit\n");
    scanf("%lu",num);
    acc.bal += num;
}
void withdrawMoney()
{
    acc;
    double num;
    printf("Enter the amount you want to withdraw\n");
    scanf("%lu",num);
    acc.bal -= num;
}
void checkBalance()
{   
    acc;
    printf("%lu",acc.bal);
}
void deleteAccount()
{
    if(("Accounts.txt")!=NULL)
    printf("Account not found\n");

    else if(remove("Accounts.txt")==0)
    printf("Account deleted successfully\n");

    else
    printf("Account couldn't be deleted successfully\n");
}
