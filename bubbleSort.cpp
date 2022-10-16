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

void bubbleSort(int* A, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(A[j] > A[j + 1])
            {
                int temp;
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int* A, int n)
{
    int isSorted = 0;
    for(int i = 0; i < n - 1; i++)
    {
        isSorted = 1;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(A[j] > A[j + 1])
            {
                int temp;
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }

        if(isSorted)
        {
            return;
        }
    }
}

int main()
{
    int A1[] = {1,4,2,6,4,7,5,3,4};
    int n1 = 9;

    int A2[] = {54,34,67,23,85,33,67,22,9,6,13,67};
    int n2 = 12;

    display(A1, n1);
    bubbleSort(A1, n1);
    display(A1, n1);

    display(A2, n2);
    bubbleSortAdaptive(A2, n2);
    display(A2, n2);
    return 0;
}