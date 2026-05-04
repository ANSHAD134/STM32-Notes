#include <stdio.h>
#include <string.h>

int main()
{
    int i, len, flag=1;
    char str[100];
    
    printf("Enter a string:");
    scanf("%s", str);
    
    len = strlen(str);
    
    for(i=0; i<len/2; i++)
    {
        if(str[i] != str[len - i - 1])
        {
            flag=0;
            break;
        }
    }
    
    if(flag)
    {
        printf("The input is a Palindrome.");
    }
    else
    {
        printf("The input is not a palindrome.");
    }
    
    return 0;
}