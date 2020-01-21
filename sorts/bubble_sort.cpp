#include <bits/stdc++.h>

using namespace std;

void bubble_sort(int arr[], int size)
{
    //flag for sorted list
    bool is_sorted;
    for (int i = 0; i < size - 1; ++i)
    {
        is_sorted = true;
        for (int j = 0; j < size - 1 - i; ++j)
        {
            //swapping
            if (arr[j] > arr[j + 1])
            {
                is_sorted = false;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (is_sorted)
            break;
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
    bubble_sort(arr, 8);

    print(arr, 8);
    return 0;
}