#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} Account;
void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
int main() {
    int choice;
    while (1) {
        printf("\nBank Account Management System\n");
        printf("1. Create a new account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Check balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: checkBalance(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void createAccount() {
    Account acc;
    FILE *file = fopen("accounts.dat", "ab");

    printf("Enter account number: ");
    scanf("%d", &acc.accountNumber);
    printf("Enter name: ");
    scanf("%s", acc.name);
    acc.balance = 0.0;

    fwrite(&acc, sizeof(Account), 1, file);
    fclose(file);

    printf("Account created successfully!\n");
}
void depositMoney() {
    int accountNumber;
    float amount;
    Account acc;
    FILE *file = fopen("accounts.dat", "rb+");

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            acc.balance += amount;

            fseek(file, -sizeof(Account), SEEK_CUR);
            fwrite(&acc, sizeof(Account), 1, file);
            fclose(file);

            printf("Amount deposited successfully!\n");
            return;
        }
    }

    printf("Account not found!\n");
    fclose(file);
}
void withdrawMoney() {
    int accountNumber;
    float amount;
    Account acc;
    FILE *file = fopen("accounts.dat", "rb+");

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount > acc.balance) {
                printf("Insufficient balance!\n");
            } else {
                acc.balance -= amount;

                fseek(file, -sizeof(Account), SEEK_CUR);
                fwrite(&acc, sizeof(Account), 1, file);
                fclose(file);

                printf("Amount withdrawn successfully!\n");
                return;
            }
        }
    }

    printf("Account not found!\n");
    fclose(file);
}
void checkBalance() {
    int accountNumber;
    Account acc;
    FILE *file = fopen("accounts.dat", "rb");

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.accountNumber == accountNumber) {
            printf("Account Number: %d\n", acc.accountNumber);
            printf("Name: %s\n", acc.name);
            printf("Balance: %.2f\n", acc.balance);
            fclose(file);
            return;
        }
    }

    printf("Account not found!\n");
    fclose(file);
}
