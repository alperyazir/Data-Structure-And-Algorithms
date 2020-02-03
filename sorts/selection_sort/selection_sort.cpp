#include <bits/stdc++.h>

using namespace std;

void selection_sort(int arr[], int size)
{
    int j;
    int k;

    for (int c = 0; c < size; ++c)
    {
        j = c;
        k = c;
        while (j < size)
        {
            if (arr[j] < arr[k])
                k = j;
            else
                j++;
        }
        // swapping
        int temp = arr[c];
        arr[c] = arr[k];
        arr[k] = temp;
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
    selection_sort(arr, 8);

    print(arr, 8);
    return 0;
}