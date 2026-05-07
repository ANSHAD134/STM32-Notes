#include <stdio.h>

int main()
{
    int num1, num2, pos, n;
    
    printf("Enter Two numbers:");
    scanf("%d %d", &num1, &num2);
    
    printf("Enter the position:");
    scanf("%d", &pos);
    
    printf("Enter number of bits for Swap:");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
    {
        int bit1 = ((num1 >> (pos + i))& 1);
        
        int bit2 = ((num2 >> (pos + i))& 1);
        
        if(bit1 != bit2)
        {
            num1 = num1 ^ (1 << (pos + i));
            num2 = num2 ^ (1 << (pos + i));
        }
    }
    
    printf("After Swapping bits\n");
    printf("First number = %d\n", num1);
    printf("Second number = %d\n", num2);

    return 0;
}