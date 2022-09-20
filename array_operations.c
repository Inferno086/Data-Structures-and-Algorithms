#include <stdio.h>
#include <conio.h>

void display(int array[], int size)
{
    printf("The array is : ");
    for(int i = 0; i < size; i++)
    {
        printf(" %d ", array[i]);
    }
    printf("\nThe size is : %d", size);
}

void Delete(int array[], int* size, int pos)
{
    for(int i = (pos - 1); i <= (*size - 2); i++)
    {
        array[i] = array[i + 1];
    }
    (*size)--; // This also deletes the last element if pos = size
}

void Insert(int array[], int* size, int num, int pos)
{
    for(int i = (*size - 1); i >= (pos - 1); i--)
    {
        array[i + 1] = array[i];
    }
    array[pos - 1] = num;
    (*size)++;
}

int main()
{
    // Declaration Section
    int array[50];
    int num, size, pos, pos2;

    // Taking size of array
    printf("Enter the size of array : ");
    scanf("%d", &size);
    printf("\n");

    // Taking values (elements) of array
    printf("Enter %d array elements : ", size);
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    // Displaying the array
    printf("\n");
    display(array, size);

    // Taking pos from user
    while(1)
    {
        printf("\nEnter the position for deletion : ");
        scanf("%d", &pos);
        if(pos <= size && pos > 0)
        {
            printf("\n");
            break;
        }
        else
        {
            printf("\nEnter correct position!");
        }
    }

    // Deleting the element array[pos - 1]
    Delete(array, &size, pos);
    
    // Displaying new array
    display(array, size);

    // Take pos2 for Insertion
    while(1)
    {
        printf("\nEnter the position for insertion : ");
        scanf("%d", &pos2);
        if(pos2 <= (size + 1) && pos2 > 0)
        {
            printf("\n");
            break;
        }
        else
        {
            printf("\nEnter correct position!");
        }
    }

    // Take num for Insertion
    printf("Enter the number to be inserted : ");
    scanf("%d", &num);
    printf("\n");

    // Insertion
    Insert(array, &size, num, pos2);

    // Displaying new array
    display(array, size);

    return 0;
}