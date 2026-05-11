#include <stdio.h>

int main()
{
    int arr[100], size;
    int i, j, target;
    int found=0;
    
    printf("Enter array size:");
    scanf("%d", &size);
    
    printf("Enter array elements:");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter target sum:");
    scanf("%d", &target);
    
    printf("Pairs with %d are:", target);
    
    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(arr[i] + arr[j] == target)
            {
                printf("%d %d\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }
    
    if(found == 0)
    {
        printf("No Pairs found.");
    }
    
    return 0;
}
