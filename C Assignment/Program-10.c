#include <stdio.h>

int main()
{
    unsigned int num = 0;
    char str[100];
    
    printf("Enter the number:");
    scanf("%s", str);
    
    for(int i=0; str[i] !='\0'; i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            num = num * 10 + (str[i] - '0');
        }
        else
        {
            printf("Invalid input.");
            return 0;
        }
    }
    
    printf("The integer value is:%u\n", num);
    
    return 0;
}