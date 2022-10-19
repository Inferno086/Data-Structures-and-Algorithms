#include <iostream>
using namespace std;

void display(int *A, int n)
{
    cout << "The array is : ";
    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void selectionSort(int* A, int n)
{
    int min, minIndex, temp;
    for(int i = 0; i < n - 1; i++)
    {
        min = A[i];
        minIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(A[j] < min)
            {
                minIndex = j;
                min = A[j];
            }
        }
        temp = A[i];
        A[i] = min;
        A[minIndex] = temp;
    }
}

int main()
{
    int A1[] = {1,4,2,6,4,7,5,3,4};
    int n1 = 9;

    int A2[] = {54,34,67,23,85,33,67,22,9,6,13,67};
    int n2 = 12;

    display(A1, n1);
    selectionSort(A1, n1);
    display(A1, n1);

    display(A2, n2);
    selectionSort(A2, n2);
    display(A2, n2);
    return 0;
}