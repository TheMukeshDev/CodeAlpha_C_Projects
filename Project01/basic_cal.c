#include <stdio.h>
#include <math.h>

int main(void)
{
    double num1, num2;
    char operator;
    const double EPS = 1e-12; 
    int choice = 0;
    int running = 1;

    printf("Basic calculator (Addition, Subtraction, Multiplication & Division)\n");

    while (running) {
        printf("\nMenu:\n");
        printf(" 1) Calculate\n");
        printf(" 2) Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter 1st Number:\t ");
                scanf("%lf", &num1);
                printf("Enter 2nd Number:\t ");
                scanf("%lf", &num2);

                printf(" + for addition\n - for subtraction\n * for multiplication\n / for division\n Enter Operator sign : ");
                scanf(" %c", &operator);

                switch (operator) {
                    case '+':
                        printf(" Addition of %.6g %c %.6g = %.6g\n", num1, operator, num2, num1 + num2);
                        break;
                    case '-':
                        printf(" Subtraction of %.6g %c %.6g = %.6g\n", num1, operator, num2, num1 - num2);
                        break;
                    case '*':
                        printf(" Multiplication of %.6g %c %.6g = %.6g\n", num1, operator, num2, num1 * num2);
                        break;
                    case '/':
                        if (fabs(num2) < EPS) {
                            printf("Error: Cannot divide by zero (or value too close to zero).\n");
                        } else {
                            printf(" Division of %.6g %c %.6g = %.6g\n", num1, operator, num2, num1 / num2);
                        }
                        break;
                    default:
                        printf("Invalid operator '%c'. Use +, -, * or /.\n", operator);
                        break;
                }
                break;
            case 2:
                running = 0;
                break;
            default:
                printf("Invalid menu option. Please enter 1 or 2.\n");
                break;
        }
    }

    printf("Exiting calculator. Goodbye.\n");
    return 0;
}
