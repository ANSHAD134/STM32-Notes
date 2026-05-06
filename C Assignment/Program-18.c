#include <stdio.h>

int main()
{
    int num, pos, n, result;
    
    printf("Enter the number:");
    scanf("%d", &num);
    
    printf("Enter starting position:");
    scanf("%d", &pos);
    
    printf("Enter number of bits to Retrive:");
    scanf("%d", &n);
    
   result = num >> pos;
   
   result = result & ((1 << n) - 1);
    
    printf("Extracted bits: %d\n", result);

    return 0;
    
}