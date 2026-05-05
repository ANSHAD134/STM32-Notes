#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    char str[100];
    
    printf("Enter a string:");
    scanf(" %[^\n]", str);
    
    for(i=0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ' && str[i+1] == ' ')
        {
            for(j=i; str[j] != '\0'; j++)
            {
                str[j] = str[j+1];
            }
            i--;
        }
    }
    
    printf("Modified string = %s", str);
    
    return 0;
}