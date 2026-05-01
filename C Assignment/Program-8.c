#include <stdio.h>

void ConvertBase(int num, int base, char result[])
{
    int remainder, i=0;
    
    if(num==0)
    {
        result[i++] = '0';
        result[i] = '\0';
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
    
    result[i] = '\0';
}

int main()
{
    int num, base, i=0;
    char result[100];
    
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
    
    ConvertBase(num, base, result);
    
   while(result[i] != '\0')
    {
        i++;
    }

    for(int j = i - 1; j >= 0; j--)
    {
        printf("%c", result[j]);
    }

    printf("\n");

    return 0;
}