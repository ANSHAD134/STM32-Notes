#include <stdio.h>

int main()
{
    int n, prime=1;
    
    printf("Enter the number:");
    scanf("%d", &n);
    
   if(n<=1)
   {
       prime=0;
   }
   else
   {
        for(int i=2;i<n;i++)
        {
            if(n%i==0)
            {
                prime=0;
                break;
            }
        }
    }
    
    if(prime==1)
    {
        printf("It's a Prime number.");
    }
    else
    {
        printf("It's not a prime number.");
    }
    return 0;
}