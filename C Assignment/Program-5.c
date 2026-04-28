#include <stdio.h>

int perfect(int n)
{
    int i, sum=0;
    for(i=1;i<n;i++)
    {
        if(n%i==0)
        {
            sum=sum+i;
        }
    }
    return sum;
}

int main()
{
    int num;
    printf("Enter the number:");
    scanf("%d", &num);
    
    if(num<=0)
    {
        printf("Invalid number.\n");
        printf("Enter Postivie number.");
        return 0;
    }
    
    if(perfect(num)==num)
    {
        printf("It is a Perfect number.");
    }
    else
    {
        printf("It is Not a Perfect number.");
    }
    return 0;
}