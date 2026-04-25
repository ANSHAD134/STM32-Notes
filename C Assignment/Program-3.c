#include <stdio.h>

int main()
{
    unsigned int n, i, factorial=1;
    
    printf("Enter the number:");
    scanf("%u", &n);
    
    if(n==0)
    {
        factorial = 1;
    }
    else
    {
        for(i=1; i<=n; i++)
        {
        factorial = factorial * i;
        }
    }
    
    printf("Factorial = %u", factorial);
    
    return 0;
}