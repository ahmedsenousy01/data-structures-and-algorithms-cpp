#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int linearSearch(vector<int> v, int target) // O(n)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == target)
            return i;
    }

    return -1;
}

void bubbleSort(vector<int> &v) // O(n^2)
{
    for (int i = 0;; i++)
    {
        bool swapped = false;
        for (int j = 0; j < v.size() - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);

                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void selectionSort(vector<int> &v) // O(n^2)
{
    for (int i = 0; i < v.size(); i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[minIndex])
                minIndex = j;
        }
        swap(v[i], v[minIndex]);
    }
}

void insertionSort(vector<int> &v) // O(n^2)
{
    for (int i = 1; i < v.size(); i++)
    {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    vector<int> leftArr(n1), rightArr(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = arr[mid + 1 + i];

    // Merge the temp arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            ++i;
        }
        else
        {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Copy remaining elements of leftArr[], if any
    while (i < n1)
    {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    // Copy remaining elements of rightArr[], if any
    while (j < n2)
    {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// Function to perform merge sort
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to partition the array
int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[end]; // Pivot element
    int i = start - 1;    // Index of smaller element

    for (int j = start; j < end; ++j)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    // Place the pivot in its correct position
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

// Function to perform quick sort
void quickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        // Partition the array
        int pi = partition(arr, start, end);

        // Recursively sort elements before and after partition
        quickSort(arr, start, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}

int binarySearch(vector<int> v, int target)
{
    int left = 0, right = v.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (v[mid] == target)
            return mid;
        else if (v[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    vector<int> toBeSorted = {4, 5, 1, 6, 9, 7, 2};
    cout << linearSearch(toBeSorted, 11) << endl;
}