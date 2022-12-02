#include<iostream>
using namespace std;

void display(int* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int partition(int* arr, int lb, int ub)
{
    int pivot, start, end;
    pivot = arr[lb];
    start = lb;
    end = ub;

    while(start < end)
    {
        while(arr[start] <= pivot)
        {
            start++;
        }

        while(arr[end] > pivot)
        {
            end--;
        }
        if(start < end)
        {
            swap(arr[start], arr[end]);
        }
    }

    swap(arr[lb], arr[end]);

    return end;
}

void quickSort(int* arr, int lb, int ub)
{
    if(lb < ub)
    {
        int loc;
        loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc - 1);
        quickSort(arr, loc + 1, ub);
    }
}

int main()
{
    const int n = 8;
    int marks[n] = {43, 37, 5, 29, 74, 65, 65, 5};
    cout << "Quick Sort :- \n";
    display(marks, n);
    quickSort(marks, 0, 7);
    display(marks, n);
    return 0;
}