// PALINDROME CHECKER
#include<stdio.h>
#include<string.h>
int main()
{
    char str[20];
    printf("Enter the string : ");
    scanf("%s",&str);
    int len = strlen(str);
    int i;
    for(i=0;i<len;i++)
    {
        if(str[i] != str[len-1-i])
        {
            printf("Not a palindrome string \n");
            return 0;
        }
    }
    printf("Yes this string is a palindrome string\n");
    return 0;
}