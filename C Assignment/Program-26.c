#include <stdio.h>

int main()
{
    int arr[100], size, temp[100];
    int index = 0;
    
    printf("Enter array size:");
    scanf("%d", &size);

    printf("Enter array elements:");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for(int i=0; i<size; i++)
    {
        if(arr[i] < 0)
        {
            temp[index] = arr[i];
            index++;
        }
    }
    
    for(int i=0; i<size; i++)
    {
        if(arr[i] >= 0)
        {
            temp[index] = arr[i];
            index++;
        }
    }
    
    printf("Rearranged array:");
    
    for(int i=0; i<size; i++)
    {
        printf("%d ", temp[i]);
    }
    
    return 0;
}