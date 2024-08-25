#include<iostream>
using namespace std;

int main(){
    int arr[5] = {1,2,3,45};
    int * ptr = arr;
    cout<<arr<<endl;
    cout<<arr+0<<endl;
    cout<<&arr<<endl;
    cout<<ptr<<endl;

    cout<<arr+1<<endl;
    cout<<&arr[1]<<endl;

    cout<<arr[0]<<endl;
    cout<<*arr<<endl;
    cout<<*(arr+0)<<endl;
    cout<<*ptr<<endl;

    for(int i=0;i<5;i++){
        cout<<arr+i<<endl;
    }

    for(int i=0;i<5;i++){
        cout<<*arr+i<<endl;
    }

     for(int i=0;i<5;i++){
        cout<<ptr[i]<<endl;
    }

    for(int i=0;i<5;i++){
        cout<<*ptr<<endl;
        ptr++;
    }

    ptr = ptr+3;
    cout<<*ptr<<endl;
    
}
