#include <stdio.h>

int main()
{
    int num1, num2, pos, n, result;
    
    printf("Enter Two numbers:");
    scanf("%d %d", &num1, &num2);
    
    printf("Enter starting position:");
    scanf("%d", &pos);
    
    printf("Enter number of bits(n):");
    scanf("%d", &n);
    
    int mask = ((1 << n) -1) << pos;
    
    int cleared = num1 & ~mask;
    
    int bit = (num2 & ((1 << n) - 1)) << pos;
    
    result = cleared | bit;
    
    printf("Modified bit: %d\n", result);
    
    return 0;
    
}