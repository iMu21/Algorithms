#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int lenOfLeftSubArray = mid - left + 1;
    int lenOfRightSubArray = right - mid;

    int leftSubArray[lenOfLeftSubArray];
    int rightSubArray[lenOfRightSubArray];

    for (int i = 0; i < lenOfLeftSubArray; i++)
        leftSubArray[i] = arr[left + i];

    for (int j = 0; j < lenOfRightSubArray; j++)
        rightSubArray[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < lenOfLeftSubArray && j < lenOfRightSubArray)
    {
        if (leftSubArray[i] <= rightSubArray[j])
        {
            arr[k] = leftSubArray[i];
            i++;
        }
        else
        {
            arr[k] = rightSubArray[j];
            j++;
        }
        k++;
    }

    while (i < lenOfLeftSubArray)
    {
        arr[k] = leftSubArray[i];
        i++;
        k++;
    }

    while (j < lenOfRightSubArray)
    {
        arr[k] = rightSubArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, arrSize - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
