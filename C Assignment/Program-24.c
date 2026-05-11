#include <stdio.h>

int main()
{
    int arr1[50], arr2[50], merged[100]; 
    int size1, size2;
    int i=0, j=0, k=0;

    printf("Enter first array size:");
    scanf("%d", &size1);
    
    printf("Enter first sorted array elements:");
    
    for(i=0; i<size1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    
    printf("Enter second array size:");
    scanf("%d", &size2);
    
    printf("Enter second sorted array elements:");
    
    for(i=0; i<size2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    
    i=0;
    j=0;
    
    while(i < size1 && j < size2)
    {
        if(arr1[i] <= arr2[j])
        {
            merged[k] = arr1[i];
            i++;
        }
        else
        {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }
    
    while(i < size1)
    {
        merged[k] = arr1[i];
        i++;
        k++;
    }
    
    while(j < size2)
    {
        merged[k] = arr2[j];
        j++;
        k++;
    }
    
    printf("Merged sorted array:");
    
    for(i=0; i<k; i++)
    {
        printf("%d ", merged[i]);
    }
    
    return 0;
}
