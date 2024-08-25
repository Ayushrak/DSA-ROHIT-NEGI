#include<iostream>
using namespace std;

int main(){
    int *ptr = new int;
    *ptr =5;
    cout<<*ptr<<endl;
    float *ptr2 = new float;
    *ptr2 = 3.6;
    cout<<*ptr2<<endl;

    int n;
    cout<<"enter the size of array";
    cin>>n;

    int *p = new int[n];

    for(int i=0;i<n;i++){
        p[i] = i+1;
        cout<<p[i]<<endl;
    }

    delete ptr;
    delete ptr2;
    delete[] p;
}