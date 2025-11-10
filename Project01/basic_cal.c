#include<stdio.h>

int main()
{
    int num1,num2;
    char operator;
    printf(" Basic calculator (Addition, Subtraction, Multiplication & Division)\n");
    printf("Enter 1st Number:\t ");
    scanf("%d",&num1);

    printf("Enter 2nd Number:\t ");
    scanf("%d",&num2);

    printf(" + for addition\n - for subtraction\n * for multiplication\n / for division\n Enter Operator sign : ");
    scanf(" %c",&operator);
    
    switch(operator)
        {
        case '+':
            printf(" Addition of %d %c %d = %d",num1,operator,num2,num1+num2);
            break;
        case '-':
            printf(" Subtraction of %d %c %d = %d",num1,operator,num2,num1-num2);
            break;
        case '*':
            printf(" Multiplication of %d %c %d = %d",num1,operator,num2,num1*num2);
            break;
        case '/':
            if (num2==0)
            {
                 printf("Error: Cannot divide by zero.");
            }
            else
            {
                printf(" Division of %d %c %d = %.2f",num1,operator,num2,(float) num1/num2);
            }
            break;
        default :
            printf("Invalid input ");
            break;
        }


    return 0;

}
