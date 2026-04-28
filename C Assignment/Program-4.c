#include <stdio.h>

int main()
{
    int n, fab=0, first=0, next=1;
    
    printf("Enter the number:");
    scanf("%d", &n);
    
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            fab=0;
        }
        else if(i==1)
        {
            fab=1;
        }
        else
        {
            fab=first+next;
            first=next;
            next=fab;
        }
    printf("%d ", fab);
    }
    return 0;
}