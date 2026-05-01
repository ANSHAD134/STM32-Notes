#include <stdio.h>

void CountDigit(int num, int freq[])
{
    if(num<0)
    {
        num=-num;
    }
    
    if(num==0)
    {
        freq[0]++;
        return;
    }
    
    while(num>0)
    {
        int digit=num%10;
        freq[digit]++;
        num=num/10;
    }
}

int main()
{
    int num;
    int freq[10]={0};
    
    printf("Enter the integer:");
    scanf("%d", &num);
    
    CountDigit(num, freq);
    
    printf("Digit frequences:\n");
    for(int i=0; i<10; i++)
    {
        printf("%d -> %d times\n", i, freq[i]);
    }
    return 0;
}