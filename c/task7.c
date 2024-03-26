// ATM SIMULATOR
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct customer
    {
        int accno;
        char name[30];
        float balance;
    };
    struct trans
    {
        int accno;
        char trans_type;
        float amount;
    };
    FILE *p,*q;
    int choice;
    struct customer c;
    struct trans t;
    while (1)
    {
        printf("1. Print all account data.\n");
        printf("2. Print Specific account data.\n");
        printf("3. Add Account.\n");
        printf("4. Close Account.\n");
        printf("5. Transaction  \n");
        printf("6. Exit\n");
        printf("==> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            p = fopen("CUSTOMER.DAT", "r");
            while (fread(&c, sizeof(c), 1, p) == 1)
            {
                printf("Account no. - %d\n", c.accno);
                printf("Customer Name - %s\n", c.name);
                printf("Customer Balance - %.2f\n\n", c.balance);
            }
            fclose(p);
        }
        break;
        case 2:
        {
            printf("Enter account no. - ");
            scanf("%d", &t.accno);
            p = fopen("CUSTOMER.DAT", "r");
            while (fread(&c, sizeof(c), 1, p) == 1)
            {
                if (t.accno == c.accno)
                {
                    printf("Account no. - %d\n", c.accno);
                    printf("Customer Name - %s\n", c.name);
                    printf("Customer Balance - %.2f\n\n", c.balance);
                }
            }
            fclose(p);
        }
        break;
        case 3:
        {
            p = fopen("CUSTOMER.DAT", "a");
            printf("Enter Account no. - ");
            scanf("%d",&c.accno);
            getchar();
            printf("Enter the name of customer - ");
            gets(c.name);
            printf("Enter opening balance - ");
            scanf("%f",&c.balance);
            if(c.balance<100)
            {
                printf("Minimum balance policy not match!\n");
            }
            else
            {
                fwrite(&c,sizeof(c),1,p);
                printf("Account added successfully!\n");
            }
            fclose(p);
        }
        break;
        case 4:
        {
            p = fopen("CUSTOMER.DAT","r");
            q = fopen("temp","w");
            printf("Enter the account no. - ");
            scanf("%d",&t.accno);
            while (fread(&c, sizeof(c), 1, p) == 1)
            {
                if(t.accno == c.accno)
                {
                    printf("Account delete successfully!\n");
                }
                else
                {
                    fwrite(&c,sizeof(c),1,q);
                }
            }
            fclose(p);
            fclose(q);
            remove("CUSTOMER.DAT");
            rename("temp","CUSTOMER.DAT");
        }
            break;
        case 5:
        {
            printf("Enter the account no. - ");
            scanf("%d",&t.accno);
            getchar();
            printf("Transaction type - ");
            scanf("%c",&t.trans_type);
            printf("Enter Amount - ");
            scanf("%f",&t.amount);
            p = fopen("CUSTOMER.DAT","r");
            q = fopen("temp","w");
            while (fread(&c, sizeof(c), 1, p) == 1)
            {
                if(t.accno == c.accno)
                {
                    if(t.trans_type == 'D' || t.trans_type == 'd')
                    {
                        c.balance +=  t.amount;
                        fwrite(&c,sizeof(c),1,q);
                        printf("Amount added Successfully\n");
                    }
                    if(t.trans_type == 'W' || t.trans_type == 'w')
                    {
                        c.balance -=  t.amount;
                        fwrite(&c,sizeof(c),1,q);
                        printf("Amount Withdraw Successfully\n");
                    }
                }
                else
                {
                    fwrite(&c,sizeof(c),1,q);
                }
            }
            fclose(p);
            fclose(q);
            remove("CUSTOMER.DAT");
            rename("temp","CUSTOMER.DAT");
        }
            break;
        case 6:
        exit(1);
        default:
            printf("Please enter a valid option\n");
        }
    }
    return 0;
}