#include <stdio.h>

void ConvertBase(int num, int base)
{
    int remainder, i=0;
    char result[100];
    
    if(num==0)
    {
        printf("0\n");
        return;
    }
    
    while(num>0)
    {
        remainder=num % base;
        
        if(remainder<10)
        {
            result[i]=remainder + '0';
        }
        else
        {
            result[i]=remainder - 10 + 'A';
        }
        num = num / base;
        i++;
    }
    printf("Converted number:");
    for(int j=i-1;j>=0;j--)
    {
        printf("%c", result[j]);
    }
    printf("\n");
}

int main()
{
    int num, base;
    
    printf("Enter decimal number:");
    scanf("%d", &num);
    
    printf("Enter base(2 to 16):");
    scanf("%d", &base);
    
    if((base<2) || (base>16))
    {
        printf("Invalid number\n");
        printf("Enter base(2 to 16)");
        return 0;
    }
    
    ConvertBase(num, base);

    return 0;
}