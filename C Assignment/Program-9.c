#include <stdio.h>

float add(float num1 , float num2)
{
    return num1 + num2;
}

float Substract(float num1, float num2)
{
    return num1 - num2;
}

float Multiplay(float num1, float num2)
{
    return num1 * num2;
}

float divide(float num1, float num2)
{
    if(num2==0)
    {
        printf("Division Error.\n");
        return 0;
    }
    return num1 / num2;
}

float calculate(float num1, float num2, char op)
{
    switch (op) {
        case '+':
        return add(num1, num2);
        break;
        
        case '-':
        return Substract(num1, num2);
        break;
        
        case '*':
        return Multiplay(num1, num2);
        break;
        
        case '/':
        return divide(num1, num2);
        break;
    default:
        printf("Invalid OPerator");
        return 0;
    } 
}

int main()
{
    float num1, num2, result;
    char op;
    
    printf("Enter the Two float numbers:");
    scanf("%f %f", &num1, &num2);
    
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &op);
    
    result = calculate(num1, num2, op);
    
    printf("Result: %.2f", result);
    
    return 0;
}