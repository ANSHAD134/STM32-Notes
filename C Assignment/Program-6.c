#include <stdio.h>

int GcdNum(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return GcdNum(b, a%b);
    }
}

int main()
{
    int num1, num2, result;
    
    printf("Enter two positive number:");
    scanf("%d %d", &num1, &num2);
    
    if((num1<=0) || (num2<=0))
    {
        printf("Invalid Number.\n");
        printf("Enter Positive number.");
        return 0;
    }
    
    result = GcdNum(num1, num2);
    
    printf("GCD = %d", result);

    return 0;
}