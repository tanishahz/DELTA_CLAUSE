// TEMPERATURE CONVERSION
#include <stdio.h>
int main()
{
float f,c;
printf("Enter the temperature of city in Fahrenheit = ");
scanf("%f",&f);
c=(f-32)/1.8;     /*formula to convert Fahrenheit to Celsius */ 
printf("Temperature in centigrade = %.2f\n",c);
    return 0;
}