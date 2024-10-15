#include <iostream>
using namespace std;

// Merge function to merge three sorted subarrays
void merge(int arr[], int s, int q, int q2, int f)
{
    int n1 = q - s + 1;
    int n2 = q2 - q;
    int n3 = f - q2;

    // Temporary arrays for left, middle, and right subarrays
    int left[n1], middle[n2], right[n3];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        left[i] = arr[s + i];
    for (int i = 0; i < n2; i++)
        middle[i] = arr[q + 1 + i];
    for (int i = 0; i < n3; i++)
        right[i] = arr[q2 + 1 + i];

    int i = 0, j = 0, k = 0, l = s;

    // Merge three arrays back into arr[s..f]
    while (i < n1 && j < n2 && k < n3)
    {
        if (left[i] <= middle[j] && left[i] <= right[k])
            arr[l++] = left[i++];
        else if (middle[j] <= left[i] && middle[j] <= right[k])
            arr[l++] = middle[j++];
        else
            arr[l++] = right[k++];
    }

    // Merge remaining elements of left and middle
    while (i < n1 && j < n2)
    {
        if (left[i] <= middle[j])
            arr[l++] = left[i++];
        else
            arr[l++] = middle[j++];
    }

    // Merge remaining elements of middle and right
    while (j < n2 && k < n3)
    {
        if (middle[j] <= right[k])
            arr[l++] = middle[j++];
        else
            arr[l++] = right[k++];
    }

    // Merge remaining elements of left and right
    while (i < n1 && k < n3)
    {
        if (left[i] <= right[k])
            arr[l++] = left[i++];
        else
            arr[l++] = right[k++];
    }

    // Copy remaining elements
    while (i < n1)
        arr[l++] = left[i++];
    while (j < n2)
        arr[l++] = middle[j++];
    while (k < n3)
        arr[l++] = right[k++];
}

// Three-way merge sort function
void merge_sort_three(int arr[], int s, int f)
{
    if (f - s < 1) // Base case: when the subarray has one or no elements
        return;

    int q = s + (f - s) / 3;
    int q2 = s + 2 * (f - s) / 3;

    // Recursively sort three parts
    merge_sort_three(arr, s, q);
    merge_sort_three(arr, q + 1, q2);
    merge_sort_three(arr, q2 + 1, f);

    // Merge the three sorted parts
    merge(arr, s, q, q2, f);
}

int main()
{
    int arr_unsorted[] = {22, 4};
    int n = sizeof(arr_unsorted) / sizeof(int);

    merge_sort_three(arr_unsorted, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr_unsorted[i] << " ";
    }

    return 0;
}
