// Calculator

#include <stdio.h>
int main()
{
    float a, b,calc=0;
    char ope;
    printf("Instructions : \n");
    printf("> Enter both values with operator in middle.\n");
    printf("> Must give space between them.\n");
    printf("> For e.g. = 6 + 5 then enter result = 11. \n");
    printf("> Then second time or later you only have to enter operator and second value.\n");
    printf("> for e.g. = * 2 then enter result = 22. \n");
    printf("> To Begin again press c 0 \n");
    printf("> To exit press e 0 \n\n\n");
    begin :
    printf("Enter : \n");
    scanf("%f %c %f", &a, &ope, &b);
    calc = a;
    while (1)
    {
        
        switch (ope)
        {
        case '+':
            calc = calc + b;
            printf("%.2f ", calc);
            getchar();
            scanf("%c %f",&ope, &b);
            break;
        case '-':
        calc = calc - b;
            printf("%.2f ", calc);
            getchar();
            scanf("%c %f",&ope, &b);
            break;
        case '*':
        calc = calc * b;
            printf("%.2f ", calc);
            getchar();
            scanf("%c %f",&ope, &b);
            break;
        case '/':
        calc = calc / b;
            printf("%.2f ", calc);
            getchar();
            scanf("%c %f",&ope, &b);
            break;
        case 'e':
        case 'E':
        goto ex;
        break;
        case 'c' :
        case 'C' :
        goto begin ;
        }
    }
    ex:
    return 0;
}
