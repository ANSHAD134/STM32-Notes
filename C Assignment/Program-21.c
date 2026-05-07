#include <stdio.h>

int main()
{
    int arr[50], size;
    
    printf("Enter the size of array:");
    scanf("%d", &size);
    
    printf("Enter array elements:\n");
    
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for(int i=0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if(arr[i]==arr[j])
            {
                for(int k=j; k<size-1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                size--;
                j--;
            }
        }
    }
    
    printf("Array after removing duplicate:\n");
    
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    
}