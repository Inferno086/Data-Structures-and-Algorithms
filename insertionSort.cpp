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

void insertionSort(int A[], int n)
{
    int key, j;
    for(int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;

        while(A[j] > key && j >= 0)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    // Explanation of insertion  sort algorithm
    // Example
    // 0 1 2 3 4 5  -> inder
    // 1 3 6 2 5 4  -> array
    // For i = 3
    // key = A[3] = 2
    // j = 2
    // A[2] (6) > key (2) && j >= 0  ==> YES :-
    // A[j + 1] = A[j] => A[3] = A[2] (6)
    // 1 3 6 6 5 4
    // j-- :-
    // j = 1
    // A[1] (3) > key (2) && j >= 0  ==> YES :-
    // A[j + 1] = A[j] => A[2] = A[1] (3)
    // 1 3 3 6 5 4
    // j--
    // j = 0
    // A[0] (1) > key (2) && j >= 0  ==> NO :-
    // while loop stops
    // A[j + 1] = key => A[1] = 2 
    // 1 2 3 6 5 4

    int A1[] = {1,4,2,6,4,7,5,3,4};
    int n1 = 9;

    int A2[] = {54,34,67,23,85,33,67,22,9,6,13,67};
    int n2 = 12;

    display(A1, n1);
    insertionSort(A1, n1);
    display(A1, n1);

    display(A2, n2);
    insertionSort(A2, n2);
    display(A2, n2);
    return 0;
}