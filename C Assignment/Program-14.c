#include <stdio.h>
#include <string.h>

int main()
{
    int i, index, pangram=1;
    int freq[26]={0};
    char str[100];
    
    printf("Enter a string:");
    scanf(" %[^\n]", str);
    
    for(i=0; str[i] !='\0'; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            index = str[i] - 'A';
            freq[index] = 1;
        }
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            index = str[i] - 'a';
            freq[index] = 1;
        }
    }
    
    for(i=0; i<26; i++)
    {
        if(freq[i] == 0)
        {
            pangram=0;
            break;
        }
    }
    
    if(pangram)
    {
        printf("The string is a Pangram.");
    }
    else
    {
        printf("The string is not a Pangram.");
    }

    return 0;
}