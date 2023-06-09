#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapsort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, n, 0);
    }
}
void printArray(int arr[], int n)
{
    
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout<<endl;
}

int main()
{
    int arr[] = {60, 20, 40, 70, 30, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Before heapifying array is =    ";
    printArray(arr, n);

    heapsort(arr, n);

    cout << "After heapifing array is \n";
    printArray(arr, n);

    return 0;
}