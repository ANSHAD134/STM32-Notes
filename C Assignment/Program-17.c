#include <stdio.h>

int main()
{
    int num, pos, n;
    
    printf("Enter the number:");
    scanf("%d", &num);
    
    printf("Enter starting position:");
    scanf("%d", &pos);
    
    printf("Enter number of bits to Toggle:");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
    {
        num = num ^ (1<<(pos + i));
    }
    
    printf("Modified number: %d", num);

    return 0;
    
}