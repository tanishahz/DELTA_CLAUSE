// NUMBER GUESSING GAME
#include<stdio.h>
int main()
{
    int num,hidden = 67;
    printf("Enter the number : ");
    scanf("%d",&num);
    while(num!=hidden)
    {
        if(num > hidden )
        {
            printf("Please decries your number\n");
        }
        if(num < hidden )
        {
            printf("Please  increase your number\n");
        }
        printf("Enter new Number : ");
        scanf("%d",&num);
    }
    printf("You Got the correct Value");
    return 0;
}