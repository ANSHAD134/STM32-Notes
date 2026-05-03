#include <stdio.h>

int main()
{
    int num, i=0, negative=0;
    char str[50];
    
    printf("Enter the number:");
    scanf("%d", &num);
    
    if(num < 0)
    {
        negative = 1;
        num = -num;
    }
    
    if(num == 0)
    {
        str[i++] = '0';
    }
    
    while(num>0)
    {
        int digit = num % 10;
        str[i++] = digit + '0';
        num = num / 10;
    }
    
    if(negative)
    {
        str[i++] = '-';
    }
    
    str[i] = '\0';
    
    for(int j=0; j<i/2; j++)
    {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
    
    printf("String form:%s\n", str);
    
    return 0;
}