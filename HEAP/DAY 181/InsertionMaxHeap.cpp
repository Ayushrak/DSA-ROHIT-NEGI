#include<iostream>
using namespace std;

class MaxHeap{
    int *arr;
    int size; //total elements in heap;
    int total_Size; // total size of array
public:
    MaxHeap(int n){
        arr = new int[n];
        size = 0;
        total_Size = n;
    }

    //insert into the heap
    void insert(int value){
        // if heap size is avaiable or not
        if(size==total_Size){
            cout<<"Heap Overflow\n";
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        //compare it with its parent
        while(index > 0 && arr[(index-1)/2]<arr[index])
        {
            swap(arr[index],arr[(index-1)/2]);
            index = (index-1)/2;
        };

        cout<<arr[index]<<" is inserted into the heap";
    }

    void heapify(int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && arr[left] > arr[largest])
        largest = left;

    if(right < size && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(largest);
    }
}

    void print()
    {
        for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";

        cout<<endl;
    }

    void Delete()
    {
        if(size==0)
        {
            cout<<"Heap Underflow\n";
            return;
        }

        cout<<arr[0]<<"deleted from the heap";
        arr[0] = arr[size-1];
        size--;

        if(size==0)
        return;

        heapify(0);
    }
};



int main(){
    MaxHeap H1(6);
    H1.insert(4);
    H1.insert(14);
    H1.insert(11);
    H1.print();
}