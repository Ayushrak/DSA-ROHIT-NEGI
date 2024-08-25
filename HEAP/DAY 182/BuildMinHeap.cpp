#include<iostream>
using namespace std;

//Min heap;

void Heapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest])
        smallest = left;

    if(right < n && arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i)
    {
        swap(arr[i], arr[smallest]);
        Heapify(arr, n, smallest);
    }
}

void BuildHeap(int arr[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
        Heapify(arr, n, i);
}

void PrintHeap(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main(){
    int arr[] = {10,3,9,8,5,13,18,14,11,70};
    BuildHeap(arr, 10);
    PrintHeap(arr, 10);
}