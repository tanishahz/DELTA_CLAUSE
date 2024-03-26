// RANDOM PASSWORD GENERATOR
#include <stdio.h>
#include <string.h>
int main()
{
    char name[20];
    long long int mobile;
    int YearOfBirth, i, len, r;
    char password[10];
    printf("Enter the Name : ");
    gets(name);
    printf("Enter the mobile number : ");
    scanf("%lld", &mobile);
    printf("Enter the year of birth : ");
    scanf("%d", &YearOfBirth);
    len = strlen(name);
    for (i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
        {
            password[i] = name[len - 1 - i];
        }
        else
        {
            password[i] = name[i];
        }
    }
    for (i = 4; i < 6; i++)
    {
        r = YearOfBirth % 10;
        password[i] = r + 48 - 15;
        YearOfBirth = YearOfBirth / 10;
    }
    for (i = 6; i < 10; i++)
    {
        r = mobile % 10;
        password[i] = r + 48 + 2;
        mobile = mobile / 10;
    }
    password[10] = '\0';
    printf("Password is : %s", password);
    return 0;
}