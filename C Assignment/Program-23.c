#include <stdio.h>

int main()
{
    int arr[100], temp[100];
    int size, pos;
    char dir;
    
    printf("Enter array size:");
    scanf("%d", &size);
    
    printf("Enter array elements:");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter number of position to rotate:");
    scanf("%d", &pos);
    
    printf("Enter direction (L for Left and R for Right):");
    scanf(" %c", &dir);
    
    pos = pos % size;
    
    if(dir == 'L' || dir == 'l')
    {
        for(int i=0; i<size; i++)
        {
            temp[i] = arr[(i + pos) % size];
        }
    } 
    else if(dir == 'R' || dir == 'r')
    {
        for(int i=0; i<size; i++)
        {
            temp[(i + pos) % size] = arr[i];
        }
    }
    else
    {
        printf("Invalid direction.");
        return 0;
    }
    
    printf("Rotated array:\n");
    
    for(int i=0; i<size; i++)
    {
        printf("%d ", temp[i]);
    }
    
    return 0;
}