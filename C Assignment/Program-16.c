#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    char str[100];
    
    printf("Enter a string:");
    scanf(" %[^\n]", str);
    
    for(i=0; str[i] != '\0'; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
    
    printf("Modified string = %s", str);
    
    return 0;
}