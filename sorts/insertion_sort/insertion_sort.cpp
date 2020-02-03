#include <bits/stdc++.h>

using namespace std;

void insertion_sort(int arr[], int size)
{
    int j, x;
    for (int i = 1; i < size - 1; ++i)
    {
        j = i - 1;
        x = arr[i];
        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = {3, 7, 5, 6, 4, 10, 8, 66};
    insertion_sort(arr, 8);

    print(arr, 8);
    return 0;
}