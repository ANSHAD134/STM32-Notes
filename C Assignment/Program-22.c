#include <stdio.h>

int main()
{
    int arr[100], size;
    
    printf("Enter the array size:");
    scanf("%d", &size);
    
    if(size < 2)
    {
        printf("Need at least 2 elements.\n");
        return 0;
    }
    
    printf("Enter the numbers:");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int largest, secondLargest;
    int smallest, secondSmallest;

    if(arr[0] > arr[1])
    {
        largest = arr[0];
        secondLargest = arr[1];

        smallest = arr[1];
        secondSmallest = arr[0];
    }
    else
    {
        largest = arr[1];
        secondLargest = arr[0];

        smallest = arr[0];
        secondSmallest = arr[1];
    }
    
    for(int i = 2; i < size; i++)
    {
        if(arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }

        if(arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < secondSmallest && arr[i] != smallest)
        {
            secondSmallest = arr[i];
        }
    }
    
    if(largest == smallest)
    {
        printf("All elements are same.\n");
    }
    else
    {
        printf("Second Largest = %d\n", secondLargest);
        printf("Second Smallest = %d\n", secondSmallest);
    }

    return 0;
}